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
#include "ascendingstrategy.h"
#include "descendingstrategy.h"

#include <QTimer>
#include "pdebug.h"
#include "filteringmodel.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->tableMain->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->statusBar->showMessage("Ready");
    m_model = new JSONModel(QList<JSONAble*>(), new AscendingStrategy(), new DescendingStrategy(), this);    
    m_controller = new ViewController(m_model, this);

    FilteringModel *primaryFilter = new FilteringModel(m_model, this);
    FilteringModel *secondaryFilter = new FilteringModel(primaryFilter, this);

    ui->tableMain->setModel(secondaryFilter);

    ui->buttonLogout->setText("Log In");
    ui->labelLogged->setText("No logged in");
    ui->labelUser->setText(Credentials::instance().token());
    m_controller->viewChanged(0);
    QTimer::singleShot(100,[=](){ ui->tableMain->selectRow(0); ui->tableCommon->selectRow(0);});

    connect(ui->textFilterPrimary, &QLineEdit::textChanged, [=](){
        primaryFilter->filter(0, ui->textFilterPrimary->text());
        secondaryFilter->filter(0, ui->textFilterSecondary->text());
    });
    connect(ui->tableMain->selectionModel(), &QItemSelectionModel::currentChanged, [=](QModelIndex current, QModelIndex){ m_model->setSelectedIndex(current.row());});
    connect(m_model, &JSONModel::dataChanged, [=](){
        if(ui->tableMain->selectionModel()->selectedRows(0).size() != 0){
            m_model->setSelectedIndex(ui->tableMain->selectionModel()->selectedRows(0).first().row());
        }
        primaryFilter->reload();
        secondaryFilter->reload();
    });
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

    /// TEST AREA ///

    Order o = Order::builder(21, 37, "2018-01-17")
            .addProduct(Product::builder(32, "Czajnixx 3000")
                        .addPart(Part(1421, "Pralkogrzałka indukcyjna", 33))
                        .addPart(Part(4, "Pokrywka przeźroczysta", 6))
                        .addPart(Part(45, "Obudowa typu premium", 2343))
                        .build())
            .addProduct(Product::builder(12, "Czajnik jednorazowy")
                        .addPart(Part(7324, "Obudowa papierowa", 29))
                        .addPart(Part(645, "Grzałka z drutu", 44))
                        .build())
            .build();
}

MainWindow::~MainWindow(){
    delete ui;
}
