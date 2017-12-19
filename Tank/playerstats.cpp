#include "playerstats.h"
#include <QFont>
#include <QMessageBox>
#include "game.h"
#include "typeinfo"
#include <QDebug>
#include <QProcess>
#include <QApplication>

extern Game *game;



void PlayerStats::Score()
{
    //Setting the Initial score
    score = 0;

    //Creating the Text item on the screen
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
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
    setDefaultTextColor(Qt::green);
    setFont(QFont("arial",16));
    setPos(x()+150,y());
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
        setDefaultTextColor(Qt::green);
    }

    else if(health <= 0){


       //Defining the Message Box
       QMessageBox popUp;

        popUp.setText("<h2>Game over </h2> <br><br> <h3>Do you want to play again?</h3>");
        popUp.setStandardButtons(QMessageBox:: Yes | QMessageBox::Cancel);
        popUp.setDefaultButton(QMessageBox::Yes);

        switch (popUp.exec()){

        case QMessageBox::Yes: {

            QApplication::quit();
            QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
            break;
        }


        case QMessageBox::Cancel: {
        QApplication::quit();
        break;
        }


    }

    }

    return health;
}

qint32 PlayerStats::getHealth()
{
 return health;
}


