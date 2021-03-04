
#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include "Player.h"
#include "Score.h"
#include "Health.h"


class Game: public QGraphicsView{
        Q_OBJECT
public:
    Game(QWidget * parent=NULL);

    void displayMainMenu();
    void gameOver();

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
public slots:
    void start();
    void restartGame();

};

#endif // GAME_H
