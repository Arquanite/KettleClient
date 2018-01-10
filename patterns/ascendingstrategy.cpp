#include "ascendingstrategy.h"

AscendingStrategy::AscendingStrategy(){

}

bool AscendingStrategy::less(QVariant a, QVariant b){
    return a < b;
}
