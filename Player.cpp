#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // son de la ball
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/laser.mp3"));

    // image bg
    setPixmap(QPixmap(":/image/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // bouger joueur droite gauche
    if (event->key() == Qt::Key_Q){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // tirer avec escape
    else if (event->key() == Qt::Key_Space){
        // creer ball
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+45,y());
        scene()->addItem(bullet);

        // jouer son ball
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }
}

void Player::spawn(){
    // creer enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
