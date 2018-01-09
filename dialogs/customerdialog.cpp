#include "customerdialog.h"
#include "ui_customerdialog.h"

#include <QMessageBox>

CustomerDialog::CustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &CustomerDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
    });
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}
