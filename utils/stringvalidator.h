#ifndef STRINGVALIDATOR_H
#define STRINGVALIDATOR_H

#include <QString>

class StringValidator {
public:
    StringValidator() = delete;

    static bool isNonEmpty(QString string);
};

#endif // STRINGVALIDATOR_H
