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

    void reload();
    void setComboProvider(QList<QString> list);

    void setProviderIds(const QList<int> &value);

private:
    Ui::PartDialog *ui;
    QList<int> providerIds;
};

#endif // PARTDIALOG_H
