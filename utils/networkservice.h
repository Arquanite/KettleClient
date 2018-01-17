#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>

#include "entities.h"

class NetworkService : public QObject {
    Q_OBJECT
    const QString m_address = "http://localhost:3000";
    QNetworkAccessManager *m_manager = new QNetworkAccessManager(this);

public:
    explicit NetworkService(QObject *parent = nullptr);

    QNetworkReply* getCustomers();
    QNetworkReply* getDepartments();
    QNetworkReply* getEmployees();
    QNetworkReply* getOrders();
    QNetworkReply* getParts();
    QNetworkReply* getProducts();
    QNetworkReply* getProviders();
    QNetworkReply* getStates();

    QNetworkReply* post(Customer c);
    QNetworkReply* post(Department d);
    QNetworkReply* post(Employee e);
    QNetworkReply* post(Order o);
    QNetworkReply* post(Part p);
    QNetworkReply* post(Product p);
    QNetworkReply* post(Provider p);
    QNetworkReply* post(State s);

    QNetworkReply* update(Customer c);
    QNetworkReply* update(Department d);
    QNetworkReply* update(Employee e);
    QNetworkReply* update(Order o);
    QNetworkReply* update(Part p);
    QNetworkReply* update(Product p);
    QNetworkReply* update(Provider p);
    QNetworkReply* update(State s);

    QNetworkReply* deleteResource(Customer c);
    QNetworkReply* deleteResource(Department d);
    QNetworkReply* deleteResource(Employee e);
    QNetworkReply* deleteResource(Order o);
    QNetworkReply* deleteResource(Part p);
    QNetworkReply* deleteResource(Product p);
    QNetworkReply* deleteResource(Provider p);
    QNetworkReply* deleteResource(State s);

    QNetworkReply* login(QString name, QString pass);

signals:

public slots:
};

#endif // NETWORKSERVICE_H
