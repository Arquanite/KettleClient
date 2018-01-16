#ifndef PROVIDERDIALOG_H
#define PROVIDERDIALOG_H

#include <QDialog>
#include "provider.h"

namespace Ui {
class ProviderDialog;
}

class ProviderDialog : public QDialog {
    Q_OBJECT

    bool validate();

public:
    Provider provider = Provider(0, "", "");
    explicit ProviderDialog(QWidget *parent = 0);
    ~ProviderDialog();

    void reload();

private:
    Ui::ProviderDialog *ui;
};

#endif // PROVIDERDIALOG_H
