#ifndef STATESTATE_H
#define STATESTATE_H

#include "abstractstate.h"

class StateState : public AbstractState {
public:
    StateState(NetworkService *service, JSONModel *model);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
};

#endif // STATESTATE_H
