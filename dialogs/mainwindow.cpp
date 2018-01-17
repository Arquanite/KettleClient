#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "waitingdialog.h"
#include "logindialog.h"
#include "aboutdialog.h"

#include "randomjsonfactory.h"
#include "jsonmodel.h"

#include "credentials.h"
#include "product.h"
#include "order.h"
#include "typeconverter.h"

#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->tableMain->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->statusBar->showMessage("Ready");
    m_model = new JSONModel(QList<JSONAble*>(), this);
    m_controller = new ViewController(m_model, this);
    ui->tableMain->setModel(m_model);
    ui->buttonLogout->setText("Log In");
    ui->labelLogged->setText("No logged in");
    ui->labelUser->setText(Credentials::instance().token());
    m_controller->viewChanged(0);
    QTimer::singleShot(100,[=](){ ui->tableMain->selectRow(0); ui->tableCommon->selectRow(0);});

    connect(ui->tableMain->selectionModel(), &QItemSelectionModel::currentChanged, [=](QModelIndex current, QModelIndex){ m_model->setSelectedIndex(current.row());});
    connect(ui->buttonRefresh, &QPushButton::clicked, m_controller, &ViewController::refresh);
    connect(ui->buttonAdd, &QPushButton::clicked, m_controller, &ViewController::add);
    connect(ui->buttonEdit, &QPushButton::clicked, m_controller, &ViewController::edit);
    connect(ui->buttonRemove, &QPushButton::clicked, m_controller, &ViewController::remove);
    connect(ui->buttonLogout, &QPushButton::clicked, [&](){
        if(Credentials::instance().token().size() == 0){
            LoginDialog *dialog = new LoginDialog(this);
            if(dialog->exec() == QDialog::Accepted){
                ui->buttonLogout->setText("Log Out");
                ui->labelLogged->setText("Logged as:");
                ui->labelUser->setText(Credentials::instance().token());
            }
        } else {
            Credentials::instance().setToken("");
            ui->buttonLogout->setText("Log In");
            ui->labelLogged->setText("No logged in");
            ui->labelUser->setText(Credentials::instance().token());
        }
    });
    connect(ui->tableCommon, &QTableWidget::clicked, [&](QModelIndex index){
        m_controller->viewChanged(index.row());
        QTimer::singleShot(100,[=](){ ui->tableMain->selectRow(0); });
    });
    connect(ui->actionLogin, &QAction::triggered, [&](){
       LoginDialog *dialog = new LoginDialog(this);
       dialog->exec();
    });

    connect(ui->actionAbout, &QAction::triggered, [&](){
        AboutDialog *dialog = new AboutDialog(this);
        dialog->exec();
    });

//    QList<QJsonObject> data;
//    RandomJSONFactory f;
//    for(int i=0; i<10; i++){
//        data.append(f.randomCustomer());
//    }
//    JSONModel *model = new JSONModel(data, this);
//    ui->tableMain->setModel(model);

    /// TEST AREA ///

    QList<JSONAble*> lol;
    QList<Part> xd;
//    lol = xd;
    //toJSONAble(d);
//    toJSONAble(1);
    TypeConverter::toJSONAble(xd);

    Product p = Product::builder(12, "lol").addPart(Part(1,"2",3)).addPart(Part(1,"2",3)).build();

    Order o = Order::builder(21, 37, "lolxd")
            .addProduct(Product::builder(32, "dsd")
                        .addPart(Part(1,"2",3))
                        .addPart(Part(4,"5",6)).build())
            .addProduct(Product::builder(12, "lol")
                        .addPart(Part(7,"8",9))
                        .addPart(Part(6,"6",6)).build())
            .build();

    RandomJSONFactory fac;
    for(int i=0; i<32; i++){
//        qDebug()<<fac.randomState();
    };
}

MainWindow::~MainWindow(){
    delete ui;
}
