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
        tankJ1->setPixmap(QPixmap(QString("img/TankDroit.png"))); //tank1->getImage()
        tankJ1->setScaledContents(true);
        tankJ1->hide();
    }else if(_nbrTank == 1){ //Tank J2
        this->posx = aleaTankX()*50;
        this->posy = aleaTankY()*50;
        tankJ2 = new QLabel(Fen);
        tankJ2->setObjectName("tankJ2");
        tankJ2->setGeometry(QRect(this->getPosx(), this->getPosY(), 50, 50));
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

int Tank::avancer(int mouv){ //Ajouter les conditons pour ne pas traverser le tank adverse ou les obstacles
    int aBouge = 0;
    //Vers le haut
    if(mouv == 1 && getPosY()>0){
        this->setPosX(this->getPosx());
        this->setPosY(this->getPosY()-50);
        aBouge = 1;
    }//Vers le bas
    else if(mouv == 2 && getPosY()<450){
        this->setPosX(this->getPosx());
        this->setPosY(this->getPosY()+50);
        aBouge = 1;
    }//Vers la droite
    else if(mouv == 3 && getPosx()<950){
        this->setPosX(this->getPosx()+50);
        this->setPosY(this->getPosY());
        aBouge = 1;
    }//Vers la gauche
    else if(mouv == 4 && getPosx()>0){
        this->setPosX(this->getPosx()-50);
        this->setPosY(this->getPosY());
        aBouge = 1;
    }
    return aBouge;
}


void Tank::keyPressEvent ()
{
    int c = 0;
    while(1){
        c = 0;

        switch((c=getch())){
        case KEY_UP:
            cout << endl << "Up" << endl;//key up
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            break;
        case KEY_LEFT:
            cout << endl << "Left" << endl;  // key left
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;  // key right
            break;
        default:
            cout << endl << "null" << endl;  // not arrow
            break;
        }
    }    
}
