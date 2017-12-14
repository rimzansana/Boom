#include "missile.h"
#include <QDebug>
#include "typeinfo"

extern Game *game;

Missile::Missile(QGraphicsItem *parent):QObject(), QGraphicsRectItem(parent)
{

    //Creating the Missile

    setRect(0,0,50,10);

    //Creating the timer
    QTimer *timer = new QTimer();

    //Setting the timeout
    timer->start(50);

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(moveMissile()));



}

void Missile::moveMissile()
{

    //Destroying the Attackers
    QList<QGraphicsItem *> collidingObjects = collidingItems();
    for(qint32 i=0,n=collidingObjects.size(); i<n;++i){
        if(typeid(*(collidingObjects[i]))==typeid(Attacker)){

            game->stats->increaseScore();

            //Both the Missile and the attacker are removed and deleted.
            scene()->removeItem(collidingObjects[i]);
            scene()->removeItem(this);


            delete collidingObjects[i];
            delete this;
            return;
        }
    }

    setPos(x()+10,y());

    if(pos().x()>900){
        scene()->removeItem(this);
        delete this;




    }
}
