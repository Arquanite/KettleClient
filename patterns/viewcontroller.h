#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include "jsonmodel.h"
#include <QObject>

#include "networkservice.h"
#include "states.h"

// ???

class ViewController : public QObject {
    Q_OBJECT
private:
    QList<AbstractState*> m_states;
    AbstractState *m_currentState;
    NetworkService m_service;
    JSONModel *m_model;
public:
    explicit ViewController(JSONModel *model, QWidget *parent = nullptr);

public slots:
    void viewChanged(int id);
    void add();
    void edit();
    void remove();
    void refresh();
};

#endif // VIEWCONTROLLER_H
