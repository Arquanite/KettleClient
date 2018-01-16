#include "viewcontroller.h"
#include <QJsonObject>
#include <functional>
#include "randomjsonfactory.h"

#include "customerdialog.h"
#include "departmentdialog.h"
#include "employeedialog.h"
#include "orderdialog.h"
#include "partdialog.h"
#include "productdialog.h"
#include "providerdialog.h"
#include "statedialog.h"
#include "waitingdialog.h"
#include "typeconverter.h"

#include <QDebug>
#include <QMessageBox>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>

ViewController::ViewController(JSONModel *model, QWidget *parent) : QObject(parent), m_model(model){
    m_states.append(new CustomerState(&m_service, m_model, parent));
    m_states.append(new DepartmentState(&m_service, m_model, parent));
    m_states.append(new EmployeeState(&m_service, m_model, parent));
    m_states.append(new OrderState(&m_service, m_model, parent));
    m_states.append(new PartState(&m_service, m_model, parent));
    m_states.append(new ProductState(&m_service, m_model, parent));
    m_states.append(new ProviderState(&m_service, m_model, parent));
    m_states.append(new StateState(&m_service, m_model, parent));
}

void ViewController::viewChanged(int id){
    QList<QJsonObject> data;
    std::function<QJsonObject(void)> generate;
    RandomJSONFactory JSONFactory;
    m_current = id;
    m_currentState = m_states.at(id);
    m_currentState->getList();
}

void ViewController::add(){
    m_currentState->add();
}

void ViewController::edit(){
    QDialog *dialog = nullptr;
    switch(m_current){
    case 0:
        dialog = new ProviderDialog((QWidget*)parent());
        break;
    case 1:
        dialog = new CustomerDialog((QWidget*)parent());
        break;
    case 2:
        dialog = new EmployeeDialog((QWidget*)parent());
        break;
    case 3:
        dialog = new DepartmentDialog((QWidget*)parent());
        break;
    case 4:
        dialog = new PartDialog((QWidget*)parent());
        break;
    case 5:
        dialog = new ProductDialog((QWidget*)parent());
        break;
    case 6:
        dialog = new StateDialog((QWidget*)parent());
        break;
    case 7:
        dialog = new OrderDialog((QWidget*)parent());
        break;
    default:
        return;
    }
    dialog->exec();
}

void ViewController::remove(){
    QMessageBox::question((QWidget*)parent(), "Are you sure?", "Do you really want to remove selected row?");
}
