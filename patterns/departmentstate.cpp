#include "departmentstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

DepartmentState::DepartmentState(NetworkService *service, JSONModel *model) : AbstractState(service, model){

}


void DepartmentState::getList(){
    QNetworkReply *reply = m_service->getDepartments();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toDepartment(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void DepartmentState::add(){
}
