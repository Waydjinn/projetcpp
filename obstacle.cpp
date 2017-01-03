#include "obstacle.h"

int Obstacle:: _nbrObstacle = -1;
Point Obstacle:: _TabPoint[20];

Obstacle::Obstacle(int typeObstacle, QWidget *Fen) : QLabel(Fen)
{

    int x;
    int y;
    if(_nbrObstacle != -1){
        x = aleaObsX(19, 0)*50;
        y = aleaObsY(9, 0)*50;
        if(chercherObs(_TabPoint, x, y) == 1){
            x = aleaObsX(19, 0)*50;
            y = aleaObsY(9, 0)*50;
        }
    }else{
        x = aleaObsX(19, 0)*50;
        y = aleaObsY(9, 0)*50;
    }

    if(typeObstacle == 1){ //Arbres
        setPixmap(QPixmap(":/img/img/arbre.png"));
        vie = 1;
        setGeometry(x, y, 50, 50);
        _nbrObstacle++;
        _TabPoint[_nbrObstacle].setX(x);
        _TabPoint[_nbrObstacle].setY(y);
    }else if(typeObstacle == 2){ //Rochers
        setPixmap(QPixmap(":/img/img/roche.png"));
        vie = 7;
        setGeometry(x, y, 50, 50);
        _nbrObstacle++;
        _TabPoint[_nbrObstacle].setX(x);
        _TabPoint[_nbrObstacle].setY(y);
    }else if(typeObstacle == 3){ //Eau
        setPixmap(QPixmap(":/img/img/eau.png"));
        vie = 99999;
        setGeometry(x, y, 50, 50);
        _nbrObstacle++;
        _TabPoint[_nbrObstacle].setX(x);
        _TabPoint[_nbrObstacle].setY(y);
    }
    setScaledContents(true);
    hide();
}

int Obstacle::chercherObs(Point *Tab, int x, int y){
    for(int i = 0; i <= _nbrObstacle; i++){
        if(Tab[i].getX() == x && Tab[i].getY() == y){
            return 0;
        }
    }
    return 1;
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

int Obstacle::aleaObsX(int a, int b){
    return rand()%(a-b+1)+b;
}

int Obstacle::aleaObsY(int a, int b){
    return rand()%(a-b+1)+b;
}
