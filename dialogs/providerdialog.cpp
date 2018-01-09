#include "providerdialog.h"
#include "ui_providerdialog.h"

#include <QMessageBox>

ProviderDialog::ProviderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProviderDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &ProviderDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
    });
}

ProviderDialog::~ProviderDialog()
{
    delete ui;
}
