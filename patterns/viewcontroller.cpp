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
#include <QJsonDocument>
#include <QtNetwork/QNetworkReply>

#include "pdebug.h"

ViewController::ViewController(JSONModel *model, QObject *parent) : QObject(parent), m_model(model){

}

void ViewController::viewChanged(int id){
    QList<QJsonObject> data;
    std::function<QJsonObject(void)> generate;
    RandomJSONFactory JSONFactory;
    m_current = id;
    QNetworkReply *reply;
    switch (id) {
    case TypeProvider:
        reply = m_service.getProviders();
        connect(reply, &QNetworkReply::finished, [=](){ m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toProvider(QJsonDocument::fromJson(reply->readAll()).array()))); });
        break;
    case TypeCustomer:
        reply = m_service.getCustomers();
        connect(reply, &QNetworkReply::finished, [=](){ m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toCustomer(QJsonDocument::fromJson(reply->readAll()).array()))); });
        break;
    case TypeEmployee:
        reply = m_service.getEmployees();
        connect(reply, &QNetworkReply::finished, [=](){ m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toEmployee(QJsonDocument::fromJson(reply->readAll()).array()))); });
        break;
    case TypeDepartment:
        reply = m_service.getDepartments();
        connect(reply, &QNetworkReply::finished, [=](){ m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toDepartment(QJsonDocument::fromJson(reply->readAll()).array()))); });
        break;
    case TypePart:
        reply = m_service.getParts();
        connect(reply, &QNetworkReply::finished, [=](){ m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toPart(QJsonDocument::fromJson(reply->readAll()).array()))); });
        break;
    case TypeProduct:
        reply = m_service.getProducts();
        connect(reply, &QNetworkReply::finished, [=](){ m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toProduct(QJsonDocument::fromJson(reply->readAll()).array()))); });
        break;
    case TypeState:
        reply = m_service.getStates();
        connect(reply, &QNetworkReply::finished, [=](){ m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toState(QJsonDocument::fromJson(reply->readAll()).array()))); });
        break;
    case TypeOrder:
        reply = m_service.getOrders();
        connect(reply, &QNetworkReply::finished, [=](){ m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toOrder(QJsonDocument::fromJson(reply->readAll()).array()))); });
        break;
    }
    qDebug()<<"id"<<id;
//    for(int i=0; i<25; i++){
//        data.append(generate());
//    }
//    WaitingDialog *dialog = new WaitingDialog((QWidget*)parent());
//    dialog->exec();
//    m_model->setSourceData(data);
}

void ViewController::add(){
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
