#ifndef TERRAIN_H
#define TERRAIN_H

#include <QLabel>


#include "point.h"
#include "obstacle.h"

class Terrain
{
public:
    Terrain(QWidget *Fen);
    QLabel *carte;

    Obstacle *Obs1, *Obs2, *Obs3, *Obs4, *Obs5, *Obs6, *Obs7, *Obs8, *Obs9, *Obs10;
    Obstacle *Obs11,*Obs12, *Obs13, *Obs14, *Obs15, *Obs16, *Obs17, *Obs18, *Obs19;
    Obstacle *Obs20;


    int getL()const;
    int getC()const;
private:
    int L, C;//L longueur, C largeur

};

#endif // TERRAIN_H
