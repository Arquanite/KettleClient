#include "departmentdialog.h"
#include "ui_departmentdialog.h"

#include <QMessageBox>

DepartmentDialog::DepartmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepartmentDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &DepartmentDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
    });
}

DepartmentDialog::~DepartmentDialog()
{
    delete ui;
}
