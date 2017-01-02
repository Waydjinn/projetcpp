#ifndef TANK_H
#define TANK_H

#include <QLabel>
#include <QKeyEvent>
#include <QEvent>
#include <QGraphicsRectItem>

#include "terrain.h"


class Tank : public QGraphicsRectItem
{
private:
    void keyPressEvent ();
    int capacite; //nbr de déplacement du tank
    int obus1, obus2, obus3, posx, posy;

public:
    void keyPressEvent(QKeyEvent *event);

    Tank(QWidget *Fen);
    QLabel *tankJ1;
    QLabel *tankJ2;
    static int _nbrTank;
    int aleaTankX();
    int aleaTankY();

    void viser(); //Tourner le canon et ajuster angle
    void tirer(); //Tirer un obus après avoir visé
    int avancer(int mouv); //Bouger renvoie 1 si le tank a bougé (posx et posy modifier), sinon 0
    void finDeTour(); //Finir le tour
    void estTouche(); //Tank touché ou non

    int getPosx() const;
    int getPosY() const;
    int getObus2() const;
    int getObus3() const;
    int getCapacite() const;
    void setPosX(int n);
    void setPosY(int n);
    void setObus2(int n);
    void setObus3(int n);
    void setCapacite(int n);
};

#endif // TANK_H
