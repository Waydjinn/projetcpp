#include "fenetre.h"

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
    //Boutton Retour menu
    bouton4 = new QPushButton("Retour menu", this);
    bouton4->setCursor(Qt::PointingHandCursor);
    bouton4->setFont(QFont("Arial", 16));
    bouton4->setGeometry(790, 530, 200, 60);
    bouton4->hide();

    //Carte de jeu
    map = new QLabel(this);
    map->setObjectName("map");
    map->setGeometry(QRect(10, 10, 980, 510));
    map->setPixmap(QPixmap(QString("img/map.png")));
    map->hide();

    //tankJ1
    tankJ1 = new QLabel(this);
    tankJ1->setObjectName("tankJ1");
    tankJ1->setGeometry(QRect(10, 10, 40, 40));
    tankJ1->setPixmap(QPixmap(QString("img/TankDroit.png")));
    tankJ1->setScaledContents(true);
    tankJ1->hide();

    //tankJ2
    tankJ2 = new QLabel(this);
    tankJ2->setObjectName("tankJ2");
    tankJ2->setGeometry(QRect(950, 480, 40, 40));
    tankJ2->setPixmap(QPixmap(QString("img/TankGaucheJ2.png")));
    tankJ2->setScaledContents(true);
    tankJ2->hide();


    //Actions
    //Bouton 1
    QObject::connect(bouton1, SIGNAL(clicked()), bouton1, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton2, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton3, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), titre, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton4, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), map, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tankJ1, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tankJ2, SLOT(show()));
    //Bouton 2
    QObject::connect(bouton2, SIGNAL(clicked()), bouton1, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), bouton2, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), bouton3, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), titre, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), bouton4, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), map, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), tankJ1, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), tankJ2, SLOT(show()));
    //Bouton 3
    QObject::connect(bouton3, SIGNAL(clicked()), qApp, SLOT(quit())); //methode statique de QT, SIGNAL -> marco préprocesseur
    //qApp -> QT créer automatiquement un pointeur qApp qui pointe vers l'objet QApplication créer
    //Bouton 4
    QObject::connect(bouton4, SIGNAL(clicked()), bouton1, SLOT(show()));
    QObject::connect(bouton4, SIGNAL(clicked()), bouton2, SLOT(show()));
    QObject::connect(bouton4, SIGNAL(clicked()), bouton3, SLOT(show()));
    QObject::connect(bouton4, SIGNAL(clicked()), titre, SLOT(show()));
    QObject::connect(bouton4, SIGNAL(clicked()), bouton4, SLOT(hide()));
    QObject::connect(bouton4, SIGNAL(clicked()), map, SLOT(hide()));
    QObject::connect(bouton4, SIGNAL(clicked()), tankJ1, SLOT(hide()));
    QObject::connect(bouton4, SIGNAL(clicked()), tankJ2, SLOT(hide()));
}
