#include "partdialog.h"
#include "ui_partdialog.h"

#include <QMessageBox>
#include <stringvalidator.h>

PartDialog::PartDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PartDialog){
    ui->setupUi(this);

    reload();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &PartDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is invalid!");
            return;
        }
        part.setName(ui->textName->text());
        part.setProviderId(ui->comboProvider->currentIndex());
        this->accept();
    });
}

PartDialog::~PartDialog(){
    delete ui;
}

void PartDialog::reload(){
    ui->textName->setText(part.name());
    if(part.providerId() > 0){
        ui->comboProvider->setCurrentIndex(providerIds.indexOf(part.providerId()));
    }
    else ui->comboProvider->setCurrentIndex(0);
}

void PartDialog::setComboProvider(QList<QString> list){
    ui->comboProvider->addItems(list);
    reload();
}

void PartDialog::setProviderIds(const QList<int> &value){
    providerIds = value;
    reload();
}

bool PartDialog::validate(){
    if(!StringValidator::isNonEmpty(ui->textName->text())) return false;
    if(ui->comboProvider->currentIndex() < 0) return false;
    return true;
}
