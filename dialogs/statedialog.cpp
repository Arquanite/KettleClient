#include "statedialog.h"
#include "ui_statedialog.h"

#include <QMessageBox>
#include "pdebug.h"

StateDialog::StateDialog(QWidget *parent) : QDialog(parent), ui(new Ui::StateDialog){
    ui->setupUi(this);

    reload();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &StateDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        state.setName(ui->textName->text());
        state.setDepartmentId(ui->comboDepartment->currentIndex());
        this->accept();
    });
}

StateDialog::~StateDialog(){
    delete ui;
}

void StateDialog::reload(){
    ui->textName->setText(state.name());

    if(state.departmentId() > 0){
        ui->comboDepartment->setCurrentIndex(departmentIds.indexOf(state.departmentId()));
    }
    else ui->comboDepartment->setCurrentIndex(0);
}

void StateDialog::setComboDepartment(QList<QString> list){
    ui->comboDepartment->addItems(list);
    reload();
}

void StateDialog::setDepartmentIds(const QList<int> &value){
    departmentIds = value;
    reload();
}

bool StateDialog::validate(){
    if(ui->textName->text() == "" || ui->comboDepartment->currentIndex() < 0) return false;
    return true;
}
