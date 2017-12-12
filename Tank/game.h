#ifndef GAME_H
#define GAME_H
#include "tank.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "score.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    Score *score;



};





#endif // GAME_H
