#ifndef MISSILE_H
#define MISSILE_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include "attacker.h"
#include <QTimer>
#include <QList>


class Missile:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Missile();
public slots:
    void moveMissile();

};





#endif // MISSILE_H
