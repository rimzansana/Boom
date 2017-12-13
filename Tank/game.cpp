#include "game.h"


Game::Game()
{
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

    //removing the scroll bar
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create Enemy
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),tank,SLOT(spawn()));
    timer->start(2000);

    stats =  new PlayerStats();
    stats->Score();
    scene->addItem(stats);

    health = new PlayerStats();
    health->Health();
    scene->addItem(health);

    pack = new HealthPack();
    scene->addItem(pack);

    //Displaying the View
    view->show();
}
