#ifndef CUSTOMERSTATE_H
#define CUSTOMERSTATE_H

#include "abstractstate.h"

class CustomerState : public AbstractState {
public:
    CustomerState(NetworkService *service, JSONModel *model);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
};

#endif // CUSTOMERSTATE_H
