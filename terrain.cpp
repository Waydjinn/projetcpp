#include "terrain.h"

Terrain::Terrain(QWidget *Fen)
{

    this->C = 970;
    this->L = 480;
    carte = new QLabel(Fen);
    carte->setObjectName("map");
    carte->setGeometry(QRect(10, 10, this->getC(), this->getL()));
    carte->setPixmap(QPixmap(QString("img/map.png")));
    carte->hide();
}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}
