#include "productdialog.h"
#include "ui_productdialog.h"

#include <QMessageBox>

ProductDialog::ProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductDialog)
{
    ui->setupUi(this);

    ui->textName->setText(product.name());

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

ProductDialog::~ProductDialog()
{
    delete ui;
}

bool ProductDialog::validate(){
    return true;
}
