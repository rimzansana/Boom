#ifndef TANK_H
#define TANK_H
#include "missile.h"
#include "attacker.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

class Tank: public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    Tank();
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
};







#endif // TANK_H
