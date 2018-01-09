#ifndef PROVIDERDIALOG_H
#define PROVIDERDIALOG_H

#include <QDialog>

namespace Ui {
class ProviderDialog;
}

class ProviderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProviderDialog(QWidget *parent = 0);
    ~ProviderDialog();

private:
    Ui::ProviderDialog *ui;
};

#endif // PROVIDERDIALOG_H
