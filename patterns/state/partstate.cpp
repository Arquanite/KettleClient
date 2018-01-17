#include "partstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

#include "partdialog.h"

PartState::PartState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}

void PartState::getList(){
    QNetworkReply *reply = m_service->getParts();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toPart(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void PartState::add(){
    PartDialog *dialog = new PartDialog(m_parent);
    QNetworkReply *reply = m_service->getProviders();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        QList<Provider> list = TypeConverter::toProvider(QJsonDocument::fromJson(reply->readAll()).array());
        QList<QString> providerNames;
        QList<int> providerIds;
        for(int i=0; i<list.size(); i++){
            providerNames.append(list.at(i).name());
            providerIds.append(list.at(i).id());
        }
        dialog->setComboProvider(providerNames);
        dialog->setProviderIds(providerIds);
    });
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->part);
    }
}

void PartState::update(){
    PartDialog *dialog = new PartDialog(m_parent);
    QNetworkReply *reply = m_service->getProviders();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        QList<Provider> list = TypeConverter::toProvider(QJsonDocument::fromJson(reply->readAll()).array());
        QList<QString> providerNames;
        QList<int> providerIds;
        for(int i=0; i<list.size(); i++){
            providerNames.append(list.at(i).name());
            providerIds.append(list.at(i).id());
        }
        dialog->setComboProvider(providerNames);
        dialog->setProviderIds(providerIds);
    });
    dialog->part.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->part);
    }
}

void PartState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        Part p(0, "", 0);
        p.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(p);
    }
}
