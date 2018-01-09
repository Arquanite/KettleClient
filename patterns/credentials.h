#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <QString>

// Singleton

class Credentials {
    QString m_token;
    Credentials() = default;
    Credentials(const Credentials&) = delete;
    Credentials& operator =(const Credentials&) = delete;
    Credentials(Credentials&&) = delete;
    Credentials& operator =(Credentials&&) = delete;
public:
    static Credentials& instance();
    QString token() const;
    void setToken(QString token);
};

#endif // CREDENTIALS_H
