#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->textBrowser->viewport()->setAutoFillBackground(false);
    ui->textBrowser->setFrameStyle(QFrame::NoFrame);
    connect(ui->buttonOK, &QPushButton::clicked, this, &AboutDialog::accept);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
