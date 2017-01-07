#ifndef TERRAIN_H
#define TERRAIN_H

#include <QLabel>

#include "obstacle.h"

class Terrain
{
public:
    Terrain(QWidget *Fen);
    QLabel *carte;
    QList<Obstacle *> listObstacle;

    int getL()const;
    int getC()const;
private:
    int L, C;//L longueur, C largeur

};

#endif // TERRAIN_H
