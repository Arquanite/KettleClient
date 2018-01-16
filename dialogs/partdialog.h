#ifndef PARTDIALOG_H
#define PARTDIALOG_H

#include <QDialog>
#include "part.h"

namespace Ui {
class PartDialog;
}

class PartDialog : public QDialog {
    Q_OBJECT

    bool validate();

public:
    Part part = Part(0, "", 0);
    explicit PartDialog(QWidget *parent = 0);
    ~PartDialog();

private:
    Ui::PartDialog *ui;
};

#endif // PARTDIALOG_H
