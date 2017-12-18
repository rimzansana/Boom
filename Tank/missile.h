#ifndef MISSILE_H
#define MISSILE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include "attacker.h"
#include <QTimer>
#include <QList>
#include <QMediaPlayer>
#include "game.h"



class Missile:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Missile(QGraphicsItem * parent=0);
    QMediaPlayer *explosion;

public slots:
    void moveMissile();



};





#endif // MISSILE_H
