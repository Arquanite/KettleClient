#include "productdialog.h"
#include "ui_productdialog.h"

#include <QMessageBox>

ProductDialog::ProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &ProductDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
    });
}

ProductDialog::~ProductDialog()
{
    delete ui;
}
