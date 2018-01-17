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

#include <QMessageBox>
#include <QTimer>
#include "pdebug.h"
#include "filteringmodel.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->tableMain->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->statusBar->showMessage("Ready");
    m_emptyModel = new JSONModel(QList<JSONAble*>(), new AscendingStrategy(), new DescendingStrategy(), this);
    m_model = new JSONModel(QList<JSONAble*>(), new AscendingStrategy(), new DescendingStrategy(), this);    
    m_controller = new ViewController(m_model, this);

    m_primaryFilter = new FilteringModel(m_model, this);
    m_secondaryFilter = new FilteringModel(m_primaryFilter, this);

    logout();
    m_controller->viewChanged(0);
    QTimer::singleShot(100,[=](){ ui->tableMain->selectRow(0); ui->tableCommon->selectRow(0);});

    connect(ui->textFilterPrimary, &QLineEdit::textChanged, [=](){
        m_primaryFilter->filter(ui->comboFilterPrimary->currentIndex(), ui->textFilterPrimary->text());
        m_secondaryFilter->filter(ui->comboFilterSecondary->currentIndex(), ui->textFilterSecondary->text());
    });
    connect(ui->textFilterSecondary, &QLineEdit::textChanged, [=](){
        m_primaryFilter->filter(ui->comboFilterPrimary->currentIndex(), ui->textFilterPrimary->text());
        m_secondaryFilter->filter(ui->comboFilterSecondary->currentIndex(), ui->textFilterSecondary->text());
    });

    connect(ui->tableMain->selectionModel(), &QItemSelectionModel::currentChanged, [=](QModelIndex current, QModelIndex){ m_model->setSelectedIndex(current.row());});
    connect(m_model, &JSONModel::dataChanged, [=](){
        if(ui->tableMain->selectionModel()->selectedRows(0).size() != 0){
            m_model->setSelectedIndex(ui->tableMain->selectionModel()->selectedRows(0).first().row());
        }
        m_primaryFilter->reload();
        m_secondaryFilter->reload();
	reload();
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
                ui->buttonAdd->setDisabled(false);
                ui->buttonEdit->setDisabled(false);
                ui->buttonRefresh->setDisabled(false);
                ui->buttonRemove->setDisabled(false);
                ui->tableMain->setModel(m_secondaryFilter);
            }
        } else {
            if (QMessageBox::question(this, "Log out", "Do you want to log out?") == QMessageBox::No) return;
            Credentials::instance().setToken("");
            logout();
        }
    });
    connect(ui->tableCommon, &QTableWidget::clicked, [&](QModelIndex index){
        m_controller->viewChanged(index.row());
        QTimer::singleShot(100,[=](){ ui->tableMain->selectRow(0); });
        reload();
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

void MainWindow::logout() {
    ui->buttonLogout->setText("Log In");
    ui->labelLogged->setText("Not logged in");
    ui->labelUser->setText(Credentials::instance().token());
    ui->buttonAdd->setDisabled(true);
    ui->buttonEdit->setDisabled(true);
    ui->buttonRefresh->setDisabled(true);
    ui->buttonRemove->setDisabled(true);
    ui->tableMain->setModel(m_emptyModel);
}

void MainWindow::reload(){
    for(int i=ui->comboFilterPrimary->count(); i>0; i--){
        ui->comboFilterPrimary->removeItem(0);
        ui->comboFilterSecondary->removeItem(0);
    }
    if(m_model->rowCount() < 1) return;
    auto m = m_model->json(0)->toJSON().keys();
    if(m.size() == 0) return;
    for(QString s : m){
        ui->comboFilterPrimary->addItem(s);
        ui->comboFilterSecondary->addItem(s);
    }
}
