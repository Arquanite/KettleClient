#include "orderdialog.h"
#include "ui_orderdialog.h"

#include <QMessageBox>

OrderDialog::OrderDialog(QWidget *parent) : QDialog(parent), ui(new Ui::OrderDialog){
    ui->setupUi(this);

    reload();

    connect(ui->buttonCancel, &QPushButton::clicked, this, &OrderDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        if(!validate()){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        order.setCustomerId(ui->comboCustomer->currentIndex());
        //TODO CAŁARESZTA
        this->accept();
    });
}

OrderDialog::~OrderDialog(){
    delete ui;
}

void OrderDialog::reload(){
    ui->comboCustomer->setCurrentIndex(order.customerId());
}

bool OrderDialog::validate(){
    return true;
}
