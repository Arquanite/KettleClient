#ifndef STATESTATE_H
#define STATESTATE_H

#include "abstractstate.h"

class StateState : public AbstractState {
public:
    StateState(NetworkService *service, JSONModel *model, QWidget *parent);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
    void update() override;
};

#endif // STATESTATE_H
