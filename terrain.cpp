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

    /*
    //Obstacles
    arbre1 = new QLabel(Fen);
    arbre1->setObjectName("arbre1");
    arbre1->setGeometry(QRect(50, 50, 50, 50));
    arbre1->setPixmap(QPixmap(QString("img/arbre.png")));
    arbre1->setScaledContents(true);
    arbre1->hide();

    arbre2 = new QLabel(Fen);
    arbre2->setObjectName("arbre2");
    arbre2->setGeometry(QRect(150, 250, 50, 50));
    arbre2->setPixmap(QPixmap(QString("img/arbre.png")));
    arbre2->setScaledContents(true);
    arbre2->hide();

    arbre3 = new QLabel(Fen);
    arbre3->setObjectName("arbre3");
    arbre3->setGeometry(QRect(250, 450, 50, 50));
    arbre3->setPixmap(QPixmap(QString("img/arbre.png")));
    arbre3->setScaledContents(true);
    arbre3->hide();

    arbre4 = new QLabel(Fen);
    arbre4->setObjectName("arbre4");
    arbre4->setGeometry(QRect(750, 350, 50, 50));
    arbre4->setPixmap(QPixmap(QString("img/arbre.png")));
    arbre4->setScaledContents(true);
    arbre4->hide();

    roche1 = new QLabel(Fen);
    roche1->setObjectName("roche1");
    roche1->setGeometry(QRect(650, 450, 50, 50));
    roche1->setPixmap(QPixmap(QString("img/roche.png")));
    roche1->setScaledContents(true);
    roche1->hide();

    eau1 = new QLabel(Fen);
    eau1->setObjectName("eau1");
    eau1->setGeometry(QRect(250, 250, 50, 50));
    eau1->setPixmap(QPixmap(QString("img/eau.png")));
    eau1->setScaledContents(true);
    eau1->hide();
    */

}

int Terrain::getL()const{
    return this->L;
}

int Terrain::getC()const{
    return this->C;
}
