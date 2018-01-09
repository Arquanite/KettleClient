#ifndef PARTDIALOG_H
#define PARTDIALOG_H

#include <QDialog>

namespace Ui {
class PartDialog;
}

class PartDialog : public QDialog {
    Q_OBJECT

public:
    explicit PartDialog(QWidget *parent = 0);
    ~PartDialog();

private:
    Ui::PartDialog *ui;
};

#endif // PARTDIALOG_H
