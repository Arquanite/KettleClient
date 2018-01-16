#include "productstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

ProductState::ProductState(NetworkService *service, JSONModel *model) : AbstractState(service, model){

}


void ProductState::getList(){
    QNetworkReply *reply = m_service->getProducts();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toProduct(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void ProductState::add(){

}
