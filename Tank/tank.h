#ifndef TANK_H
#define TANK_H
#include <QGraphicsRectItem>
#include <QKeyEvent>

class Tank: public QGraphicsRectItem{
public:
    Tank();
    void keyPressEvent(QKeyEvent *event);
};







#endif // TANK_H
