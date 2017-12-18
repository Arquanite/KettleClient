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
    connect(ui->buttonRefresh, &QPushButton::clicked, [&](){
        WaitingDialog *dialog = new WaitingDialog(this);
        dialog->exec();
    });
    connect(ui->tableCommon, &QTableWidget::clicked, [&](QModelIndex index){
        QDialog *dialog = nullptr;
        switch(index.row()){
        case 0:
            dialog = new ProviderDialog(this);
            break;
        case 1:
            dialog = new CustomerDialog(this);
            break;
        case 2:
            dialog = new EmployeeDialog(this);
            break;
        case 3:
            dialog = new DepartmentDialog(this);
            break;
        case 4:
            dialog = new PartDialog(this);
            break;
        case 5:
            dialog = new ProductDialog(this);
            break;
        case 6:
            dialog = new StateDialog(this);
            break;
        case 7:
            dialog = new OrderDialog(this);
            break;
        }
        dialog->exec();
    });
    connect(ui->buttonLogout, &QPushButton::clicked, [&](){
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
