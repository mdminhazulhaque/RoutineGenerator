#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "routine.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_shuffleDays_clicked();
    void on_shufflePeriods_clicked();
    void generateTable();

private:
    Ui::MainWindow *ui;
    Routine routine;
};

#endif // MAINWINDOW_H
