#include "tank.h"
#include "missile.h"
#include "attacker.h"
#include <QGraphicsScene>


Tank::Tank()
{
    //Creating the tank


    setRect(0,0,100,100);

    //Positioning the tank

    int xPos = 0;
    int yPos =250;
    setPos(xPos,yPos);

}

void Tank::keyPressEvent(QKeyEvent *event)
{


    if (event->key()==Qt::Key_Up){

        //Keeping the Tank on screen
        if(pos().y()>0)
        setPos(x(),y()-10);

    }

    else if (event->key()==Qt::Key_Down){
        //Keeping the Tank on screen
        if(pos().y()<500)
        setPos(x(),y()+10);
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
       missile->setPos(x()+70,y()+45);
       scene()->addItem(missile);


    }
}

void Tank::spawn()
{
    Attacker *huh = new Attacker();
    scene()->addItem(huh);
}
