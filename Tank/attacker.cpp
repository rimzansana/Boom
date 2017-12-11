#include "attacker.h"
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "tank.h"

Attacker::Attacker()
{
    //setting the size
    setRect(0,0,100,100);

    //setting the position
    int randomPosition = rand() %500;
    setPos(800,randomPosition);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveAttacker()));
    timer->start(50);

}

void Attacker::moveAttacker()
{
    //Removing the attcker when it hits the tank
    QList<QGraphicsItem *> collidingObjects = collidingItems();
    for(int i=0,n=collidingObjects.size(); i<n;++i){
        if(typeid(*(collidingObjects[i]))==typeid(Tank)){


            scene()->removeItem(this);


            delete this;
            return;
        }
    }

    setPos(x()-5,y());

   if(pos().x()<-100){
        scene()->removeItem(this);
        delete this;
        qDebug()<< "Enemy Removed";
   }

}
