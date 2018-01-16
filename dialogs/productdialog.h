#ifndef PRODUCTDIALOG_H
#define PRODUCTDIALOG_H

#include <QDialog>
#include "product.h"

namespace Ui {
class ProductDialog;
}

class ProductDialog : public QDialog {
    Q_OBJECT

    bool validate();

public:
    Product product = Product::builder(0, "").build();
    explicit ProductDialog(QWidget *parent = 0);
    ~ProductDialog();

    void reload();

private:
    Ui::ProductDialog *ui;
};

#endif // PRODUCTDIALOG_H
