#ifndef TANK_H
#define TANK_H

#include <QLabel>
#include <QKeyEvent>
#include <QEvent>

#include "terrain.h"


class Tank : public Obstacle
{
private:
    int capacite; //nbr de déplacement du tank
    int typeObusCharg, obus1, obus2, obus3, posx, posy;
    int nbrMouvTour; //nbr mouvement par tour

public:
    Tank(QWidget *Fen);
    QLabel *tankJ1;
    QLabel *tankJ2;
    QList<Obstacle *> listImpacts;
    static int _nbrTank;
    int aleaTankX();
    int aleaTankY();

    int verif(Tank *tankJoueur, int mouv); //Vérifie que le tank ne traverse pas d'obstacle
    void tirer(QWidget *Fen, int angle, int force , Tank *tankJoueur); //Tirer un obus après avoir visé
    void avancer(int mouv, int joueur, Tank *tankJoueur, Tank *tankAdverse); //Bouger
    int aTouche(Tank *tankAdverse); //Tank touché renvoie 1 ou non renvoie 0

    int getPosx() const;
    int getPosY() const;
    int getObus2() const;
    int getObus3() const;
    int getCapacite() const;
    int getNbrMouvTour() const;
    int getTypeObusCharg() const;
    void setTypeObusCharg(int n);
    void setNbrMouvTour(int n);
    void setPosX(int n);
    void setPosY(int n);
    void setObus2(int n);
    void setObus3(int n);
    void setCapacite(int n);
};

#endif // TANK_H
