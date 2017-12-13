#include "healthpack.h"
#include "stdlib.h"
#include <QGraphicsScene>


HealthPack::HealthPack()
{
    //creating the healthpack
    setRect(0,0,50,50);

    int p = rand() %500;
    setPos(0,p);

}





