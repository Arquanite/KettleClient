#include "credentials.h"

Credentials &Credentials::instance(){
    static Credentials instance;
    return instance;
}

QString Credentials::token() const {
    return m_token;
}

void Credentials::setToken(QString token){
    m_token = token;
}
