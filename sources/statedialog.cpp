#include "statedialog.h"
#include "ui_statedialog.h"

#include <QMessageBox>

StateDialog::StateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StateDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &StateDialog::reject);
    connect(ui->buttonSave, &QPushButton::clicked, [&](){
        QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
    });
}

StateDialog::~StateDialog()
{
    delete ui;
}
