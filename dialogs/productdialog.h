#ifndef PRODUCTDIALOG_H
#define PRODUCTDIALOG_H

#include <QDialog>
#include "product.h"
#include "jsonmodel.h"

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

public slots:
    void add();
    void remove();

private:
    Ui::ProductDialog *ui;
    JSONModel *model;
};

#endif // PRODUCTDIALOG_H
