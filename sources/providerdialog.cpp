#include "providerdialog.h"
#include "ui_providerdialog.h"

ProviderDialog::ProviderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProviderDialog)
{
    ui->setupUi(this);
}

ProviderDialog::~ProviderDialog()
{
    delete ui;
}
