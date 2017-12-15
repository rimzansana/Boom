#include <QApplication>
#include "game.h"

Game *game;
bool restart=true;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    while(restart==true){
    game = new Game();
    restart = false;
    }

    return a.exec();
}
