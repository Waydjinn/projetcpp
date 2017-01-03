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
