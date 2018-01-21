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
    void setComboDepartament(QList<QString> list);

    void setDepartmentIds(const QList<int> &value);

private:
    Ui::EmployeeDialog *ui;
    QList<int> departmentIds;
};

#endif // EMPLOYEEDIALOG_H
