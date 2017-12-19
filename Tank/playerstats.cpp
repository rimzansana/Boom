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
    health =health-20;
    setPlainText(QString("Health: ") + QString::number(health));
    }
}



void PlayerStats::increaseHealth()
{
    if(health<100){
    health=health+20;
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



       QMessageBox popUp;
        popUp.setWindowTitle(" You failed to protect north korea");
        popUp.setText("Do you want to try again?");
        popUp.setStandardButtons(QMessageBox:: Yes | QMessageBox::Cancel);
        popUp.setDefaultButton(QMessageBox::Yes);

        switch (popUp.exec()){

        case QMessageBox::Yes: {

            delete game->view;
            delete game->scene;
            delete game;
            QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
            break;
        }


        case QMessageBox::Cancel: {
        delete game->view;
        delete game;
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


