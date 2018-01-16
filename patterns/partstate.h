#ifndef PARTSTATE_H
#define PARTSTATE_H

#include "abstractstate.h"

class PartState : public AbstractState
{
public:
    PartState(NetworkService *service, JSONModel *model);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
};

#endif // PARTSTATE_H
