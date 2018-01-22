#include "productdialog.h"
#include "ui_productdialog.h"
#include "typeconverter.h"
#include "pdebug.h"
#include "ascendingstrategy.h"
#include "descendingstrategy.h"
#include <QInputDialog>
#include <QJsonDocument>
#include <QMessageBox>
#include <QMessageBox>
#include <QNetworkReply>
#include "networkservice.h"
#include "partdialog.h"
#include "stringvalidator.h"

ProductDialog::ProductDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ProductDialog){
    ui->setupUi(this);

    model = new JSONModel(QList<JSONAble*>(), new AscendingStrategy(), new DescendingStrategy, parent);
    ui->tableView->setModel(model); 

    connect(ui->buttonCancel, &QPushButton::clicked, this, &ProductDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "BŁĄÐ", "Formularz zawiera błędy");
            return;
        }
        product.setName(ui->textName->text());
        this->accept();
    });
    connect(ui->buttonAdd, &QPushButton::clicked, this, &ProductDialog::add);
    connect(ui->buttonRemove, &QPushButton::clicked, this, &ProductDialog::remove);
}

ProductDialog::~ProductDialog(){
    delete ui;
}

void ProductDialog::reload(){
    ui->textName->setText(product.name());
    model->setSourceData(TypeConverter::toJSONAble(product.parts()));
}

void ProductDialog::add(){
    NetworkService *service = new NetworkService();
    QNetworkReply *reply = service->getParts();
    reply->connect(reply, &QNetworkReply::finished, [&](){
        QList<Part> list = TypeConverter::toPart(QJsonDocument::fromJson(reply->readAll()).array());
        QList<QString> partNames;
        for(int i=0; i<list.size(); i++){
            partNames.append(list.at(i).name());
        }
        Part p = list.at(partNames.indexOf(QInputDialog::getItem(this, "Select Part", "Select one item from list", partNames, 0, false)));
        auto data = model->sourceData();
        data.append(new Part(p));
        model->setSourceData(data);
    });
}

void ProductDialog::remove(){
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

bool ProductDialog::validate(){
    if(!StringValidator::isNonEmpty(ui->textName->text())) return false;
    return true;
}
