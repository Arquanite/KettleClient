#include "partdialog.h"
#include "ui_partdialog.h"

#include <QMessageBox>

PartDialog::PartDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PartDialog){
    ui->setupUi(this);

    ui->textName->setText(part.name());
    ui->comboProvider->setCurrentIndex(part.providerId());

    connect(ui->buttonCancel, &QPushButton::clicked, this, &PartDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        part.setName(ui->textName->text());
        part.setProviderId(ui->comboProvider->currentIndex());
        this->accept();
    });
}

PartDialog::~PartDialog()
{
    delete ui;
}

bool PartDialog::validate(){
    return true;
}
