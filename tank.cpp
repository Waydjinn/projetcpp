#include "tank.h"

int Tank:: _nbrTank = 0;

Tank::Tank(QWidget *Fen)
{
    if(_nbrTank == 0){  //Tank J1
        this->posx = 20;
        this->posy = 10;
        tankJ1 = new QLabel(Fen);
        tankJ1->setObjectName("tankJ1");
        tankJ1->setGeometry(QRect(this->getPosx(), this->getPosY(), 40, 40));
        tankJ1->setPixmap(QPixmap(QString("img/TankDroit.png"))); //tank1->getImage()
        tankJ1->setScaledContents(true);
        tankJ1->hide();
    }else if(_nbrTank == 1){ //Tank J2
        this->posx = 940;
        this->posy = 450;
        tankJ2 = new QLabel(Fen);
        tankJ2->setObjectName("tankJ2");
        tankJ2->setGeometry(QRect(this->getPosx(), this->getPosY(), 40, 40));
        tankJ2->setPixmap(QPixmap(QString("img/TankGaucheJ2.png")));
        tankJ2->setScaledContents(true);
        tankJ2->hide();
    }
    this->capacite = 0;
    this->obus2 = 10;
    this->obus3 = 5;
    _nbrTank++;
}

//Getters
int Tank::getCapacite() const{
    return this->capacite;
}

int Tank::getObus2() const{
    return this->obus2;
}

int Tank::getObus3() const{
    return this->obus3;
}

int Tank::getPosx() const{
    return this->posx;
}

int Tank::getPosY() const{
    return this->posy;
}

//Setters
void Tank::setCapacite(int n){
    this->capacite = n;
}

void Tank::setObus2(int n){
    this->obus2 = n;
}

void Tank::setObus3(int n){
    this->obus3 = n;
}

void Tank::setPosX(int n){
    this->posx = n;
}

void Tank::setPosY(int n){
    this->posy = n;
}

//Fonctions

int Tank::avancer(int mouv){ //Ajouter les conditons pour ne pas traverser le tank adverse ou les obstacles
    int aBouge = 0;
    //Vers le haut
    if(mouv == 1 && getPosY()>10){
        this->setPosX(this->getPosx());
        this->setPosY(this->getPosY()-40);
        aBouge = 1;
    }//Vers le bas
    else if(mouv == 2 && getPosY()<450){
        this->setPosX(this->getPosx());
        this->setPosY(this->getPosY()+40);
        aBouge = 1;
    }//Vers la droite
    else if(mouv == 3 && getPosx()<940){
        this->setPosX(this->getPosx()+40);
        this->setPosY(this->getPosY());
        aBouge = 1;
    }//Vers la gauche
    else if(mouv == 4 && getPosx()>20){
        this->setPosX(this->getPosx()-40);
        this->setPosY(this->getPosY());
        aBouge = 1;
    }
    return aBouge;
}


void Tank::keyPressEvent (QKeyEvent * event)
{
    if(event->key() == Qt::Key_Up && this->getCapacite() != 0){
        if(this->avancer(1)){
            this->setCapacite(this->getCapacite()-1);
        }
    }else if(event->key() == Qt::Key_Down && this->getCapacite() != 0){
        if(this->avancer(2)){
            this->setCapacite(this->getCapacite()-1);
        }
    }else if(event->key() == Qt::Key_Right && this->getCapacite() != 0){
        if(this->avancer(3)){
            this->setCapacite(this->getCapacite()-1);
        }
    }else if(event->key() == Qt::Key_Left && this->getCapacite() != 0){
        if(this->avancer(4)){
            this->setCapacite(this->getCapacite()-1);
        }
    }
}
