#include "employeedialog.h"
#include "ui_employeedialog.h"

#include <QMessageBox>
#include <stringvalidator.h>

EmployeeDialog::EmployeeDialog(QWidget *parent) : QDialog(parent), ui(new Ui::EmployeeDialog){
    ui->setupUi(this);

    reload();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &EmployeeDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is invalid!");
            return;
        }
        employee.setName(ui->textName->text());
        employee.setSurname(ui->textSurname->text());
        employee.setHourlyRate(ui->spinRate->value());
        employee.setHourCount(ui->spinCount->value());
        employee.setDepartmentId(departmentIds.at(ui->comboDepartment->currentIndex()));
        this->accept();
    });
}

EmployeeDialog::~EmployeeDialog(){
    delete ui;
}

void EmployeeDialog::reload(){
    ui->textName->setText(employee.name());
    ui->textSurname->setText(employee.surname());
    ui->spinRate->setValue(employee.hourlyRate());
    ui->spinCount->setValue(employee.hourCount());

    if(employee.departmentId() > 0) ui->comboDepartment->setCurrentIndex(departmentIds.indexOf(employee.departmentId()));
    else ui->comboDepartment->setCurrentIndex(0);
}

void EmployeeDialog::setComboDepartament(QList<QString> list){
    ui->comboDepartment->addItems(list);
    reload();
}

void EmployeeDialog::setDepartmentIds(const QList<int> &value){
    departmentIds = value;
    reload();
}

bool EmployeeDialog::validate(){
    if(ui->spinRate->value() == 0 || ui->spinCount->value() == 0 ||
            ui->comboDepartment->currentIndex() < 0) return false;
    if(!StringValidator::isNonEmpty(ui->textName->text())) return false;
    if(!StringValidator::isNonEmpty(ui->textSurname->text())) return false;
    return true;
}
