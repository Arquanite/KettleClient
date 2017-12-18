#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include "jsonmodel.h"
#include <QObject>

enum {
    Provider,
    Customer,
    Employee,
    Department,
    Part,
    Product,
    State,
    Order
};

class ViewController : public QObject {
    Q_OBJECT
private:
    JSONModel *m_model;
public:
    explicit ViewController(JSONModel *model, QObject *parent = nullptr);

public slots:
    void viewChanged(int id);
};

#endif // VIEWCONTROLLER_H
