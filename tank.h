#ifndef TANK_H
#define TANK_H


class Tank
{
private:
    int capacite; //nbr de déplacement du tank L/10
    int obus1, obus2, obus3;
public:
    Tank();
    void viser(); //Tourner le canon et ajuster angle
    void tirer(); //Tirer un obus après avoir visé
    void avancer(); //Bouger
    void finDeTour(); //Finir le tour et passer au J2
    void estTouche(); //Tank touché ou non
};

#endif // TANK_H
