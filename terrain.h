#ifndef TERRAIN_H
#define TERRAIN_H
#include "point.h"
#include "fenetre.h"

class Terrain : public Point, public QWidget
{
private:
    int L, C;//L longueur, C largeur
    QPushButton *boutonR1;
public:
    Terrain();
    int getL()const;
    int getC()const;
};

#endif // TERRAIN_H
