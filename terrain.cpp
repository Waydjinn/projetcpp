#include "terrain.h"

Terrain::Terrain()
{

    this->C = 970;
    this->L = 480;
}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}
