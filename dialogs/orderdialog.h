#ifndef ORDERDIALOG_H
#define ORDERDIALOG_H

#include <QDialog>
#include "order.h"

namespace Ui {
class OrderDialog;
}

class OrderDialog : public QDialog {
    Q_OBJECT

    bool validate();

public:
    Order order = Order::builder(0, 0, "").build();
    explicit OrderDialog(QWidget *parent = 0);
    ~OrderDialog();

    void reload();

private:
    Ui::OrderDialog *ui;
};

#endif // ORDERDIALOG_H
