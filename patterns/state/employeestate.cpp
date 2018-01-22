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
    QNetworkReply *reply = m_service->getDepartments();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        QList<Department> dlist = TypeConverter::toDepartment(QJsonDocument::fromJson(reply->readAll()).array());
        QList<QString> departmentNames;
        QList<int> departmentIds;
        for(int i=0; i<dlist.size(); i++){
            departmentNames.append(dlist.at(i).name());
            departmentIds.append(dlist.at(i).id());
        }
        dialog->setComboDepartament(departmentNames);
        dialog->setDepartmentIds(departmentIds);
    });
    reply = m_service->getEmployees();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        QList<Employee> elist = TypeConverter::toEmployee(QJsonDocument::fromJson(reply->readAll()).array());
        QList<QString> supervisorNames;
        QList<int> supervisorIds;
        for(int i=0; i<elist.size(); i++){
            supervisorNames.append(elist.at(i).surname() + " " + elist.at(i).name());
            supervisorIds.append(elist.at(i).id());
        }
    });
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->employee);
    }
}

void EmployeeState::update(){
    EmployeeDialog *dialog = new EmployeeDialog(m_parent);
    QNetworkReply *reply = m_service->getDepartments();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        QList<Department> dlist = TypeConverter::toDepartment(QJsonDocument::fromJson(reply->readAll()).array());
        QList<QString> departmentNames;
        QList<int> departmentIds;
        for(int i=0; i<dlist.size(); i++){
            departmentNames.append(dlist.at(i).name());
            departmentIds.append(dlist.at(i).id());
        }
        dialog->setComboDepartament(departmentNames);
        dialog->setDepartmentIds(departmentIds);
    });
    reply = m_service->getEmployees();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        QList<Employee> elist = TypeConverter::toEmployee(QJsonDocument::fromJson(reply->readAll()).array());
        QList<QString> supervisorNames;
        QList<int> supervisorIds;
        for(int i=0; i<elist.size(); i++){
            supervisorNames.append(elist.at(i).surname() + " " + elist.at(i).name());
            supervisorIds.append(elist.at(i).id());
        }
    });
    dialog->employee.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->employee);
    }
}

void EmployeeState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        Employee e(0, "", "", 0, 0, 0);
        e.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(e);
    }
}
