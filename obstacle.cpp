#include "obstacle.h"

int Obstacle:: _nbrObstacle = -1;
Point Obstacle:: _TabPoint[50];

Obstacle::Obstacle(){

}

Obstacle::Obstacle(QWidget *Fen) : QLabel(Fen)
{

    int x;
    int y;
    type = rand()%(3-1+1)+1;

    if(_nbrObstacle != -1){
        x = aleaObsX(19, 0)*50;
        y = aleaObsY(9, 0)*50;
        while(chercherObs(_TabPoint, x, y) == 1){
            x = aleaObsX(19, 0)*50;
            y = aleaObsY(9, 0)*50;
        }
    }else{
        x = aleaObsX(19, 0)*50;
        y = aleaObsY(9, 0)*50;
    }

    if(this->getType() == 1){ //Arbres
        setPixmap(QPixmap(":/img/img/arbre.png"));
        vie = 1;
        setGeometry(x, y, 50, 50);
        _nbrObstacle++;
        _TabPoint[_nbrObstacle].setX(x);
        _TabPoint[_nbrObstacle].setY(y);
    }else if(this->getType() == 2){ //Rochers
        setPixmap(QPixmap(":/img/img/roche.png"));
        vie = 7;
        setGeometry(x, y, 50, 50);
        _nbrObstacle++;
        _TabPoint[_nbrObstacle].setX(x);
        _TabPoint[_nbrObstacle].setY(y);
    }else if(this->getType() == 3){ //Eau
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


Obstacle::Obstacle(QWidget *Fen, int x, int y) : QLabel(Fen)
{
    setGeometry(x, y, 50, 50);
    setPixmap(QPixmap(":/img/img/impact.png"));
    show();
}



int Obstacle::chercherObs(Point *Tab, int x, int y){
    for(int i = 0; i <= _nbrObstacle; i++){
        while(Tab[i].getX() == x && Tab[i].getY() == y){
            return 1;
        }
    }
    return 0;
}

int Obstacle::getVie() const{
    return this->vie;
}

int Obstacle::getPosObsX() const{
    return this->posX;
}

int Obstacle::getPosObsY() const{
    return this->posY;
}

int Obstacle::getType() const{
    return this->type;
}

void Obstacle::setVie(int n){
    this->vie = n;
}

void Obstacle::setPosObsX(int n){
    this->posX = n;
}

void Obstacle::setPosObsY(int n){
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
