#include "attacker.h"
#include "typeinfo"
extern Game *game;

Attacker::Attacker(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    //setting the size
    setRect(0,0,90,90);

    //setting the position
    int randomPosition = rand() %500;
    setPos(800,randomPosition);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveAttacker()));
    timer->start(50);

}

void Attacker::moveAttacker()
{
    //Removing the attacker when it hits the tank
    QList<QGraphicsItem *> collidingObjects = collidingItems();
    for(int i=0,n=collidingObjects.size(); i<n;++i){
        if(typeid(*(collidingObjects[i]))==typeid(Tank)){

            game->health->decreaseHealth();


            //Attacker is removed from the scene and deleted.
            scene()->removeItem(this);

            delete this;
            return;
        }
    }

    setPos(x()-5,y());

   if(pos().x()<-90){
        game->health->decreaseHealth();
        scene()->removeItem(this);
        delete this;
        qDebug()<< "Enemy Removed";
   }

}
