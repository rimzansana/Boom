#include "missile.h"
#include <QTimer>



Missile::Missile()
{

    //Creating the Missile
    int x = 4;
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
}
