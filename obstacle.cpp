#include "obstacle.h"


Obstacle::Obstacle(int typeObstacle, QWidget *Fen) : QLabel(Fen)
{
    srand(time(NULL));
    if(typeObstacle == 1){ //Arbres
        this->setPixmap(QPixmap("/img/img/arbre.png"));
        vie = 1;
        setGeometry(aleaObsX()*50, aleaObsY()*50, 50, 50);
    }else if(typeObstacle == 2){ //Rochers
        this->setPixmap(QPixmap("/img/img/roche.png"));
        vie = 7;
    }else if(typeObstacle == 3){ //Eau
        this->setPixmap(QPixmap("/img/img/eau.png"));
        vie = 99999;
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

int Obstacle::aleaObsX(){
    return rand()%19;
}

int Obstacle::aleaObsY(){
    return rand()%9;
}
