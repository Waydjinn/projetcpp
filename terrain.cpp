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

    /*
    Obstacle *Obs;
    for(int i=0; i < 50; i++){
        Obs[i] = new Obstacle(Fen);
    }
    */


    Obs1 = new Obstacle(Fen);Obs2 = new Obstacle(Fen);
    Obs3 = new Obstacle(Fen);Obs4 = new Obstacle(Fen);
    Obs5 = new Obstacle(Fen);Obs6 = new Obstacle(Fen);
    Obs7 = new Obstacle(Fen);Obs8 = new Obstacle(Fen);
    Obs9 = new Obstacle(Fen);Obs10 = new Obstacle(Fen);
    Obs11 = new Obstacle(Fen);Obs12 = new Obstacle(Fen);
    Obs13 = new Obstacle(Fen);Obs14 = new Obstacle(Fen);
    Obs15 = new Obstacle(Fen);Obs16 = new Obstacle(Fen);
    Obs17 = new Obstacle(Fen);Obs18 = new Obstacle(Fen);
    Obs19 = new Obstacle(Fen);Obs20 = new Obstacle(Fen);
    Obs21 = new Obstacle(Fen);Obs22 = new Obstacle(Fen);
    Obs23 = new Obstacle(Fen);Obs24 = new Obstacle(Fen);
    Obs25 = new Obstacle(Fen);Obs26 = new Obstacle(Fen);
    Obs27 = new Obstacle(Fen);Obs28 = new Obstacle(Fen);
    Obs29 = new Obstacle(Fen);Obs30 = new Obstacle(Fen);
    Obs31 = new Obstacle(Fen);Obs32 = new Obstacle(Fen);
    Obs33 = new Obstacle(Fen);Obs34 = new Obstacle(Fen);
    Obs35 = new Obstacle(Fen);Obs36 = new Obstacle(Fen);
    Obs37 = new Obstacle(Fen);Obs38 = new Obstacle(Fen);
    Obs39 = new Obstacle(Fen);Obs40 = new Obstacle(Fen);
    Obs41 = new Obstacle(Fen);Obs42 = new Obstacle(Fen);
    Obs43 = new Obstacle(Fen);Obs44 = new Obstacle(Fen);
    Obs45 = new Obstacle(Fen);Obs46 = new Obstacle(Fen);
    Obs47 = new Obstacle(Fen);Obs48 = new Obstacle(Fen);
    Obs49 = new Obstacle(Fen);Obs50 = new Obstacle(Fen);


}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}


