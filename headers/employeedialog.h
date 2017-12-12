#ifndef EMPLOYEEDIALOG_H
#define EMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class EmployeeDialog;
}

class EmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeDialog(QWidget *parent = 0);
    ~EmployeeDialog();

private:
    Ui::EmployeeDialog *ui;
};

#endif // EMPLOYEEDIALOG_H
