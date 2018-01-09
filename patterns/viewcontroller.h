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
    int m_current = -1;
public:
    explicit ViewController(JSONModel *model, QObject *parent = nullptr);

public slots:
    void viewChanged(int id);
    void add();
    void edit();
    void remove();
};

#endif // VIEWCONTROLLER_H
