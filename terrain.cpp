#include "terrain.h"

Terrain::Terrain()
{

    this->C = 1000;
    this->L = 600;
}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}
