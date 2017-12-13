#ifndef HEALTHPACK_H
#define HEALTHPACK_H
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

class HealthPack:public QObject ,public QGraphicsRectItem{
    Q_OBJECT
  public:
    HealthPack();

};

#endif // HEALTHPACK_H
