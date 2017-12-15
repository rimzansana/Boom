#include "playerstats.h"
#include <QFont>
#include <QMessageBox>
#include "game.h"
extern Game *game;


void PlayerStats::Score()
{
    //Setting the Initial score
    score = 0;

    //Creating the Text item on the screen
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("arial",18));

}

void PlayerStats::increaseScore()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

void PlayerStats::Health()
{
    //setting the Initial Health
    health = 50;

    //Creating the Text item on the Screen
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::darkGreen);
    setFont(QFont("arial",18));
    setPos(x()+100,y());
}

void PlayerStats::decreaseHealth()
{
    if(health>0){
    health =health-10;
    setPlainText(QString("Health: ") + QString::number(health));

    }
}



void PlayerStats::increaseHealth()
{

    if(health<50){
    health=health+10;
    setPlainText(QString("Health: ") + QString::number(health));
    }
}

int PlayerStats::getHealth()
{

    if(health<30){
        setDefaultTextColor(Qt::red);
    }
    else if(health==30){
        setDefaultTextColor(Qt::darkGreen);
    }

    else if(health==0){
        game->timer->stop();
        QMessageBox::information(game,"Game Over","Play Again");
        delete game->scene;
    }



return health;
}
