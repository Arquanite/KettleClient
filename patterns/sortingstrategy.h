#ifndef SORTINGSTRATEGY_H
#define SORTINGSTRATEGY_H

#include <QVariant>

// Strategia

class SortingStrategy {
public:
    SortingStrategy();
    virtual bool less(QVariant a, QVariant b) = 0;
};

#endif // SORTINGSTRATEGY_H
