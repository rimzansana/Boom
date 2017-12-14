#include "healthpack.h"
#include "stdlib.h"
#include <QGraphicsScene>
#include "typeinfo"
#include "game.h"
extern Game *game;

HealthPack::HealthPack(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    //creating the healthpack
    setRect(0,0,50,50);

    qint32 p = rand() %500;
    setPos(850,p);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveHealthPack()));
    timer->start(50);
}


void HealthPack::moveHealthPack()
{
    //Removing the Health Pack when the tank Collects it
    QList<QGraphicsItem *> collidingObjects = collidingItems();
    for(qint32 i=0,n=collidingObjects.size(); i<n;++i){
        if(typeid(*(collidingObjects[i]))==typeid(Tank)){

            game->health->increaseHealth();


            //Removing the Health Pack from the Screen
            scene()->removeItem(this);

            delete this;
            return;
        }
    }

    setPos(x()-20,y());

   if(pos().x()<-50){
        scene()->removeItem(this);
        delete this;
        qDebug()<< "Health Removed";
   }
}
