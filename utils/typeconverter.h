#ifndef TYPECONVERTER_H
#define TYPECONVERTER_H

#include <QList>
#include "jsonable.h"

class TypeConverter {
public:
    TypeConverter() = delete;
    template<class T>
    static QList<JSONAble*> toJSONAble(QList<T> list){
        static_assert(!std::is_pointer<T>::value, "Argument cannot be pointer. You should use QList<T> instead of QList<T*>");
        static_assert(std::is_base_of<JSONAble, T>::value, "Base class of argument must be JSONAble");
        QList<JSONAble*> jsons;
        for(T element : list) jsons.append(new T(element));
        return jsons;
    }
};

#endif // TYPECONVERTER_H
