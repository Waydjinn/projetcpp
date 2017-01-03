#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QLabel>

class Obstacle
{
private:
    int vie, posX, posY, type;

public:
    Obstacle(int typeObstacle, QWidget *Fen);
    int getVie() const;
    int getPosX() const;
    int getPosY() const;
    int getType() const;
    void setVie(int n);
    void setPosX(int n);
    void setPosY(int n);
    void setType(int n);
};

#endif // OBSTACLE_H
