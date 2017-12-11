#ifndef TANK_H
#define TANK_H
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
