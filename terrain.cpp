#include "terrain.h"

Terrain::Terrain() : QWidget()
{

    this->C = 1000;
    this->L = 600;

    setFixedSize(C, L);

    boutonR1 = new QPushButton("Retour menu", this);
    boutonR1->setCursor(Qt::PointingHandCursor);
    boutonR1->setFont(QFont("Arial", 16));
    boutonR1->setGeometry(620, 400, 300, 90);
    QObject::connect(boutonR1, SIGNAL(clicked()), this, SLOT(hide()));
}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}
