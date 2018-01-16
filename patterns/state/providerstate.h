#ifndef PROVIDERSTATE_H
#define PROVIDERSTATE_H

#include "abstractstate.h"

class ProviderState : public AbstractState {
public:
    ProviderState(NetworkService *service, JSONModel *model);

    // AbstractState interface
public:
    void getList() override;
    void add() override;
};

#endif // PROVIDERSTATE_H
