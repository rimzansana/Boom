#ifndef ATTACKER_H
#define ATTACKER_H
#include <QGraphicsRectItem>
#include <QObject>

class Attacker:public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    Attacker();

public slots:
    void moveAttacker();
};



#endif // ATTACKER_H
