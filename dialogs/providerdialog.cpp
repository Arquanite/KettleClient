#include "providerdialog.h"
#include "ui_providerdialog.h"

#include <QMessageBox>
#include <stringvalidator.h>

ProviderDialog::ProviderDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ProviderDialog){
    ui->setupUi(this);

    reload();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &ProviderDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is invalid!");
            return;
        }
        provider.setName(ui->textName->text());
        provider.setAddress(ui->textAddress->text());
        this->accept();
    });
}

ProviderDialog::~ProviderDialog(){
    delete ui;
}

void ProviderDialog::reload(){
    ui->textName->setText(provider.name());
    ui->textAddress->setText(provider.address());
}

bool ProviderDialog::validate(){
    if(!StringValidator::isNonEmpty(ui->textName->text())) return false;
    if(!StringValidator::isNonEmpty(ui->textAddress->text())) return false;

    return true;
}
