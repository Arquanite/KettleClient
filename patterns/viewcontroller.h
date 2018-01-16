#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include "jsonmodel.h"
#include <QObject>

#include "networkservice.h"
#include "states.h"

// ???

enum {
    TypeProvider,
    TypeCustomer,
    TypeEmployee,
    TypeDepartment,
    TypePart,
    TypeProduct,
    TypeState,
    TypeOrder
};

class ViewController : public QObject {
    Q_OBJECT
private:
    QList<AbstractState*> m_states;
    AbstractState *m_currentState;
    NetworkService m_service;
    JSONModel *m_model;
    int m_current = -1;
public:
    explicit ViewController(JSONModel *model, QWidget *parent = nullptr);

public slots:
    void viewChanged(int id);
    void add();
    void edit();
    void remove();
};

#endif // VIEWCONTROLLER_H
