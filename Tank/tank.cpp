#include "tank.h"
#include "missile.h"
#include <QGraphicsScene>

void Tank::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Left){
        setPos(x()-10,y());
    }

    else if (event->key()==Qt::Key_Right){
        setPos(x()+10,y());
    }

    else if (event->key()==Qt::Key_Up){
        setPos(x(),y()-10);
    }

    else if (event->key()==Qt::Key_Down){
        setPos(x(),y()+10);
    }

    else if (event->key()==Qt::Key_Space){

        //Creating a Missile if the Space is pressed

        Missile *missile = new Missile();
        scene()->addItem(missile);




    }
}
