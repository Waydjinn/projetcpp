#ifndef TERRAIN_H
#define TERRAIN_H

#include "point.h"

class Terrain
{
public:
    Terrain();
    int getL()const;
    int getC()const;

private:
    int L, C;//L longueur, C largeur

};

#endif // TERRAIN_H
