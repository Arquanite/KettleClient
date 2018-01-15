#ifndef PDEBUG_H
#define PDEBUG_H

#include <QDebug>

#define pDebug() qDebug() << __PRETTY_FUNCTION__ << "->"

#endif // PDEBUG_H
