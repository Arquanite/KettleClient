#include "statestate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

StateState::StateState(NetworkService *service, JSONModel *model) : AbstractState(service, model){

}

void StateState::getList(){
    QNetworkReply *reply = m_service->getStates();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toState(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void StateState::add(){

}
