#ifndef HEALTHPACK_H
#define HEALTHPACK_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "game.h"
#include <QMediaPlayer>

class HealthPack:public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
  public:
    HealthPack(QGraphicsItem * parent=0);

public slots:
    void moveHealthPack();

private:
    QMediaPlayer *collection;

};

#endif // HEALTHPACK_H
