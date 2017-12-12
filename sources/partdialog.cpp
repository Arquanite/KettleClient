#include "partdialog.h"
#include "ui_partdialog.h"

PartDialog::PartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PartDialog)
{
    ui->setupUi(this);
}

PartDialog::~PartDialog()
{
    delete ui;
}
