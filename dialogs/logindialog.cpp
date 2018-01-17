#include "logindialog.h"
#include "ui_logindialog.h"
#include "networkservice.h"
#include "credentials.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkReply>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &LoginDialog::reject);
    connect(ui->buttonOk, &QPushButton::clicked, [&](){
        if(ui->textLogin->text().size() == 0 && ui->textPassword->text().size() == 0){
            QMessageBox::critical(this, "ERROR", "Form is missing one or more fields");
            return;
        }
        QString name = ui->textLogin->text();
        QString pass = ui->textPassword->text();
        NetworkService *service = new NetworkService(this);
        QNetworkReply *reply = service->login(name, pass);
        reply->connect(reply, &QNetworkReply::finished, [=](){
            QJsonArray array = QJsonDocument::fromJson(reply->readAll()).array();
            if(array.size() == 0) {
                QMessageBox::critical(this, "ERROR", "Wrong username or password");
                return;
            }
            Credentials::instance().setToken(name);
            this->accept();
        });
    });
}

LoginDialog::~LoginDialog(){
    delete ui;
}
