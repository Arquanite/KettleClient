#ifndef ASCENDINGSTRATEGY_H
#define ASCENDINGSTRATEGY_H

#include "sortingstrategy.h"

// Strategia

class AscendingStrategy : public SortingStrategy {
public:
    AscendingStrategy();

    // SortingStrategy interface
public:
    bool less(QVariant a, QVariant b) override;
};

#endif // ASCENDINGSTRATEGY_H
