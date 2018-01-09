#ifndef RANDOMACCESSLIST_H
#define RANDOMACCESSLIST_H

#include <QList>

class RandomAccessList {
private:
    QList<QString> m_list;
public:
    RandomAccessList();
    RandomAccessList(std::initializer_list<QString> init);

    QString get();
};

#endif // RANDOMACCESSLIST_H
