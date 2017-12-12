#ifndef ATTACKER_H
#define ATTACKER_H
#include "tank.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

class Attacker:public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    Attacker(QGraphicsItem * parent=0);

public slots:
    void moveAttacker();
};



#endif // ATTACKER_H
