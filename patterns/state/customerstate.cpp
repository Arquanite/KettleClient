#include "customerstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

#include "customerdialog.h"

#include <QDebug>

CustomerState::CustomerState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}

void CustomerState::getList(){
    QNetworkReply *reply = m_service->getCustomers();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toCustomer(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void CustomerState::add(){
    CustomerDialog *dialog = new CustomerDialog(m_parent);
    if(dialog->exec() == QDialog::Accepted){
        qDebug()<<dialog->customer.name();
    }
}
