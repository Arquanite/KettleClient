#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <QDialog>

#include "networkservice.h"
#include "jsonmodel.h"

// Stan

class AbstractState {
protected:
    NetworkService *m_service;
    JSONModel *m_model;
    QWidget *m_parent;

public:
    AbstractState(NetworkService *service, JSONModel *model, QWidget *parent);
    virtual ~AbstractState();

    virtual void getList() = 0;
    virtual void add() = 0;
};

#endif // ABSTRACTSTATE_H
