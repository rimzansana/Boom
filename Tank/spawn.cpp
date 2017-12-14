#include "spawn.h"


void Spawn::spawnEnemy()
{
    overallHealth = game->health->getHealth();
    if(overallHealth>0){
    Attacker *enemy = new Attacker();
    scene()->addItem(enemy);}
}

void Spawn::spawnHealthPacks()
{
    if(overallHealth>0){
    HealthPack *pack = new HealthPack();
    scene()->addItem(pack);
    }

}
