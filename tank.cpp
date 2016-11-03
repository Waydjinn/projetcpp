#include "tank.h"

Tank::Tank(const Terrain T)
{
    this->capacite = (T.getL())/10;
    this->obus2 = 10;
    this->obus3 = 5;
}
