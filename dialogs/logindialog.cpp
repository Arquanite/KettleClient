#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &LoginDialog::reject);
    connect(ui->buttonOk, &QPushButton::clicked, [&](){
        QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
    });
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
