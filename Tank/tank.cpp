#include "tank.h"
#include "healthpack.h"
#include "game.h"
#include <QMessageBox>
#include <QMovie>
#include <QLabel>
#include <QDebug>
extern Game *game;


Tank::Tank(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

  setPixmap(QPixmap(":/images/Tank.gif").scaled(150,100,Qt::KeepAspectRatio));

    //Positioning the tank

    qint32 xPos = 0;
    qint32 yPos =250;
    setPos(xPos,yPos);

}

void Tank::keyPressEvent(QKeyEvent *event)
{


    if (event->key()==Qt::Key_Up){

        //Keeping the Tank on screen
        if(pos().y()>0)
        setPos(x(),y()-25);

    }

    else if (event->key()==Qt::Key_Down){
        //Keeping the Tank on screen
        if(pos().y()<500)
        setPos(x(),y()+25);
    }


    /* else if (event->key()==Qt::Key_Left){
         setPos(x()-10,y());
     }

     else if (event->key()==Qt::Key_Right){
         setPos(x()+10,y());
     }

     */

    else if (event->key()==Qt::Key_Space){

        //Creating a Missile if the Space is pressed

        Missile *missile = new Missile();

       //setting the position of missile
       missile->setPos(x()+70,y()+30);
       scene()->addItem(missile);


    }
}

void Tank::spawnAttacker()
{
   overallHealth = game->health->checkHealth();
   if(overallHealth>0){
    Attacker *enemy = new Attacker();
    scene()->addItem(enemy);}
}

void Tank::spawnHealthPacks()
{

    if(game->health->getHealth()>0){
    qDebug() <<overallHealth;
    HealthPack *pack = new HealthPack();
    scene()->addItem(pack);
    }
}
