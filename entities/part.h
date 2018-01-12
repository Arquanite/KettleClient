#ifndef PART_H
#define PART_H

#include "jsonable.h"

class Part : public JSONAble {
protected:
    int m_id;
    QString m_name;
    int m_providerId;
public:
    Part(int id, QString name, int providerId);

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

    int providerId() const;
    void setProviderId(int providerId);

    // JSONAble interface
protected:
    bool validate(QJsonObject json) override;
    QVariantMap valuesMap() override;
    void setValuesMap(QVariantMap values) override;
};

#endif // PART_H
