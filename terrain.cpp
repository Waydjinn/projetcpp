#include "terrain.h"

Terrain::Terrain(QWidget *Fen)
{
    this->C = 950;
    this->L = 500;
    carte = new QLabel(Fen);
    carte->setObjectName("map");
    carte->setGeometry(QRect(0, 0, this->getC(), this->getL()));
    carte->setPixmap(QPixmap(QString("img/map.png")));
    carte->hide();
}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}
