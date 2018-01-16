#include "providerstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

ProviderState::ProviderState(NetworkService *service, JSONModel *model) : AbstractState(service, model){

}


void ProviderState::getList(){
    QNetworkReply *reply = m_service->getProviders();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toProvider(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void ProviderState::add(){

}
