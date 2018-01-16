#ifndef DEPARTMENTDIALOG_H
#define DEPARTMENTDIALOG_H

#include <QDialog>
#include "department.h"

namespace Ui {
class DepartmentDialog;
}

class DepartmentDialog : public QDialog {
    Q_OBJECT

    bool validate();

public:
    Department department = Department(0, "");
    explicit DepartmentDialog(QWidget *parent = 0);
    ~DepartmentDialog();

    void reload();

private:
    Ui::DepartmentDialog *ui;
};

#endif // DEPARTMENTDIALOG_H
