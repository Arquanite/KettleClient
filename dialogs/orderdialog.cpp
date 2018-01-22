#include "orderdialog.h"
#include "ui_orderdialog.h"

#include <QJsonDocument>
#include <QMessageBox>
#include <QNetworkReply>
#include <ascendingstrategy.h>
#include <descendingstrategy.h>
#include <networkservice.h>
#include <typeconverter.h>
#include <QInputDialog>

OrderDialog::OrderDialog(QWidget *parent) : QDialog(parent), ui(new Ui::OrderDialog){
    ui->setupUi(this);

    model = new JSONModel(QList<JSONAble*>(), new AscendingStrategy, new DescendingStrategy, parent);
    ui->tableView->setModel(model);

    reload();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &OrderDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        order.setCustomerId(ui->comboCustomer->currentIndex());
        order.setDate(ui->dateEdit->text());
        this->accept();
    });

    connect(ui->buttonAdd, &QPushButton::clicked, this, &OrderDialog::add);
    connect(ui->buttonRemove, &QPushButton::clicked, this, &OrderDialog::remove);
}

OrderDialog::~OrderDialog(){
    delete ui;
}

void OrderDialog::reload(){
    ui->comboCustomer->setCurrentIndex(order.customerId());
    model->setSourceData(TypeConverter::toJSONAble(order.products()));
}

void OrderDialog::add(){
    NetworkService *service = new NetworkService();
    QNetworkReply *reply = service->getProducts();
    reply->connect(reply, &QNetworkReply::finished, [&](){
        QList<Product> list = TypeConverter::toProduct(QJsonDocument::fromJson(reply->readAll()).array());
        QList<QString> productNames;
        for(int i=0; i<list.size(); i++){
            productNames.append(list.at(i).name());
        }
        Product p = list.at(productNames.indexOf(QInputDialog::getItem(this, "Select Part", "Select one item from list", productNames, 0, false)));
        auto data = model->sourceData();
        data.append(new Product(p));
        model->setSourceData(data);
    });
}

void OrderDialog::remove(){
    if(ui->tableView->selectionModel()->selectedRows().size() == 0){
        QMessageBox::warning(this, "Warning", "You must select item you want to remove!");
        return;
    }
    int selection = ui->tableView->selectionModel()->selectedRows().first().row();
    if(QMessageBox::question(this, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        auto data = model->sourceData();
        data.removeAt(selection);
        model->setSourceData(data);
    }
}

bool OrderDialog::validate(){
    return true;
}
