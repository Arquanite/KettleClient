#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "waitingdialog.h"
#include "logindialog.h"
#include "aboutdialog.h"

#include "randomjsonfactory.h"
#include "jsonmodel.h"

#include "product.h"
#include "typeconverter.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->tableMain->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->statusBar->showMessage("Ready");
    m_model = new JSONModel(QList<QJsonObject>(), this);
    m_controller = new ViewController(m_model, this);
    ui->tableMain->setModel(m_model);
    connect(ui->buttonRefresh, &QPushButton::clicked, [&](){
        WaitingDialog *dialog = new WaitingDialog(this);
        dialog->exec();
    });
    connect(ui->buttonAdd, &QPushButton::clicked, m_controller, &ViewController::add);
    connect(ui->buttonEdit, &QPushButton::clicked, m_controller, &ViewController::edit);
    connect(ui->buttonRemove, &QPushButton::clicked, m_controller, &ViewController::remove);
    connect(ui->tableCommon, &QTableWidget::clicked, [&](QModelIndex index){
        m_controller->viewChanged(index.row());
        ui->tableMain->setModel(m_model);
    });
    connect(ui->actionLogin, &QAction::triggered, [&](){
       LoginDialog *dialog = new LoginDialog(this);
       dialog->exec();
    });

    connect(ui->actionAbout, &QAction::triggered, [&](){
        AboutDialog *dialog = new AboutDialog(this);
        dialog->exec();
    });

    QList<QJsonObject> data;
    RandomJSONFactory f;
    for(int i=0; i<10; i++){
        data.append(f.randomCustomer());
    }
    JSONModel *model = new JSONModel(data, this);
    ui->tableMain->setModel(model);

    QList<JSONAble*> lol;
    QList<Part> xd;
//    lol = xd;
    //toJSONAble(d);
//    toJSONAble(1);
    TypeConverter::toJSONAble(xd);
}

MainWindow::~MainWindow(){
    delete ui;
}
