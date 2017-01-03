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
    Obs1 = new Obstacle(rand()%(3-1)+1, Fen);
    Obs2 = new Obstacle(rand()%(3-1)+1, Fen);
    /*Obs3 = new Obstacle(1, Fen);
    Obs4 = new Obstacle(1, Fen);
    Obs5 = new Obstacle(1, Fen);
    Obs6 = new Obstacle(1, Fen);
    Obs7 = new Obstacle(1, Fen);
    Obs8 = new Obstacle(1, Fen);
    Obs9 = new Obstacle(1, Fen);
    Obs10 = new Obstacle(2, Fen);
    Obs11 = new Obstacle(2, Fen);
    Obs12 = new Obstacle(2, Fen);
    Obs13 = new Obstacle(2, Fen);
    Obs14 = new Obstacle(2, Fen);
    Obs15 = new Obstacle(2, Fen);
    Obs16 = new Obstacle(2, Fen);
    Obs17 = new Obstacle(3, Fen);
    Obs18 = new Obstacle(3, Fen);
    Obs19 = new Obstacle(3, Fen);
    Obs20 = new Obstacle(3, Fen);*/

}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}


