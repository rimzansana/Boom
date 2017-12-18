#ifndef ATTACKER_H
#define ATTACKER_H
#include "tank.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "game.h"
#include <QMediaPlayer>


class Attacker:public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Attacker(QGraphicsItem * parent=0);


public slots:
    void moveAttacker();
private:
    QMediaPlayer *collision;

};



#endif // ATTACKER_H
