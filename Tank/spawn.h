#ifndef SPAWN_H
#define SPAWN_H
#include <QGraphicsItem>
#include <QObject>
#include "attacker.h"
#include "healthpack.h"


#include "game.h"
extern Game *game;

class Spawn:public QObject,public QGraphicsItem{
    Q_OBJECT
public:
     qint32 overallHealth;
public slots:
    void spawnEnemy();
    void spawnHealthPacks();
};


#endif // SPAWN_H
