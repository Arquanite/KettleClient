#ifndef RANDOMJSONFACTORY_H
#define RANDOMJSONFACTORY_H

#include <QJsonObject>
#include "randomaccesslist.h"

class RandomJSONFactory {
private:
    RandomAccessList m_names_m;
    RandomAccessList m_names_f;
    RandomAccessList m_surnames_m;
    RandomAccessList m_surnames_f;
    RandomAccessList m_colors;
    RandomAccessList m_departments;

public:
    RandomJSONFactory();

    QJsonObject randomProvider();
    QJsonObject randomCustomer();
    QJsonObject randomEmployee();
    QJsonObject randomDepartment();
    QJsonObject randomPart();
    QJsonObject randomProduct();
    QJsonObject randomState();
    QJsonObject randomOrder();

protected:
    QString randomPartName();
    QString randomPersonName();
    QString randomDepartmentName();
    QString randomProviderName();
    QString randomProductName();
    QString randomStateName();
    QString randomAddress();
    QString randomNIP();
    QString randomDate();
    int randomID();
};

#endif // RANDOMJSONFACTORY_H
