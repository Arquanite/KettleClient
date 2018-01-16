#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include <QDialog>
#include "customer.h"

namespace Ui {
class CustomerDialog;
}

class CustomerDialog : public QDialog {
    Q_OBJECT

    bool validate();

public:
    Customer customer = Customer(0, "", "", "");
    explicit CustomerDialog(QWidget *parent = 0);
    ~CustomerDialog();

private:
    Ui::CustomerDialog *ui;
};

#endif // CUSTOMERDIALOG_H
