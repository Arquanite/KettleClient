#include "networkservice.h"
#include <QJsonDocument>

#include "pdebug.h"

NetworkService::NetworkService(QObject *parent) : QObject(parent){

}

QNetworkReply* NetworkService::getCustomers(){
    QNetworkRequest request(QUrl(m_address + "/customer"));
    return m_manager->get(request);
}

QNetworkReply* NetworkService::getDepartments(){
    QNetworkRequest request(QUrl(m_address + "/department"));
    return m_manager->get(request);
}

QNetworkReply* NetworkService::getEmployees(){
    QNetworkRequest request(QUrl(m_address + "/employee"));
    return m_manager->get(request);
}

QNetworkReply* NetworkService::getOrders(){
    QNetworkRequest request(QUrl(m_address + "/order"));
    return m_manager->get(request);
}

QNetworkReply* NetworkService::getParts(){
    QNetworkRequest request(QUrl(m_address + "/part"));
    return m_manager->get(request);
}

QNetworkReply* NetworkService::getProducts(){
    QNetworkRequest request(QUrl(m_address + "/product"));
    return m_manager->get(request);
}

QNetworkReply* NetworkService::getProviders(){
    QNetworkRequest request(QUrl(m_address + "/provider"));
    return m_manager->get(request);
}

QNetworkReply* NetworkService::getStates(){
    QNetworkRequest request(QUrl(m_address + "/state"));
    return m_manager->get(request);
}



QNetworkReply* NetworkService::post(Customer c){
    QNetworkRequest request(QUrl(m_address + "/customer"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->post(request, QJsonDocument(c.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::post(Department d){
    QNetworkRequest request(QUrl(m_address + "/department"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->post(request, QJsonDocument(d.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::post(Employee e){
    QNetworkRequest request(QUrl(m_address + "/employee"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->post(request, QJsonDocument(e.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::post(Order o){
    QNetworkRequest request(QUrl(m_address + "/order"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->post(request, QJsonDocument(o.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::post(Part p){
    QNetworkRequest request(QUrl(m_address + "/part"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->post(request, QJsonDocument(p.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::post(Product p){
    QNetworkRequest request(QUrl(m_address + "/product"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->post(request, QJsonDocument(p.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::post(Provider p){
    QNetworkRequest request(QUrl(m_address + "/provider"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->post(request, QJsonDocument(p.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply *NetworkService::post(State s){
    QNetworkRequest request(QUrl(m_address + "/state"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->post(request, QJsonDocument(s.toJSON()).toJson(QJsonDocument::Compact));
}



QNetworkReply* NetworkService::update(Customer c){
    QNetworkRequest request(QUrl(QString(m_address + "/customer/%1").arg(c.id())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->put(request, QJsonDocument(c.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::update(Department d){
    QNetworkRequest request(QUrl(QString(m_address + "/department/%1").arg(d.id())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->put(request, QJsonDocument(d.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::update(Employee e){
    QNetworkRequest request(QUrl(QString(m_address + "/employee/%1").arg(e.id())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->put(request, QJsonDocument(e.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::update(Order o){
    QNetworkRequest request(QUrl(QString(m_address + "/order/%1").arg(o.id())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->put(request, QJsonDocument(o.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::update(Part p){
    QNetworkRequest request(QUrl(QString(m_address + "/part/%1").arg(p.id())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->put(request, QJsonDocument(p.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::update(Product p){
    QNetworkRequest request(QUrl(QString(m_address + "/product/%1").arg(p.id())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->put(request, QJsonDocument(p.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::update(Provider p){
    QNetworkRequest request(QUrl(QString(m_address + "/provider/%1").arg(p.id())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->put(request, QJsonDocument(p.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply *NetworkService::update(State s){
    QNetworkRequest request(QUrl(QString(m_address + "/state/%1").arg(s.id())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return m_manager->put(request, QJsonDocument(s.toJSON()).toJson(QJsonDocument::Compact));
}

QNetworkReply* NetworkService::deleteResource(Customer c){

}

QNetworkReply* NetworkService::deleteResource(Department d){

}

QNetworkReply* NetworkService::deleteResource(Employee e){

}

QNetworkReply* NetworkService::deleteResource(Order o){

}

QNetworkReply* NetworkService::deleteResource(Part p){

}

QNetworkReply* NetworkService::deleteResource(Product p){

}

QNetworkReply* NetworkService::deleteResource(Provider p){

}

QNetworkReply* NetworkService::deleteResource(State s){

}
