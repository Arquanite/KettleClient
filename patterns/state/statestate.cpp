#include "statestate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

#include "statedialog.h"
#include "pdebug.h"

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
    QNetworkReply *reply = m_service->getDepartments();
    reply->connect(reply, &QNetworkReply::finished, [=](){
       QList<Department> list = TypeConverter::toDepartment(QJsonDocument::fromJson(reply->readAll()).array());
       QList<QString> departmentNames;
       QList<int> departmentIds;
       for(int i=0; i<list.size(); i++){
           departmentNames.append(list.at(i).name());
           departmentIds.append(list.at(i).id());
       }
       dialog->setComboDepartment(departmentNames);
       dialog->setDepartmentIds(departmentIds);
    });

    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->state);
    }
}

void StateState::update(){
    StateDialog *dialog = new StateDialog(m_parent);
    QNetworkReply *reply = m_service->getDepartments();
    reply->connect(reply, &QNetworkReply::finished, [=](){
       QList<Department> list = TypeConverter::toDepartment(QJsonDocument::fromJson(reply->readAll()).array());
       QList<QString> departmentNames;
       QList<int> departmentIds;
       for(int i=0; i<list.size(); i++){
           departmentNames.append(list.at(i).name());
           departmentIds.append(list.at(i).id());

       }
       dialog->setComboDepartment(departmentNames);
       dialog->setDepartmentIds(departmentIds);
    });
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
