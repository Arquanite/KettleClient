#include "departmentdialog.h"
#include "ui_departmentdialog.h"

DepartmentDialog::DepartmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepartmentDialog)
{
    ui->setupUi(this);
}

DepartmentDialog::~DepartmentDialog()
{
    delete ui;
}
