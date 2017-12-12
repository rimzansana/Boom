#include <QApplication>
#include "game.h"

extern Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();








    return a.exec();
}
