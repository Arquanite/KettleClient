#ifndef STATEDIALOG_H
#define STATEDIALOG_H

#include <QDialog>
#include "state.h"

namespace Ui {
class StateDialog;
}

class StateDialog : public QDialog
{
    Q_OBJECT

    bool validate();

public:
    State state = State(0, "", 0);
    explicit StateDialog(QWidget *parent = 0);
    ~StateDialog();

private:
    Ui::StateDialog *ui;
};

#endif // STATEDIALOG_H
