#include "missile.h"
#include <QTimer>
#include <QDebug>



Missile::Missile()
{

    //Creating the Missile

    setRect(0,0,50,10);

    //Creating the timer
    QTimer *timer = new QTimer();

    //Setting the timeout
    timer->start(50);

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(moveMissile()));



}

void Missile::moveMissile()
{
    setPos(x()+10,y());

    if(pos().x()>900){
        scene()->removeItem(this);
        delete this;
        qDebug() <<"Bullet Deleted";



    }
}
