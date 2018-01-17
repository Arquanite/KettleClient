#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewcontroller.h"
#include "jsonmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    ViewController *m_controller;
    JSONModel *m_model;
    bool buttonState = true;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void log();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
