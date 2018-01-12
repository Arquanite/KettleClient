#include "jsonable.h"

JSONAble::~JSONAble(){

}

bool JSONAble::fromJSON(QJsonObject json){
    if(!validate(json)) return false;
    setValuesMap(json.toVariantMap());
    return true;
}

QJsonObject JSONAble::toJSON(){
    return QJsonObject::fromVariantMap(valuesMap());
}
