#include "missile.h"
#include <QDebug>
#include "typeinfo"

extern Game *game;

Missile::Missile(QGraphicsItem *parent):QObject(), QGraphicsRectItem(parent)
{

    //Defining the size of the missile

    setRect(0,0,50,10);

    //connecting the missile item to the move function
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(moveMissile()));
    timer->start(50);


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

    //The missile is removed when it moves out of the screeen
    if(pos().x()>900){
        scene()->removeItem(this);
        delete this;




    }
}
