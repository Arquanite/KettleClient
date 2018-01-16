#ifndef DEPARTMENTSTATE_H
#define DEPARTMENTSTATE_H

#include "abstractstate.h"

class DepartmentState : public AbstractState {
public:
    DepartmentState(NetworkService *service, JSONModel *model, QWidget *parent);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
    void update() override;
};

#endif // DEPARTMENTSTATE_H
