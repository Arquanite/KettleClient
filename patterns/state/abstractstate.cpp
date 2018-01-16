#include "abstractstate.h"

AbstractState::AbstractState(NetworkService *service, JSONModel *model, QWidget *parent) : m_service(service), m_model(model), m_parent(parent){

}

AbstractState::~AbstractState(){

}
