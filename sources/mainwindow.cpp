#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "waitingdialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->statusBar->showMessage("Ready");
    connect(ui->buttonRefresh, &QPushButton::clicked, [&](){
        WaitingDialog *dialog = new WaitingDialog();
        dialog->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
