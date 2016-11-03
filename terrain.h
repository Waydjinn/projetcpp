#ifndef TERRAIN_H
#define TERRAIN_H
#include <point.h>

class Terrain:public Point
{
private:
    int L, C;//L longueur, C largeur
public:
    Terrain();
    int getL()const;
    int getC()const;
};

#endif // TERRAIN_H
