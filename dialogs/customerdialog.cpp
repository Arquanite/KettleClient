#include "customerdialog.h"
#include "ui_customerdialog.h"

#include <QMessageBox>

CustomerDialog::CustomerDialog(QWidget *parent) : QDialog(parent), ui(new Ui::CustomerDialog){
    ui->setupUi(this);

    reload();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &CustomerDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        customer.setAddress(ui->textAddress->text());
        customer.setName(ui->textName->text());
        customer.setNip(ui->textNip->text());
        this->accept();
    });
}

CustomerDialog::~CustomerDialog(){
    delete ui;
}

void CustomerDialog::reload(){
    ui->textAddress->setText(customer.address());
    ui->textName->setText(customer.name());
    ui->textNip->setText(customer.nip());
}

bool CustomerDialog::validate(){
    return true;
}
