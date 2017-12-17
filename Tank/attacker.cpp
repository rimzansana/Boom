#include "attacker.h"
#include "typeinfo"
extern Game *game;

Attacker::Attacker(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    //setting the size of the attacker
    setRect(0,0,90,90);

    //setting the position of the attacker
    qint32 randomPosition = rand() %500;
    setPos(800,randomPosition);

    //Connecting the attacker item to the move method
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveAttacker()));
    timer->start(50);

}

void Attacker::moveAttacker()
{
    //Removing the attacker when it hits the tank
    QList<QGraphicsItem *> collidingObjects = collidingItems();
    for(qint32 i=0,n=collidingObjects.size(); i<n;++i){
        if(typeid(*(collidingObjects[i]))==typeid(Tank)){

            game->health->decreaseHealth();


            //Attacker is removed from the scene and deleted.
            scene()->removeItem(this);

            delete this;
            return;
        }
    }

    setPos(x()-5,y());


   //The attacker item is removed when it moves out of the screeen
   if(pos().x()<-90){
        game->health->decreaseHealth();
        scene()->removeItem(this);
        delete this;
        qDebug()<< "Enemy Removed";
   }

}
