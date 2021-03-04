#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/image/ball.png"));


    // creer et connecter le timer a move() pour creer une ball tout les 0.5s
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet::move(){
    // avoir list de tout les items en collision
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // si l'item est un enemy, detruire ball et enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // augmenter le score
            game->score->increase();

            // retirer de la scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // supprimer de la scene (memoire)
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    // si pas de collision, la ball avance
    setPos(x(),y()-15);
    // si la ball sort de l'écran, supprimer
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
