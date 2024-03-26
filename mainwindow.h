#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_button_clicked();
    void on_settings_button_clicked();
    void on_exit_button_clicked();
    void on_quit_settings_button_clicked();

    void on_cowboy_clicked();
    void on_infantry_clicked();
    void on_steve_clicked();
    void on_shotgun_clicked();
    void on_bazooka_clicked();

    void deselectCharacterButton();

private:
    Ui::MainWindow *ui;
    QPushButton *selectedCharacterButton;
    const QString SELECTED_STYLE = "border: 2px solid rgb(239, 228, 176);border-radius: 7px;";

};
#endif // MAINWINDOW_H
