#ifndef PARTSTATE_H
#define PARTSTATE_H

#include "abstractstate.h"

class PartState : public AbstractState {
public:
    PartState(NetworkService *service, JSONModel *model, QWidget *parent);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
    void update() override;
};

#endif // PARTSTATE_H
