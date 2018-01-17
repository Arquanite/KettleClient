#include "viewcontroller.h"
#include <QJsonObject>
#include <functional>

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
    viewChanged(0);
}

void ViewController::viewChanged(int id){
    m_currentState = m_states.at(id);
    refresh();
}

void ViewController::add(){
    m_currentState->add();
    refresh();
}

void ViewController::edit(){
    m_currentState->update();
    refresh();
}

void ViewController::remove(){
    QMessageBox::question((QWidget*)parent(), "Are you sure?", "Do you really want to remove selected row?");
    refresh();
}

void ViewController::refresh(){
    m_currentState->getList();
}
