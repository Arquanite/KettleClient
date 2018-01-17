#include "employeestate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

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
    EmployeeDialog *dialog = new EmployeeDialog(m_parent);
    dialog->employee.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->employee);
    }
}

void EmployeeState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        Employee e(0, "", "", 0, 0, 0, 0);
        e.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(e);
    }
}
