#include "departmentdialog.h"
#include "ui_departmentdialog.h"

#include <QMessageBox>
#include <stringvalidator.h>

DepartmentDialog::DepartmentDialog(QWidget *parent) : QDialog(parent), ui(new Ui::DepartmentDialog){
    ui->setupUi(this);

    reload();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &DepartmentDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is invalid");
            return;
        }
        department.setName(ui->textName->text());
        this->accept();
    });
}

DepartmentDialog::~DepartmentDialog(){
    delete ui;
}

void DepartmentDialog::reload(){
    ui->textName->setText(department.name());
}

bool DepartmentDialog::validate(){
    if(!StringValidator::isNonEmpty(ui->textName->text())) return false;
    return true;
}
