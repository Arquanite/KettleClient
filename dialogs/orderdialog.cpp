#include "orderdialog.h"
#include "ui_orderdialog.h"

#include <QMessageBox>

OrderDialog::OrderDialog(QWidget *parent) : QDialog(parent), ui(new Ui::OrderDialog){
    ui->setupUi(this);

    ui->comboCustomer->setCurrentIndex(order.customerId());

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

OrderDialog::~OrderDialog()
{
    delete ui;
}

bool OrderDialog::validate(){
    return true;
}
