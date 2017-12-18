#ifndef HEALTHPACK_H
#define HEALTHPACK_H
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include "game.h"
#include <QMediaPlayer>

class HealthPack:public QObject ,public QGraphicsRectItem{
    Q_OBJECT
  public:
    HealthPack(QGraphicsItem * parent=0);

public slots:
    void moveHealthPack();

private:
    QMediaPlayer *collection;

};

#endif // HEALTHPACK_H
