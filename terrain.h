#ifndef TERRAIN_H
#define TERRAIN_H

#include <QLabel>
#include <time.h>  //time
#include <stdlib.h>//srand, rand

#include "point.h"

class Terrain
{
public:
    Terrain(QWidget *Fen);
    QLabel *carte;
    int getL()const;
    int getC()const;
private:
    int L, C;//L longueur, C largeur

};

#endif // TERRAIN_H
