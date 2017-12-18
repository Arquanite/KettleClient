#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aboutdialog.h"
#include "customerdialog.h"
#include "departmentdialog.h"
#include "employeedialog.h"
#include "logindialog.h"
#include "orderdialog.h"
#include "partdialog.h"
#include "productdialog.h"
#include "providerdialog.h"
#include "statedialog.h"
#include "waitingdialog.h"
#include "randomjsonfactory.h"
#include "jsonmodel.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->statusBar->showMessage("Ready");
    m_model = new JSONModel(QList<QJsonObject>(), this);
    m_controller = new ViewController(m_model, this);
    ui->tableMain->setModel(m_model);
    connect(ui->buttonRefresh, &QPushButton::clicked, [&](){
        WaitingDialog *dialog = new WaitingDialog(this);
        dialog->exec();
    });
    connect(ui->tableCommon, &QTableWidget::clicked, [&](QModelIndex index){
        m_controller->viewChanged(index.row());
        ui->tableMain->setModel(m_model);
    });
    connect(ui->buttonLogout, &QPushButton::clicked, [&](){
       LoginDialog *dialog = new LoginDialog(this);
       dialog->exec();
    });
    QList<QJsonObject> data;
    RandomJSONFactory f;
    for(int i=0; i<10; i++){
        data.append(f.randomProduct());
    }
    JSONModel *model = new JSONModel(data, this);
    ui->tableMain->setModel(model);
}

MainWindow::~MainWindow(){
    delete ui;
}
