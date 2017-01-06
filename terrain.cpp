#include "terrain.h"

Terrain::Terrain(QWidget *Fen)
{
    this->C = 1000;
    this->L = 500;
    carte = new QLabel(Fen);
    carte->setObjectName("carte");
    carte->setGeometry(QRect(0, 0, this->getC(), this->getL()));
    carte->setPixmap(QPixmap(":/img/img/map.png"));
    carte->setScaledContents(true);
    carte->hide();
    srand(time(NULL));


    for(int i=0; i < 50; i++){
        listObstacle << new Obstacle(Fen);
    }
}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}


