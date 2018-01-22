#include "customerdialog.h"
#include "ui_customerdialog.h"

#include <QMessageBox>
#include <stringvalidator.h>

CustomerDialog::CustomerDialog(QWidget *parent) : QDialog(parent), ui(new Ui::CustomerDialog){
    ui->setupUi(this);

    reload();

    re.setPattern("^[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]$");

    connect(ui->buttonCancel, &QPushButton::clicked, this, &CustomerDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is invalid");
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
    if(!StringValidator::isNonEmpty(ui->textAddress->text())) return false;
    if(!StringValidator::isNonEmpty(ui->textName->text())) return false;
    if(!StringValidator::isNonEmpty(ui->textNip->text())) return false;
    match = re.match(ui->textNip->text());
    if(!match.hasMatch()) return false;
    return true;
}
