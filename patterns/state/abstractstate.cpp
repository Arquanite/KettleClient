#include "abstractstate.h"

AbstractState::AbstractState(NetworkService *service, JSONModel *model) : m_service(service), m_model(model){

}

AbstractState::~AbstractState(){

}
