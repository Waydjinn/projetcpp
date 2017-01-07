#include "tank.h"

int Tank:: _nbrTank = 0;
Tank::Tank(QWidget *Fen, Terrain *carte)
{
    carteT = carte;
    if(_nbrTank == 0){  //Tank J1
        this->posx = aleaTankX()*50;
        this->posy = aleaTankY()*50;
        for(int i = 0; i<=20; i++){
            while(_TabPoint[i].getX() == this->getPosx() && _TabPoint[i].getY() == this->getPosY()){
                this->posx = aleaTankX()*50;
                this->posy = aleaTankY()*50;
            }
        }
        tankJ1 = new QLabel(Fen);
        tankJ1->setObjectName("tankJ1");
        tankJ1->setGeometry(QRect(this->getPosx(), this->getPosY(), 50, 50));
        tankJ1->setPixmap(QPixmap(":/img/img/TankDroit.png"));
        tankJ1->setScaledContents(true);
        tankJ1->hide();
    }else if(_nbrTank == 1){ //Tank J2
        this->posx = aleaTankX()*50;
        this->posy = aleaTankY()*50;
        for(int i = 0; i<=20; i++){
            while(_TabPoint[i].getX() == this->getPosx() && _TabPoint[i].getY() == this->getPosY()){
                this->posx = aleaTankX()*50;
                this->posy = aleaTankY()*50;
            }
        }
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
    this->nbrMouvTour = 3;
    this->typeObusCharg = 1; //on initialise le type d'obus chargé au type 1 (obus1)
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

int Tank::getNbrMouvTour() const{
    return this->nbrMouvTour;
}

int Tank::getTypeObusCharg() const{
    return this->typeObusCharg;
}


//Setters

void Tank::setTypeObusCharg(int n){
    this->typeObusCharg = n;
}

void Tank::setNbrMouvTour(int n){
    this->nbrMouvTour = n;
}

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
    if(_nbrTank == 0){
        return rand()%10;
    }else{
        return rand()%(19-10)+10;
    }
}

int Tank::aleaTankY(){
    if(_nbrTank == 0){
        return rand()%5;
    }else{
        return rand()%(9-5)+5;
    }
}

void Tank::avancer(int mouv, int joueur,Tank *tankJoueur, Tank *tankAdverse){ //Ajouter les conditons pour ne pas traverser le tank adverse ou les obstacles
    int bouge = 0;
    if(this->getCapacite() > 0){
        if(this->getNbrMouvTour() > 0){
        //Vers le haut
        if(verif(tankJoueur, mouv) == 0){
        if(mouv == 1 && getPosY()>0){
            if((tankJoueur->getPosY()-50 != tankAdverse->getPosY()) || (tankJoueur->getPosx() != tankAdverse->getPosx())){
                for(int i = 0; i < _nbrImpacts; i++){
                    if(_TabImpacts[i].getX() == tankJoueur->getPosx() && _TabImpacts[i].getY() == tankJoueur->getPosY() ){
                        this->setCapacite(this->getCapacite()-2);
                        this->setNbrMouvTour(this->getNbrMouvTour()-2);
                        bouge = 1;
                    }
                }
                if(bouge == 0){
                    this->setCapacite(this->getCapacite()-1);
                    this->setNbrMouvTour(this->getNbrMouvTour()-1);
                }
                this->setPosY(this->getPosY()-50);
                if(joueur == 1){
                    this->tankJ1->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ1->setPixmap(QPixmap(":/img/img/TankHaut.png"));
                }else if(joueur == 2){
                    this->tankJ2->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ2->setPixmap(QPixmap(":/img/img/TankHautJ2.png"));
                }

            }
        }//Vers le bas
        else if(mouv == 2 && getPosY()<450){
            if((tankJoueur->getPosY()+50 != tankAdverse->getPosY()) || (tankJoueur->getPosx() != tankAdverse->getPosx())){
                for(int i = 0; i < _nbrImpacts; i++){
                    if(_TabImpacts[i].getX() == tankJoueur->getPosx() && _TabImpacts[i].getY() == tankJoueur->getPosY() ){
                        this->setCapacite(this->getCapacite()-2);
                        this->setNbrMouvTour(this->getNbrMouvTour()-2);
                        bouge = 1;
                    }
                }
                if(bouge == 0){
                    this->setCapacite(this->getCapacite()-1);
                    this->setNbrMouvTour(this->getNbrMouvTour()-1);
                }
                this->setPosY(this->getPosY()+50);
                if(joueur == 1){
                    this->tankJ1->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ1->setPixmap(QPixmap(":/img/img/TankBas.png"));
                }else if(joueur == 2){
                    this->tankJ2->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ2->setPixmap(QPixmap(":/img/img/TankBasJ2.png"));
                }
            }
        }//Vers la droite
        else if(mouv == 3 && getPosx()<950){
            if((tankJoueur->getPosY() != tankAdverse->getPosY()) || (tankJoueur->getPosx()+50 != tankAdverse->getPosx())){
                for(int i = 0; i < _nbrImpacts; i++){
                    if(_TabImpacts[i].getX() == tankJoueur->getPosx() && _TabImpacts[i].getY() == tankJoueur->getPosY() ){
                        this->setCapacite(this->getCapacite()-2);
                        this->setNbrMouvTour(this->getNbrMouvTour()-2);
                        bouge = 1;
                    }
                }
                if(bouge == 0){
                    this->setCapacite(this->getCapacite()-1);
                    this->setNbrMouvTour(this->getNbrMouvTour()-1);
                }
                this->setPosX(this->getPosx()+50);
                if(joueur == 1){
                    this->tankJ1->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ1->setPixmap(QPixmap(":/img/img/TankDroit.png"));
                }else if(joueur == 2){
                    this->tankJ2->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ2->setPixmap(QPixmap(":/img/img/TankDroitJ2.png"));
                }
            }
        }//Vers la gauche
        else if(mouv == 4 && getPosx()>0){
            if((tankJoueur->getPosY() != tankAdverse->getPosY()) || (tankJoueur->getPosx()-50 != tankAdverse->getPosx())){
                for(int i = 0; i < _nbrImpacts; i++){
                    if(_TabImpacts[i].getX() == tankJoueur->getPosx() && _TabImpacts[i].getY() == tankJoueur->getPosY() ){
                        this->setCapacite(this->getCapacite()-2);
                        this->setNbrMouvTour(this->getNbrMouvTour()-2);
                        bouge = 1;
                    }
                }
                if(bouge == 0){
                    this->setCapacite(this->getCapacite()-1);
                    this->setNbrMouvTour(this->getNbrMouvTour()-1);
                }
                this->setPosX(this->getPosx()-50);
                if(joueur == 1){
                    this->tankJ1->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                    this->tankJ1->setPixmap(QPixmap(":/img/img/TankGauche.png"));
                }else if(joueur == 2){
                    this->tankJ2->setGeometry(this->getPosx(), this->getPosY(), 50, 50);
                this->tankJ2->setPixmap(QPixmap(":/img/img/TankGaucheJ2.png"));
                }
            }
        }
        }
    }
    }
}

void Tank:: tirer(QWidget *Fen, int angle, int force, Tank *tankJoueur){
    if(force == 0){
        force = 10;
    }
    int effet;

    if(angle >= 0 && angle <= 30){ //gauche
        effet = tireEffet(tankJoueur, tankJoueur->getPosx()-((force/10)*50), tankJoueur->getPosY());
        if( effet == 1){
            listImpacts << new Obstacle(Fen, tankJoueur->getPosx()-((force/10)*50), tankJoueur->getPosY(), tankJoueur->getTypeObusCharg());
        }
    }else if(angle >= 31 && angle <= 60){ //diagonal haut gauche
        effet = tireEffet(tankJoueur, tankJoueur->getPosx()-((force/10)*50), tankJoueur->getPosY()-((force/10)*50));
        if( effet == 1){
            listImpacts << new Obstacle(Fen, tankJoueur->getPosx()-((force/10)*50), tankJoueur->getPosY()-((force/10)*50), tankJoueur->getTypeObusCharg());
        }
    }else if(angle >= 61 && angle <= 120){ //haut
        effet = tireEffet(tankJoueur, tankJoueur->getPosx(), tankJoueur->getPosY()-((force/10)*50));
        if( effet == 1){
            listImpacts << new Obstacle(Fen, tankJoueur->getPosx(), tankJoueur->getPosY()-((force/10)*50), tankJoueur->getTypeObusCharg());
        }
    }else if(angle >= 121 && angle <= 150){ //diagonale haut droit
        effet = tireEffet(tankJoueur, tankJoueur->getPosx()+((force/10)*50), tankJoueur->getPosY()-((force/10)*50));
        if( effet == 1){
            listImpacts << new Obstacle(Fen, tankJoueur->getPosx()+((force/10)*50), tankJoueur->getPosY()-((force/10)*50), tankJoueur->getTypeObusCharg());
        }
    }else if(angle >= 151 && angle <= 210){ //droite
        effet = tireEffet(tankJoueur, tankJoueur->getPosx()+((force/10)*50), tankJoueur->getPosY());
        if( effet == 1){
            listImpacts << new Obstacle(Fen, tankJoueur->getPosx()+((force/10)*50), tankJoueur->getPosY(), tankJoueur->getTypeObusCharg());
        }
    }else if(angle >= 211 && angle <= 240){ //diagonale bas droite
        effet = tireEffet(tankJoueur, tankJoueur->getPosx()+((force/10)*50), tankJoueur->getPosY()+((force/10)*50));
        if( effet == 1){
            if(tankJoueur->getPosx()+((force/10)*50) < 900 && tankJoueur->getPosY()+((force/10)*50) < 500){     //Evite l'affichage des impacts hors de la map
                listImpacts << new Obstacle(Fen, tankJoueur->getPosx()+((force/10)*50), tankJoueur->getPosY()+((force/10)*50), tankJoueur->getTypeObusCharg());
            }
        }
    }else if(angle >= 241 && angle <= 300){ //bas
        effet = tireEffet(tankJoueur, tankJoueur->getPosx(), tankJoueur->getPosY()+((force/10)*50));
        if( effet == 1){
            if(tankJoueur->getPosx() < 900 && tankJoueur->getPosY()+((force/10)*50) < 500){
                listImpacts << new Obstacle(Fen, tankJoueur->getPosx(), tankJoueur->getPosY()+((force/10)*50), tankJoueur->getTypeObusCharg());
            }
        }
    }else if(angle >= 301 && angle <= 330){ //diagonale bas gauche
        effet = tireEffet(tankJoueur, tankJoueur->getPosx()-((force/10)*50), tankJoueur->getPosY()+((force/10)*50));
        if( effet == 1){
            if(tankJoueur->getPosx()-((force/10)*50) < 900 && tankJoueur->getPosY()+((force/10)*50) < 500){
                listImpacts << new Obstacle(Fen, tankJoueur->getPosx()-((force/10)*50), tankJoueur->getPosY()+((force/10)*50), tankJoueur->getTypeObusCharg());
            }
        }
    }else if(angle >= 331 && angle <= 360){ //gauche
        effet = tireEffet(tankJoueur, tankJoueur->getPosx()-((force/10)*50), tankJoueur->getPosY());
        if( effet == 1){
            listImpacts << new Obstacle(Fen, tankJoueur->getPosx()-((force/10)*50), tankJoueur->getPosY(), tankJoueur->getTypeObusCharg());
        }
    }
}

int Tank::aTouche(Tank *tankAdverse){
    int res = 0;
    int j = _nbrImpacts-1;
    if(_TabImpacts[j].getX() == tankAdverse->getPosx() && _TabImpacts[j].getY() == tankAdverse->getPosY()){
        res = 1;
    }
    return res;
}

int Tank::tireEffet(Tank *tankJoueur,int posTirX, int posTirY){
    int res = 1;
    for(int i = 0; i < _nbrObstacle; i++){
        if(_TabPoint[i].getX() == posTirX && _TabPoint[i].getY() == posTirY){
            if(tankJoueur->carteT->listObstacle[i]->getType() == 2){
                res = 0;
                if(tankJoueur->getTypeObusCharg() == 1){
                    tankJoueur->carteT->listObstacle[i]->setVie(tankJoueur->carteT->listObstacle[i]->getVie()-2);
                }else if(tankJoueur->getTypeObusCharg() == 2){
                    tankJoueur->carteT->listObstacle[i]->setVie(tankJoueur->carteT->listObstacle[i]->getVie()-5);
                }else if(tankJoueur->getTypeObusCharg() == 3){
                    tankJoueur->carteT->listObstacle[i]->setVie(tankJoueur->carteT->listObstacle[i]->getVie()-10);
                }
                if(tankJoueur->carteT->listObstacle[i]->getVie() < 7){
                    tankJoueur->carteT->listObstacle[i]->setPixmap(QPixmap(":/img/img/roche2.png"));
                }
                if(tankJoueur->carteT->listObstacle[i]->getVie() < 1){
                    _TabPoint[i].setX(-1);
                    _TabPoint[i].setY(-1);
                    res = 1;
                }
            }else if(tankJoueur->carteT->listObstacle[i]->getType() == 3){
                res = 0;
            }else{//Tire sur arbre on supprime l'obstacle (1 vie)
                _TabPoint[i].setX(-1);
                _TabPoint[i].setY(-1);
            }
        }
    }
    return res;
}

int Tank::verif(Tank *tankJoueur, int mouv){
    for(int i = 0; i < _nbrObstacle; i++){
        if(mouv == 1){
            if(_TabPoint[i].getX() == tankJoueur->getPosx() && _TabPoint[i].getY() == tankJoueur->getPosY()-50){
                return 1;
            }
        }else if(mouv == 2){
            if(_TabPoint[i].getX() == tankJoueur->getPosx() && _TabPoint[i].getY() == tankJoueur->getPosY()+50){
                return 1;
            }
        }else if(mouv == 3){
            if(_TabPoint[i].getX() == tankJoueur->getPosx()+50 && _TabPoint[i].getY() == tankJoueur->getPosY()){
                return 1;
            }
        }else if(mouv == 4){
            if(_TabPoint[i].getX() == tankJoueur->getPosx()-50 && _TabPoint[i].getY() == tankJoueur->getPosY()){
                return 1;
            }
        }

    }
    return 0;
}

