#include "statedialog.h"
#include "ui_statedialog.h"

StateDialog::StateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StateDialog)
{
    ui->setupUi(this);
}

StateDialog::~StateDialog()
{
    delete ui;
}
