#include "game.h"
#include "tank.h"
#include <QDebug>

Game::Game()
{
    //creating the Scene
    this->setMouseTracking(true);
    scene = new QGraphicsScene();

    //Defining the Sceen Size
    scene->setSceneRect(0,0,900,600);

    Tank * tank = new Tank();

    //making the tank focusable
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    tank->setFocus();

    //add the Tank to the scene
    scene->addItem(tank);

    //Create a view
    view = new QGraphicsView();
    view->setFixedSize(900,600);
    view->setScene(scene);

    //removing the scroll bar
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //Creating the attacker
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),tank,SLOT(spawnAttacker()));
    timer->start(2000);


    //Creating the healthpack
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),tank,SLOT(spawnHealthPacks()));
    timer->start(5000);

    //Creating and adding the score to the screen
    stats =  new PlayerStats();
    stats->Score();
    scene->addItem(stats);

    //Creating and adding the Health to the screen
    health = new PlayerStats();
    health->Health();
    scene->addItem(health);


    //Displaying the View
    view->show();
}


/*void Game::mousePressEvent(QMouseEvent *event)
{
    switch(event->button()){
        case Qt::LeftButton: {
            qDebug() << "mouse Left";
            scene->tank->setFlag(QGraphicsItem::ItemIsFocusable);
            break;
        }
        case Qt::MiddleButton: {
            qDebug() << "mouse Middle";
            break;
        }
        case Qt::RightButton: {
            qDebug() << "mouse Right";
             this->tank->setFlag(QGraphicsItem::ItemIsFocusable);
            break;
        }
    }
}


*/



