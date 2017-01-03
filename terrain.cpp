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



    Obs1 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs2 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs3 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs4 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs5 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs6 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs7 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs8 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs9 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs10 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs11 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs12 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs13 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs14 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs15 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs16 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs17 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs18 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs19 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs20 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs21 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs22 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs23 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs24 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs25 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs26 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs27 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs28 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs29 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs30 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs31 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs32 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs33 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs34 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs35 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs36 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs37 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs38 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs39 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs40 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs41 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs42 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs43 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs44 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs45 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs46 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs47 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs48 = new Obstacle(rand()%(3-1+1)+1, Fen);
    Obs49 = new Obstacle(rand()%(3-1+1)+1, Fen);Obs50 = new Obstacle(rand()%(3-1+1)+1, Fen);


}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}


