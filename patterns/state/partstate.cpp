#include "partstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

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
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->part);
    }
}

void PartState::update(){
    PartDialog *dialog = new PartDialog(m_parent);
    dialog->part.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->part);
    }
}
