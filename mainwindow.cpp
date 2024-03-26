// Dans MainWindow.cpp
#include "MainWindow.h"
#include "ui_MainWindow.h"

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

void MainWindow::on_start_button_clicked()
{

}

void MainWindow::on_settings_button_clicked()
{
    ui->stacked_pages->setCurrentIndex(2);
}

void MainWindow::on_exit_button_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Are you sure that you want to leave ?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QCoreApplication::quit(); // Quitter l'application si l'utilisateur a cliqué sur "Oui"
    }
}

void MainWindow::on_quit_settings_button_clicked()
{
    ui->stacked_pages->setCurrentIndex(0);
}
