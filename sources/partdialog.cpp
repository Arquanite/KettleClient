#include "partdialog.h"
#include "ui_partdialog.h"

#include <QMessageBox>

PartDialog::PartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PartDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &PartDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
    });
}

PartDialog::~PartDialog()
{
    delete ui;
}
