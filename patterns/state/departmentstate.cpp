#include "departmentstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

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
    DepartmentDialog *dialog = new DepartmentDialog(m_parent);
    dialog->department.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->department);
    }
}

void DepartmentState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        Department d(0, "");
        d.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(d);
    }
}
