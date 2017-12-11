#include <QApplication>
#include <QGraphicsScene>
#include "tank.h"
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating the Scene

    QGraphicsScene *scene = new QGraphicsScene();

    //Setting the Sceen Size
    scene->setSceneRect(0,0,900,600);

    Tank *tank = new Tank();

    //making the tank focusable
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    tank->setFocus();

    //add the Tank to the scene
    scene->addItem(tank);

    //Create a view
    QGraphicsView *view = new QGraphicsView();
    view->setFixedSize(900,600);
    view->setScene(scene);

    //create Enemy
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),tank,SLOT(spawn()));
    timer->start(2000);


    //Displaying the View
    view->show();




    return a.exec();
}
