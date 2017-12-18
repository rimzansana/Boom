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

public slots:
    void moveMissile();

private:
    QMediaPlayer *explosion;



};





#endif // MISSILE_H
