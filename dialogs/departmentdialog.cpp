#include "departmentdialog.h"
#include "ui_departmentdialog.h"

#include <QMessageBox>

DepartmentDialog::DepartmentDialog(QWidget *parent) : QDialog(parent), ui(new Ui::DepartmentDialog){
    ui->setupUi(this);

    reload();

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

DepartmentDialog::~DepartmentDialog(){
    delete ui;
}

void DepartmentDialog::reload(){
    ui->textName->setText(department.name());
}

bool DepartmentDialog::validate(){
    return true;
}
