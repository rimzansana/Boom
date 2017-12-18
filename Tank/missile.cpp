#include "missile.h"
#include <QDebug>
#include "typeinfo"
#include <QMovie>

extern Game *game;

Missile::Missile(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{

    //Defining the size of the missile
   setPixmap(QPixmap(":/images/Missile.gif"));

    //connecting the missile item to the move function
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(moveMissile()));
    timer->start(50);

    //creating the QMediaPlayer
    explosion = new QMediaPlayer();
    explosion->setMedia(QUrl("qrc:/soundsEffects/explosion.mp3"));


}

void Missile::moveMissile()
{

    //Destroying the Attackers
    QList<QGraphicsItem *> collidingObjects = collidingItems();
    for(qint32 i=0,n=collidingObjects.size(); i<n;++i){
        if(typeid(*(collidingObjects[i]))==typeid(Attacker)){


            game->stats->increaseScore();
            explosion->play();

            //Both the Missile and the attacker are removed and deleted.
            scene()->removeItem(collidingObjects[i]);
            scene()->removeItem(this);


            delete collidingObjects[i];
            delete this;
            return;
        }
    }


    setPos(x()+10,y());

    //The missile is removed when it moves out of the screeen
    if(pos().x()>900){
        scene()->removeItem(this);
        delete this;




    }
}
