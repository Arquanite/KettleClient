#include "stringvalidator.h"
#include <QRegularExpression>

bool StringValidator::isNonEmpty(QString string){
    QRegularExpression regex;
    regex.setPattern("^[^\\s]( |[^\\s])*[^\\s]$");
    QRegularExpressionMatch match = regex.match(string);
    return match.hasMatch();
}
