#include <QApplication>
#include "game.h"
#include "missile.h"

Game *game;
Missile *shoot;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    game = new Game();


    return a.exec();
}
