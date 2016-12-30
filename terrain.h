#ifndef TERRAIN_H
#define TERRAIN_H

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QObject>

#include "point.h"

class Terrain : public Point
{
public:
    Terrain();
    int getL()const;
    int getC()const;

private:
    int L, C;//L longueur, C largeur

};

#endif // TERRAIN_H
