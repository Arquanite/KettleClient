#ifndef DESCENDINGSTRATEGY_H
#define DESCENDINGSTRATEGY_H

#include "sortingstrategy.h"

// Strategia
class DescendingStrategy : public SortingStrategy {
public:
    DescendingStrategy();

    // SortingStrategy interface
public:
    bool less(QVariant a, QVariant b) override;
};

#endif // DESCENDINGSTRATEGY_H
