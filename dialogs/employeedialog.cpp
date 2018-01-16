#include "employeedialog.h"
#include "ui_employeedialog.h"

#include <QMessageBox>

EmployeeDialog::EmployeeDialog(QWidget *parent) : QDialog(parent), ui(new Ui::EmployeeDialog)
{
    ui->setupUi(this);

    ui->textName->setText(employee.name());
    ui->textSurname->setText(employee.surname());
    ui->spinRate->setValue(employee.hourlyRate());
    ui->spinCount->setValue(employee.hourCount());
    ui->comboDepartment->setCurrentIndex(employee.departmentId());
    ui->comboSupervisor->setCurrentIndex(employee.supervisorId());

    connect(ui->buttonCancel, &QPushButton::clicked, this, &EmployeeDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        employee.setName(ui->textName->text());
        employee.setSurname(ui->textSurname->text());
        employee.setHourlyRate(ui->spinRate->value());
        employee.setHourCount(ui->spinCount->value());
        employee.setDepartmentId(ui->comboDepartment->currentIndex());
        employee.setSupervisorId(ui->comboSupervisor->currentIndex());
        this->accept();
    });
}

EmployeeDialog::~EmployeeDialog()
{
    delete ui;
}

bool EmployeeDialog::validate(){
    return true;
}
