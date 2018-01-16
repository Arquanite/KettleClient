#include "providerdialog.h"
#include "ui_providerdialog.h"

#include <QMessageBox>

ProviderDialog::ProviderDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ProviderDialog){
    ui->setupUi(this);

    ui->textName->setText(provider.name());
    ui->textAddress->setText(provider.address());

    connect(ui->buttonCancel, &QPushButton::clicked, this, &ProviderDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        provider.setName(ui->textName->text());
        provider.setAddress(ui->textAddress->text());
        this->accept();
    });
}

ProviderDialog::~ProviderDialog()
{
    delete ui;
}

bool ProviderDialog::validate(){
    return true;
}
