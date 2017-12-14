#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H
#include <QGraphicsTextItem>

class PlayerStats: public QGraphicsTextItem{
public:
    void Score();
    void increaseScore();
    void Health();
    void decreaseHealth();
    void increaseHealth();
    int getHealth();

private:
    qint32 score;
    qint32 health;

};


#endif // PLAYERSTATS_H
