#ifndef GAME_H
#define GAME_H
#include "tank.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <playerstats.h>
#include <healthpack.h>
#include "attacker.h"


class Game: public QGraphicsView{
public:
    Game();
    PlayerStats *stats;
    PlayerStats *health;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;


    //void mousePressEvent(QMouseEvent * event);








};





#endif // GAME_H
