#include "tank.h"
#include "healthpack.h"
#include "game.h"
#include <QMessageBox>
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include <QMediaPlayer>
extern Game *game;
extern Missile *shoot;


Tank::Tank(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

  setPixmap(QPixmap(":/images/Tank.gif").scaled(150,100,Qt::KeepAspectRatio));

    //Positioning the tank

    qint32 xPos = 0;
    qint32 yPos =250;
    setPos(xPos,yPos);


    missileLaunch = new QMediaPlayer();
    missileLaunch->setMedia(QUrl("qrc:/soundsEffects/missilelaunch.mp3"));
    missileLaunch->setVolume(50);

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


    else if (event->key()==Qt::Key_Space){

        //Creating a Missile if the Space is pressed

        Missile *missile = new Missile();

       //setting the position of missile
       missile->setPos(x()+70,y()+30);
       scene()->addItem(missile);
       qDebug() <<"its here";

       // playing the Sound Effect
       if (missileLaunch->state()==QMediaPlayer::PlayingState){
           missileLaunch->setPosition(0);
       }

       else{
           missileLaunch->play();
       }



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
