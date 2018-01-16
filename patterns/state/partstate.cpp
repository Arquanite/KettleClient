#include "partstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

PartState::PartState(NetworkService *service, JSONModel *model) : AbstractState(service, model){

}

void PartState::getList(){
    QNetworkReply *reply = m_service->getParts();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toPart(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void PartState::add()
{
}
