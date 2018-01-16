#include "employeestate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

#include "employeedialog.h"

EmployeeState::EmployeeState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}


void EmployeeState::getList(){
    QNetworkReply *reply = m_service->getEmployees();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toEmployee(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void EmployeeState::add(){
    EmployeeDialog *dialog = new EmployeeDialog(m_parent);
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->employee);
    }
}

void EmployeeState::update(){

}
