// Dans MainWindow.cpp
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , selectedCharacterButton(nullptr)
{
    ui->setupUi(this);
    ui->stacked_pages->setCurrentIndex(0);
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
    reply = QMessageBox::question(this, "Confirm", "Are you sure that you want to exit ?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QCoreApplication::quit(); // Quitter l'application si l'utilisateur a cliqué sur "Oui"
    }
}

void MainWindow::on_quit_settings_button_clicked()
{
    ui->stacked_pages->setCurrentIndex(0);
}


// Sélection des personnages

void MainWindow::deselectCharacterButton()
{
    if (selectedCharacterButton != nullptr) {
        QString currentStyle = selectedCharacterButton->styleSheet();
        currentStyle.remove(SELECTED_STYLE);
        selectedCharacterButton->setStyleSheet(currentStyle);
    }
}

void MainWindow::on_cowboy_clicked()
{
    qDebug() << "cowboy";
    deselectCharacterButton();
    selectedCharacterButton = ui->cowboy;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);
}

void MainWindow::on_infantry_clicked()
{
    qDebug() << "infantry";
    deselectCharacterButton();
    selectedCharacterButton = ui->infantry;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);
}

void MainWindow::on_shotgun_clicked()
{
    qDebug() << "shotgun";
    deselectCharacterButton();
    selectedCharacterButton = ui->shotgun;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);
}

void MainWindow::on_bazooka_clicked()
{
    qDebug() << "bazooka";
    deselectCharacterButton();
    selectedCharacterButton = ui->bazooka;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);
}

void MainWindow::on_steve_clicked()
{
    qDebug() << "steve";
    deselectCharacterButton();
    selectedCharacterButton = ui->steve;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);
}
