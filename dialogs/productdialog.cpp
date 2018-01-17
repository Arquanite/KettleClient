#include "productdialog.h"
#include "ui_productdialog.h"
#include "typeconverter.h"
#include "pdebug.h"

#include <QMessageBox>

ProductDialog::ProductDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ProductDialog){
    ui->setupUi(this);

    model = new JSONModel(QList<JSONAble*>(), this);
    ui->tableView->setModel(model);

    connect(ui->buttonCancel, &QPushButton::clicked, this, &ProductDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        product.setName(ui->textName->text());
        //TODO CAŁARESZTA
        this->accept();
    });
}

ProductDialog::~ProductDialog(){
    delete ui;
}

void ProductDialog::reload(){
    ui->textName->setText(product.name());
    model->setSourceData(TypeConverter::toJSONAble(product.parts()));
}

bool ProductDialog::validate(){
    return true;
}
