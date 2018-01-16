#include "departmentdialog.h"
#include "ui_departmentdialog.h"

#include <QMessageBox>

DepartmentDialog::DepartmentDialog(QWidget *parent) : QDialog(parent), ui(new Ui::DepartmentDialog){
    ui->setupUi(this);

    ui->textName->setText(department.name());

    connect(ui->buttonCancel, &QPushButton::clicked, this, &DepartmentDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        department.setName(ui->textName->text());
        this->accept();
    });
}

DepartmentDialog::~DepartmentDialog()
{
    delete ui;
}

bool DepartmentDialog::validate(){
    return true;
}
