#include "providerstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

#include "providerdialog.h"

ProviderState::ProviderState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}

void ProviderState::getList(){
    QNetworkReply *reply = m_service->getProviders();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toProvider(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void ProviderState::add(){
    ProviderDialog *dialog = new ProviderDialog(m_parent);
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->provider);
    }
}

void ProviderState::update(){

}
