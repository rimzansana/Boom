#ifndef MISSILE_H
#define MISSILE_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include "attacker.h"
#include <QTimer>
#include <QList>
#include "game.h"


class Missile:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Missile(QGraphicsItem * parent=0);
public slots:
    void moveMissile();

};





#endif // MISSILE_H
