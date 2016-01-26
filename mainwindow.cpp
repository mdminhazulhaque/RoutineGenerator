#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->routine->setRowCount(DAY);
    ui->routine->setColumnCount(PERIOD);

    ui->routine->setHorizontalHeaderLabels(
                QStringList()
                << "08:00-08:50"
                << "08:50-09:40"
                << "09:40-10:30"
                << "10:50-11:40"
                << "11:40-12:30"
                << "12:30-01:20"
                );
    ui->routine->setVerticalHeaderLabels(
                QStringList()
                << "A"
                << "B"
                << "C"
                << "D"
                << "E"
                );

    ui->routine->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->routine->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    routine.generate();
    generateTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_shuffleDays_clicked()
{
    routine.shuffleDays();
    generateTable();
}

void MainWindow::on_shufflePeriods_clicked()
{
    routine.shufflePeriods();
    generateTable();
}

void MainWindow::generateTable()
{
    ui->routine->clearContents();

    for(uint d=0; d<DAY; d++)
    {
        for(uint p=0; p<PERIOD; p++)
        {
            RoutineItem &ritem = routine.routine[d][p];
            QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(ritem.getCode()));
            item->setBackgroundColor(ritem.getColor());
            ui->routine->setItem(d, p, item);
        }
    }
}
