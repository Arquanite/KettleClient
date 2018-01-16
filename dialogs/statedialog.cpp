#include "statedialog.h"
#include "ui_statedialog.h"

#include <QMessageBox>

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
    ui->comboDepartment->setCurrentIndex(state.departmentId());
}

bool StateDialog::validate(){
    return true;
}
