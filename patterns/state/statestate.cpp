#include "statestate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

#include "statedialog.h"

StateState::StateState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}

void StateState::getList(){
    QNetworkReply *reply = m_service->getStates();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toState(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void StateState::add(){
    StateDialog *dialog = new StateDialog(m_parent);
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->state);
    }
}

void StateState::update(){
    StateDialog *dialog = new StateDialog(m_parent);
    dialog->state.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->state);
    }
}

void StateState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        State s(0, "", 0);
        s.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(s);
    }
}
