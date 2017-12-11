#include "attacker.h"
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

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
    setPos(x()-5,y());

   if(pos().x()<-100){
        scene()->removeItem(this);
        delete this;
        qDebug()<< "Enemy Removed";
   }

}
