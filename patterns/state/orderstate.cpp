#include "orderstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

OrderState::OrderState(NetworkService *service, JSONModel *model) : AbstractState(service, model){

}


void OrderState::getList(){
    QNetworkReply *reply = m_service->getOrders();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toOrder(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void OrderState::add(){
}
