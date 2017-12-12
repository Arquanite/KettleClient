#ifndef DEPARTMENTDIALOG_H
#define DEPARTMENTDIALOG_H

#include <QDialog>

namespace Ui {
class DepartmentDialog;
}

class DepartmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DepartmentDialog(QWidget *parent = 0);
    ~DepartmentDialog();

private:
    Ui::DepartmentDialog *ui;
};

#endif // DEPARTMENTDIALOG_H
