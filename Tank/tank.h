#ifndef TANK_H
#define TANK_H
#include "missile.h"
#include "attacker.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>

class Tank: public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Tank(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
    qint32 overallHealth;

public slots:
    void spawnAttacker();
    void spawnHealthPacks();

private:
    QMediaPlayer *missileLaunch;
};







#endif // TANK_H
