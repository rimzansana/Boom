#include <QApplication>
#include <QGraphicsScene>
#include "tank.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating the Scene

    QGraphicsScene *scene = new QGraphicsScene();

    //Setting the Sceen Size
    scene->setSceneRect(0,0,800,600);


    //Creating the tank

    Tank *tank = new Tank();
    tank->setRect(0,0,100,100);




    //making the tank focusable
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    tank->setFocus();

    //add the Tank to the scene
    scene->addItem(tank);

    //Create a view
    QGraphicsView *view = new QGraphicsView();
    view->setFixedSize(800,600);
    view->setScene(scene);

    //remove this
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //Displaying the View
    view->show();




    return a.exec();
}
