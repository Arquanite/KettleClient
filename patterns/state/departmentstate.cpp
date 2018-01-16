#include "departmentstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

#include "departmentdialog.h"

DepartmentState::DepartmentState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}


void DepartmentState::getList(){
    QNetworkReply *reply = m_service->getDepartments();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toDepartment(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void DepartmentState::add(){
    DepartmentDialog *dialog = new DepartmentDialog(m_parent);
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->department);
    }
}

void DepartmentState::update(){

}
