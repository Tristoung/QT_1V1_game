#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

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

    void keyReleaseEvent(QKeyEvent *event);
    void updatePlayerPosition();
    void updateGame();

private:
    Ui::MainWindow *ui;
    QPushButton *selectedCharacterButton;
    QLabel *curSelectedChar;
    QLabel *curSelectedName;
    const QString SELECTED_STYLE = "border: 2px solid rgb(239, 228, 176);border-radius: 7px;";

    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *player;
    QPixmap playerSprite;
    QPointF playerPosition;

    bool moveLeft = false;
    bool moveRight = false;
    bool moveUp = false;
    bool moveDown = false;

    QTimer *timer;


protected:
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

};

#endif
