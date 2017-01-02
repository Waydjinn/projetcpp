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

    QLabel *arbre1;
    QLabel *arbre2;
    QLabel *arbre3;
    QLabel *arbre4;

    QLabel *roche1;

    QLabel *eau1;

    int getL()const;
    int getC()const;
private:
    int L, C;//L longueur, C largeur

};

#endif // TERRAIN_H
