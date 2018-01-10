#include "descendingstrategy.h"

DescendingStrategy::DescendingStrategy(){

}

bool DescendingStrategy::less(QVariant a, QVariant b){
    return a > b;
}
