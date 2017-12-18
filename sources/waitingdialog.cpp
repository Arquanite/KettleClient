#include "waitingdialog.h"
#include "ui_waitingdialog.h"

WaitingDialog::WaitingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitingDialog)
{
    ui->setupUi(this);
    ui->spinner->setRoundness(0);
    ui->spinner->setMinimumTrailOpacity(0);
    ui->spinner->setTrailFadePercentage(70.0);
    ui->spinner->setNumberOfLines(15);
    ui->spinner->setLineLength(8);
    ui->spinner->setLineWidth(8);
    ui->spinner->setInnerRadius(30);
    ui->spinner->setRevolutionsPerSecond(2);
    ui->spinner->setColor(QColor(0, 0, 0));
    ui->spinner->start();
    QTimer::singleShot(3000, [&](){
       accept();
    });
}

WaitingDialog::~WaitingDialog()
{
    delete ui;
}
