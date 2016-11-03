#include "terrain.h"

Terrain::Terrain()
{
    this->C = 300;
    this->L = 115;
}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}
