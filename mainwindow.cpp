#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Create an instance of your dialog
    // 'this' sets the MainWindow as the parent
    Dialog alarmDialog(this);

    // .exec() opens the dialog and pauses code execution here until it's closed
    if (alarmDialog.exec() == QDialog::Accepted) {

        qDebug() << "Alarm dialog closed. Time to refresh the list!";

        // Next Step: Call a function here to reload the UI with the new JSON data
        // loadAlarmsToList();
    }
}
