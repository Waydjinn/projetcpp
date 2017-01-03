#include "tank.h"

int Tank:: _nbrTank = 0;

Tank::Tank(QWidget *Fen)
{
    if(_nbrTank == 0){  //Tank J1
        this->posx = aleaTankX()*50;
        this->posy = aleaTankY()*50;
        tankJ1 = new QLabel(Fen);
        tankJ1->setObjectName("tankJ1");
        tankJ1->setGeometry(QRect(this->getPosx(), this->getPosY(), 50, 50));
        tankJ1->setPixmap(QPixmap(":/img/img/TankDroit.png"));
        tankJ1->setScaledContents(true);
        tankJ1->hide();
    }else if(_nbrTank == 1){ //Tank J2
        this->posx = aleaTankX()*50;
        this->posy = aleaTankY()*50;
        tankJ2 = new QLabel(Fen);
        tankJ2->setObjectName("tankJ2");
        tankJ2->setGeometry(QRect(this->getPosx(), this->getPosY(), 50, 50));
        tankJ2->setPixmap(QPixmap(":/img/img/TankGaucheJ2.png"));
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

int Tank::aleaTankX(){
    srand(time(NULL));
    if(_nbrTank == 0){
        return rand()%10;
    }else{
        return rand()%(19-10)+10;
    }
}

int Tank::aleaTankY(){
    srand(time(NULL));
    if(_nbrTank == 0){
        return rand()%5;
    }else{
        return rand()%(9-5)+5;
    }
}

void Tank::avancer(int mouv, int joueur,Tank *tankJoueur, Tank *tankAdverse){ //Ajouter les conditons pour ne pas traverser le tank adverse ou les obstacles
    if(this->getCapacite() > 0){
        //Vers le haut
        if(mouv == 1 && getPosY()>0){
            if((tankJoueur->getPosY()-50 != tankAdverse->getPosY()) || (tankJoueur->getPosx() != tankAdverse->getPosx())){
                this->setPosY(this->getPosY()-50);
                if(joueur == 1){
                    this->tankJ1->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ1->setPixmap(QPixmap(":/img/img/TankHaut.png"));
                }else if(joueur == 2){
                    this->tankJ2->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ2->setPixmap(QPixmap(":/img/img/TankHautJ2.png"));
                }
                this->setCapacite(this->getCapacite()-1);
            }
        }//Vers le bas
        else if(mouv == 2 && getPosY()<450){
            if((tankJoueur->getPosY()+50 != tankAdverse->getPosY()) || (tankJoueur->getPosx() != tankAdverse->getPosx())){
                this->setPosY(this->getPosY()+50);
                if(joueur == 1){
                    this->tankJ1->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ1->setPixmap(QPixmap(":/img/img/TankBas.png"));
                }else if(joueur == 2){
                    this->tankJ2->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ2->setPixmap(QPixmap(":/img/img/TankBasJ2.png"));
                }
                this->setCapacite(this->getCapacite()-1);
            }
        }//Vers la droite
        else if(mouv == 3 && getPosx()<950){
            if((tankJoueur->getPosY() != tankAdverse->getPosY()) || (tankJoueur->getPosx()+50 != tankAdverse->getPosx())){
                this->setPosX(this->getPosx()+50);
                if(joueur == 1){
                    this->tankJ1->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ1->setPixmap(QPixmap(":/img/img/TankDroit.png"));
                }else if(joueur == 2){
                    this->tankJ2->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ2->setPixmap(QPixmap(":/img/img/TankDroitJ2.png"));
                }
                this->setCapacite(this->getCapacite()-1);
            }
        }//Vers la gauche
        else if(mouv == 4 && getPosx()>0){
            if((tankJoueur->getPosY() != tankAdverse->getPosY()) || (tankJoueur->getPosx()-50 != tankAdverse->getPosx())){
                this->setPosX(this->getPosx()-50);
                if(joueur == 1){
                    this->tankJ1->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ1->setPixmap(QPixmap(":/img/img/TankGauche.png"));
                }else if(joueur == 2){
                    this->tankJ2->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                this->tankJ2->setPixmap(QPixmap(":/img/img/TankGaucheJ2.png"));
                }
                this->setCapacite(this->getCapacite()-1);
            }
        }
    }
}

