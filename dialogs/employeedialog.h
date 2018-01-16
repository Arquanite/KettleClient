#ifndef EMPLOYEEDIALOG_H
#define EMPLOYEEDIALOG_H

#include <QDialog>
#include "employee.h"

namespace Ui {
class EmployeeDialog;
}

class EmployeeDialog : public QDialog {
    Q_OBJECT

    bool validate();

public:
    Employee employee = Employee(0, "", "", 0, 0, 0, 0);
    explicit EmployeeDialog(QWidget *parent = 0);
    ~EmployeeDialog();

    void reload();

private:
    Ui::EmployeeDialog *ui;
};

#endif // EMPLOYEEDIALOG_H
