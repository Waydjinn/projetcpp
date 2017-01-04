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
    QLabel *fond;

    //Obstacle Obs[50];


    Obstacle *Obs1, *Obs2, *Obs3, *Obs4, *Obs5, *Obs6, *Obs7, *Obs8, *Obs9, *Obs10;
    Obstacle *Obs11,*Obs12, *Obs13, *Obs14, *Obs15, *Obs16, *Obs17, *Obs18, *Obs19;
    Obstacle *Obs20, *Obs21, *Obs22, *Obs23, *Obs24, *Obs25, *Obs26, *Obs27, *Obs28, *Obs29, *Obs30;
    Obstacle *Obs31, *Obs32, *Obs33, *Obs34, *Obs35, *Obs36, *Obs37, *Obs38, *Obs39, *Obs40, *Obs41;
    Obstacle *Obs42, *Obs43, *Obs44, *Obs45, *Obs46, *Obs47, *Obs48, *Obs49, *Obs50;


    int getL()const;
    int getC()const;
private:
    int L, C;//L longueur, C largeur

};

#endif // TERRAIN_H
