#ifndef EMPLOYEESTATE_H
#define EMPLOYEESTATE_H

#include "abstractstate.h"

class EmployeeState : public AbstractState{
public:
    EmployeeState(NetworkService *service, JSONModel *model, QWidget *parent);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
};

#endif // EMPLOYEESTATE_H
