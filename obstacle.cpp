#include "obstacle.h"

Obstacle::Obstacle(int typeObstacle, QWidget *Fen)
{
    if(typeObstacle == 1){ //Arbres

    }else if(typeObstacle == 2){ //Rochers

    }else if(typeObstacle == 3){ //Eau

    }
}


int Obstacle::getVie() const{
    return this->vie;
}

int Obstacle::getPosX() const{
    return this->posX;
}

int Obstacle::getPosY() const{
    return this->getPosY();
}

int Obstacle::getType() const{
    return this->getType();
}

void Obstacle::setVie(int n){
    this->vie = n;
}

void Obstacle::setPosX(int n){
    this->posX = n;
}

void Obstacle::setPosY(int n){
    this->posY = n;
}

void Obstacle::setType(int n){
    this->type = n;
}
