#ifndef ORDERDIALOG_H
#define ORDERDIALOG_H

#include <QDialog>
#include <jsonmodel.h>
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

public slots:
    void add();
    void remove();

private:
    Ui::OrderDialog *ui;
    JSONModel *model;
};

#endif // ORDERDIALOG_H
