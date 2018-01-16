#include "employeestate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

EmployeeState::EmployeeState(NetworkService *service, JSONModel *model) : AbstractState(service, model){

}


void EmployeeState::getList(){
    QNetworkReply *reply = m_service->getEmployees();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toEmployee(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void EmployeeState::add(){
}
