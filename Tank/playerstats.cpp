#include "playerstats.h"
#include <QFont>


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
    setDefaultTextColor(Qt::blue);
    setFont(QFont("arial",18));
    setPos(x()+100,y());
}

void PlayerStats::decreaseHealth()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}



void PlayerStats::increaseHealth()
{
    health++;
    setPlainText(QString("Health: ") + QString::number(health));
}
