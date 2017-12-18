#include "healthpack.h"
#include "stdlib.h"
#include <QGraphicsScene>
#include "typeinfo"
#include "game.h"
extern Game *game;

HealthPack::HealthPack(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    //Defining the size of the healthpack
    setRect(0,0,50,50);

    //using the random function to generate positions for the healthpack
    qint32 p = rand() %500;
    setPos(850,p);

    //connecting the healthpack item to the move function
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveHealthPack()));
    timer->start(50);

    collection = new QMediaPlayer();
    collection->setMedia(QUrl("qrc:/soundsEffects/collection.mp3"));
}


void HealthPack::moveHealthPack()
{
    //Removing the Health Pack when the tank Collects it
    QList<QGraphicsItem *> collidingObjects = collidingItems();
    for(qint32 i=0,n=collidingObjects.size(); i<n;++i){
        if(typeid(*(collidingObjects[i]))==typeid(Tank)){

            //increasing the health
            game->health->increaseHealth();

            //playing the Soundeffect
            collection->play();

            //Removing the Health Pack from the Screen
            scene()->removeItem(this);

            delete this;
            return;
        }
    }

    setPos(x()-20,y());

    //The healthpack item is removed when it moves out of the screeen
   if(pos().x()<-50){
        scene()->removeItem(this);
        delete this;
        qDebug()<< "Health Removed";
   }
}
