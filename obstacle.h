#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QLabel>
#include <cstdlib>
#include <ctime>
#include <cstdio>

#include "point.h"

class Obstacle :public QLabel
{
private:
    int vie, posX, posY, type;

public:
    Obstacle();
    Obstacle(QWidget *Fen);
    Obstacle(QWidget *Fen, int x, int y, int typeO);

    static Point _TabPoint[50];
    static Point _TabImpacts[50];
    static int _nbrImpacts;
    static int _nbrObstacle;

    int getVie() const;
    int getPosObsX() const;
    int getPosObsY() const;
    int getType() const;
    void setVie(int n);
    void setPosObsX(int n);
    void setPosObsY(int n);
    void setType(int n);
    int aleaObsX(int a, int b);
    int aleaObsY(int a, int b);
    int chercherObs(Point *Tab, int x, int y);
};

#endif // OBSTACLE_H
