#include "playerstats.h"
#include <QFont>
#include <QMessageBox>
#include "game.h"
#include "typeinfo"
#include <QDebug>
extern Game *game;



void PlayerStats::Score()
{
    //Setting the Initial score
    score = 0;

    //Creating the Text item on the screen
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("arial",16));

}

void PlayerStats::increaseScore()
{
    score= score+5;
    setPlainText(QString("Score: ") + QString::number(score));
}

void PlayerStats::Health()
{
    //setting the Initial Health
    health = 100;

    //Creating the Text item on the Screen
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::darkGreen);
    setFont(QFont("arial",16));
    setPos(x()+100,y());
}

void PlayerStats::decreaseHealth()
{
    if(health>0){
    health =health-50;
    setPlainText(QString("Health: ") + QString::number(health));
    }
}



void PlayerStats::increaseHealth()
{
    if(health<100){
    health=health+10;
    setPlainText(QString("Health: ") + QString::number(health));
    }
}

qint32 PlayerStats::checkHealth()
{

    if(health<30 && health>0){
        setDefaultTextColor(Qt::red);
    }
    else if(health>=30){
        setDefaultTextColor(Qt::darkGreen);
    }

    else if(health <= 0){
        QMessageBox::information(game,"Game Over","Play Again",0);
         QList<QGraphicsItem *> itemsInScene = game->scene->items();
          for(qint32 i=0,n=itemsInScene.size(); i<n;++i){
              if(typeid(*(itemsInScene[i]))==typeid(Attacker) || typeid(*(itemsInScene[i]))==typeid(HealthPack)){

                  scene()->removeItem(itemsInScene[i]);

                  delete itemsInScene[i];
              }
          }
        qDebug() <<"Game reset";
         health = 100;
          setPlainText(QString("Health: ") + QString::number(health));



    }
    qDebug()<<health;

    return health;
}

qint32 PlayerStats::getHealth()
{
 return health;
}


