#ifndef MISSILE_H
#define MISSILE_H
#include <QGraphicsRectItem>
#include <QObject>

class Missile:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Missile();
public slots:
    void moveMissile();

};





#endif // MISSILE_H
