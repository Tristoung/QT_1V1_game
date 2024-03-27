
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , selectedCharacterButton(nullptr)
{
    ui->setupUi(this);
    ui->stacked_pages->setCurrentIndex(0);

    on_cowboy_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Boutons du menu

void MainWindow::on_settings_button_clicked()
{
    ui->stacked_pages->setCurrentIndex(2);
}

void MainWindow::on_exit_button_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Are you sure that you want to exit ?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QCoreApplication::quit();
    }
}

void MainWindow::on_quit_settings_button_clicked()
{
    ui->stacked_pages->setCurrentIndex(0);
}


// Lancement de la partie

void MainWindow::on_start_button_clicked()
{
    // Initialiser la scène et la vue
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    view->setFixedSize(1075, 630);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);

    if (selectedCharacterButton != nullptr) {
        if (selectedCharacterButton == ui->cowboy)
            playerSprite.load(":/static/characters/cowboy.png");
        else if (selectedCharacterButton == ui->infantry)
            playerSprite.load(":/static/characters/infantry.png");
        else if (selectedCharacterButton == ui->shotgun)
            playerSprite.load(":/static/characters/shotgun.png");
        else if (selectedCharacterButton == ui->bazooka)
            playerSprite.load(":/static/characters/bazooka.png");
        else if (selectedCharacterButton == ui->steve)
            playerSprite.load(":/static/characters/steve.png");

        player = new QGraphicsPixmapItem(playerSprite);
        scene->addItem(player);
        playerPosition = QPointF(200, 200);
        player->setPos(playerPosition);
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePlayerPosition);
    timer->start(20);
}

// Contrôles du sprite

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Q || event->key() == Qt::Key_Left)
        moveLeft = true;
    else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
        moveRight = true;
    else if (event->key() == Qt::Key_Z || event->key() == Qt::Key_Up)
        moveUp = true;
    else if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
        moveDown = true;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Q || event->key() == Qt::Key_Left)
        moveLeft = false;
    else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
        moveRight = false;
    else if (event->key() == Qt::Key_Z || event->key() == Qt::Key_Up)
        moveUp = false;
    else if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
        moveDown = false;
}

void MainWindow::updatePlayerPosition()
{
    qreal dx = 0, dy = 0;
    if (moveLeft)
        dx = -5;
    else if (moveRight)
        dx = 5;
    if (moveUp)
        dy = -5;
    else if (moveDown)
        dy = 5;
    playerPosition += QPointF(dx, dy);
    player->setPos(playerPosition);
}

void MainWindow::updateGame()
{
    updatePlayerPosition();
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


    deselectCharacterButton();
    selectedCharacterButton = ui->cowboy;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);

    qDebug() << "Personnage sélectionné : Cowboy";

    curSelectedChar = ui->img_curPlayer;
    QString currentPlayerImgStyle = curSelectedChar->styleSheet();
    currentPlayerImgStyle.remove("background-image: url(:/static/characters/"+selectedCharacterButton->objectName()+".png);");
    currentPlayerImgStyle += "background-image: url(:/static/characters/cowboy.png);";
    curSelectedChar->setStyleSheet(currentPlayerImgStyle);

    ui->name_curPlayer->setText("Cowboy");
}

void MainWindow::on_infantry_clicked()
{
    deselectCharacterButton();
    selectedCharacterButton = ui->infantry;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);

    qDebug() << "Personnage sélectionné : Infantry";

    curSelectedChar = ui->img_curPlayer;
    QString currentPlayerImgStyle = curSelectedChar->styleSheet();
    currentPlayerImgStyle.remove("background-image: url(:/static/characters/"+selectedCharacterButton->objectName()+".png);");
    currentPlayerImgStyle += "background-image: url(:/static/characters/infantry.png);";
    curSelectedChar->setStyleSheet(currentPlayerImgStyle);

    ui->name_curPlayer->setText("Infantry");
}

void MainWindow::on_shotgun_clicked()
{
    deselectCharacterButton();
    selectedCharacterButton = ui->shotgun;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);

    qDebug() << "Personnage sélectionné : Shotgun";

    curSelectedChar = ui->img_curPlayer;
    QString currentPlayerImgStyle = curSelectedChar->styleSheet();
    currentPlayerImgStyle.remove("background-image: url(:/static/characters/"+selectedCharacterButton->objectName()+".png);");
    currentPlayerImgStyle += "background-image: url(:/static/characters/shotgun.png);";
    curSelectedChar->setStyleSheet(currentPlayerImgStyle);

    ui->name_curPlayer->setText("Shotgun");
}

void MainWindow::on_bazooka_clicked()
{
    deselectCharacterButton();
    selectedCharacterButton = ui->bazooka;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);

    qDebug() << "Personnage sélectionné : Bazooka";

    curSelectedChar = ui->img_curPlayer;
    QString currentPlayerImgStyle = curSelectedChar->styleSheet();
    currentPlayerImgStyle.remove("background-image: url(:/static/characters/"+selectedCharacterButton->objectName()+".png);");
    currentPlayerImgStyle += "background-image: url(:/static/characters/bazooka.png);";
    curSelectedChar->setStyleSheet(currentPlayerImgStyle);

    ui->name_curPlayer->setText("Bazooka");

}

void MainWindow::on_steve_clicked()
{
    deselectCharacterButton();
    selectedCharacterButton = ui->steve;
    QString currentStyle = selectedCharacterButton->styleSheet();
    currentStyle += SELECTED_STYLE;
    selectedCharacterButton->setStyleSheet(currentStyle);

    qDebug() << "Personnage sélectionné : Steve";

    curSelectedChar = ui->img_curPlayer;
    QString currentPlayerImgStyle = curSelectedChar->styleSheet();
    currentPlayerImgStyle.remove("background-image: url(:/static/characters/"+selectedCharacterButton->objectName()+".png);");
    currentPlayerImgStyle += "background-image: url(:/static/characters/steve.png);";
    curSelectedChar->setStyleSheet(currentPlayerImgStyle);

    ui->name_curPlayer->setText("Steve");

}

// Détection de la position de la souris

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPointF mousePos = event->pos();

    // qDebug() << "Mouse position: " << mousePos;

    QMainWindow::mouseMoveEvent(event);
}
