#include "customerstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

CustomerState::CustomerState(NetworkService *service, JSONModel *model) : AbstractState(service, model){

}

void CustomerState::getList(){
    QNetworkReply *reply = m_service->getCustomers();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toCustomer(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void CustomerState::add(){

}
