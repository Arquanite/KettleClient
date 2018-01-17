#include "providerstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

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
    ProviderDialog *dialog = new ProviderDialog(m_parent);
    dialog->provider.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->provider);
    }
}

void ProviderState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        Customer c(0, "", "", "");
        c.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(c);
    }
}
