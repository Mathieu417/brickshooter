#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //random x pos
    int random_number = rand() % 700;
    setPos(random_number,0);

    // image enemy
    setPixmap(QPixmap(":/image/enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);


    //creer et connecter le timer a move() pour creer enemy tout les 0.5s
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start timer
    timer->start(50);
}

void Enemy::move(){
    // bouger enemy vers le bas
    setPos(x(),y()+15);

    // destruire enemy quand il quitte l'ecran
    if (pos().y() > 600){
        //retirer de la vie
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
