#include "networkservice.h"

#include <QtDebug>

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
    qDebug()<<request.sslConfiguration().caCertificates();
    return m_manager->get(request);
}

QNetworkReply *NetworkService::getStates(){
    QNetworkRequest request(QUrl(m_address + "/state"));
    return m_manager->get(request);
}

void NetworkService::post(Customer c){

}

void NetworkService::post(Department d){

}

void NetworkService::post(Employee e){

}

void NetworkService::post(Order o){

}

void NetworkService::post(Part p){

}

void NetworkService::post(Product p){

}

void NetworkService::post(Provider p){

}

void NetworkService::post(State s){

}

void NetworkService::update(Customer c){

}

void NetworkService::update(Department d){

}

void NetworkService::update(Employee e){

}

void NetworkService::update(Order o){

}

void NetworkService::update(Part p){

}

void NetworkService::update(Product p){

}

void NetworkService::update(Provider p){

}

void NetworkService::update(State s){

}

void NetworkService::deleteResource(Customer c){

}

void NetworkService::deleteResource(Department d){

}

void NetworkService::deleteResource(Employee e){

}

void NetworkService::deleteResource(Order o){

}

void NetworkService::deleteResource(Part p){

}

void NetworkService::deleteResource(Product p){

}

void NetworkService::deleteResource(Provider p){

}

void NetworkService::deleteResource(State s){

}
