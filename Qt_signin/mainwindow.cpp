#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog2.h"
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
    Dialog dialog(this);
    dialog.exec();
}
void MainWindow::on_pushButton_2_clicked()
{
    Dialog2 dialog2(this);
    dialog2.exec();
}

