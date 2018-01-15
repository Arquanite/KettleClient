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

    void post(Customer c);
    void post(Department d);
    void post(Employee e);
    void post(Order o);
    void post(Part p);
    void post(Product p);
    void post(Provider p);
    void post(State s);

    void update(Customer c);
    void update(Department d);
    void update(Employee e);
    void update(Order o);
    void update(Part p);
    void update(Product p);
    void update(Provider p);
    void update(State s);

    void deleteResource(Customer c);
    void deleteResource(Department d);
    void deleteResource(Employee e);
    void deleteResource(Order o);
    void deleteResource(Part p);
    void deleteResource(Product p);
    void deleteResource(Provider p);
    void deleteResource(State s);

signals:

public slots:
};

#endif // NETWORKSERVICE_H
