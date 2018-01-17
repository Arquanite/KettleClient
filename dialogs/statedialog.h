#ifndef STATEDIALOG_H
#define STATEDIALOG_H

#include <QDialog>
#include "state.h"

namespace Ui {
class StateDialog;
}

class StateDialog : public QDialog {
    Q_OBJECT

    bool validate();

public:
    State state = State(0, "", 0);
    explicit StateDialog(QWidget *parent = 0);
    ~StateDialog();

    void reload();
    void setComboDepartment(QList<QString> list);

    void setDepartmentIds(const QList<int> &value);

private:
    Ui::StateDialog *ui;
    QList<int> departmentIds;
};

#endif // STATEDIALOG_H
