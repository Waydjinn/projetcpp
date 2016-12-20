#include "fenetre.h"
#include "terrain.h"

Fenetre::Fenetre() : QWidget()//Appel du constructeur QWidget
{
    //Fenêtre
    setFixedSize(1000, 600);    //Taille de la fenêtre
    //Titre
    titre = new QLabel("Jeu de Tank - Projet CPP", this); //this->pointeur vers le widget parent
    titre->setGeometry(QRect(250, 30, 550, 150));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(10);
    sizePolicy1.setVerticalStretch(10);
    sizePolicy1.setHeightForWidth(titre->sizePolicy().hasHeightForWidth());
    titre->setSizePolicy(sizePolicy1);
    QFont font;
    font.setPointSize(26);
    font.setBold(true);
    font.setWeight(75);
    titre->setFont(font);
    //Bouton Un joueur
    bouton1 = new QPushButton("Jouer - Un joueur", this);
    bouton1->setCursor(Qt::PointingHandCursor);  //Change la forme du curseur quand il passe sur le bouton
    bouton1->setFont(QFont("Arial", 16));    //Choix de la police et taille du bouton
    bouton1->setGeometry(320, 180, 400, 90); //Forme et emplacement du bouton
    //QObject::connect(bouton1, SIGNAL(clicked()), qApp, SLOT(hide()));
    //Bouton Multijoueur
    bouton2 = new QPushButton("Jouer - Deux joueur", this);
    bouton2->setCursor(Qt::PointingHandCursor);
    bouton2->setFont(QFont("Arial", 16));
    bouton2->setGeometry(320, 280, 400, 90);
    //Bouton Quitter
    bouton3 = new QPushButton("Quitter", this);
    bouton3->setCursor(Qt::PointingHandCursor);
    bouton3->setFont(QFont("Arial", 16));
    bouton3->setGeometry(320, 380, 400, 90);
    bouton3->setToolTip("Arrêt de l'application");
    QObject::connect(bouton3, SIGNAL(clicked()), qApp, SLOT(quit())); //methode statique de QT, SIGNAL -> marco préprocesseur
    //qApp -> QT créer automatiquement un pointeur qApp qui pointe vers l'objet QApplication créer
}
