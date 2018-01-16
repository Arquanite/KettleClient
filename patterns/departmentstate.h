#ifndef DEPARTMENTSTATE_H
#define DEPARTMENTSTATE_H

#include "abstractstate.h"

class DepartmentState : public AbstractState {
public:
    DepartmentState(NetworkService *service, JSONModel *model);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
};

#endif // DEPARTMENTSTATE_H
