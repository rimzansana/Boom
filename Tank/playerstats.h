#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H
#include <QGraphicsTextItem>

class PlayerStats: public QGraphicsTextItem{
public:
    void Score();
    void increaseScore();
    void Health();
    void decreaseHealth();

private:
    int score;
    int health;
};


#endif // PLAYERSTATS_H