#include "fenetre.h"

Fenetre::Fenetre() : QWidget()//Appel du constructeur QWidget
{
    installEventFilter(this);
    auTourDe = 1;
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
    bouton1->setFocusPolicy(Qt::NoFocus);

    //Bouton Multijoueur
    bouton2 = new QPushButton("Jouer - Deux joueur", this);
    bouton2->setCursor(Qt::PointingHandCursor);
    bouton2->setFont(QFont("Arial", 16));
    bouton2->setGeometry(320, 280, 400, 90);
    bouton2->setFocusPolicy(Qt::NoFocus);

    //Bouton Quitter
    bouton3 = new QPushButton("Quitter", this);
    bouton3->setCursor(Qt::PointingHandCursor);
    bouton3->setFocusPolicy(Qt::NoFocus);
    bouton3->setFont(QFont("Arial", 16));
    bouton3->setGeometry(320, 380, 400, 90);
    bouton3->setToolTip("Arrêt de l'application");
    //->setFocusPolicy(Qt::NoFocus);

    //Carte de jeu
    terrain = new Terrain(this);

    //tankJ1
    tank1 = new Tank(this);
    tank1->setCapacite((terrain->getL()/10));

    //tankJ2
    tank2 = new Tank(this);
    tank2->setCapacite((terrain->getL()/10));

    //Actions
    //Bouton 1 - Un joueur
    QObject::connect(bouton1, SIGNAL(clicked()), bouton1, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton2, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton3, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), titre, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->carte, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tank1->tankJ1, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tank2->tankJ2, SLOT(show()));


    //Bouton 2 - Deux joueurs
    QObject::connect(bouton2, SIGNAL(clicked()), bouton1, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), bouton2, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), bouton3, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), titre, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->carte, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), tank1->tankJ1, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), tank2->tankJ2, SLOT(show()));

    //Bouton 3 - quitter
    QObject::connect(bouton3, SIGNAL(clicked()), qApp, SLOT(quit()));
    //methode statique de QT, SIGNAL -> macro préprocesseur
    //qApp -> QT créer automatiquement un pointeur qApp qui pointe vers l'objet QApplication créer


}


//Actions clavier
bool Fenetre:: eventFilter(QObject *obj, QEvent *event){
    if(event->type() == QEvent::KeyRelease){
        QKeyEvent *c = dynamic_cast<QKeyEvent *>(event);
        if(c && c->key() == Qt::Key_Up){
            if(this->getAuTourDe() == 1){
                this->tank1->avancer(1, 1,this->tank1, this->tank2);
            }else if(this->getAuTourDe() == 2){
                this->tank2->avancer(1, 2,this->tank2, this->tank1);
            }
        }else if(c && c->key() == Qt::Key_Down){
            if(this->getAuTourDe() == 1){
                this->tank1->avancer(2, 1,this->tank1, this->tank2);
            }else if(this->getAuTourDe() == 2){
                this->tank2->avancer(2, 2,this->tank2, this->tank1);
            }
        }else if(c && c->key() == Qt::Key_Right){
            if(this->getAuTourDe() == 1){
                this->tank1->avancer(3, 1,this->tank1, this->tank2);
            }else if(this->getAuTourDe() == 2){
                this->tank2->avancer(3, 2,this->tank2, this->tank1);
            }
        }else if(c && c->key() == Qt::Key_Left){
            if(this->getAuTourDe() == 1){
                this->tank1->avancer(4, 1,this->tank1, this->tank2);
            }else if(this->getAuTourDe() == 2){
                this->tank2->avancer(4, 2,this->tank2, this->tank1);
            }
        }else if(c && c->key() == Qt::Key_Space){
            if(this->getAuTourDe() == 1){
                this->setAuTourDe(2);
            }else if(this->getAuTourDe() == 2){
                this->setAuTourDe(1);
            }
        }
    }
    return false;
}

int Fenetre::getAuTourDe() const{
    return this->auTourDe;
}

void Fenetre::setAuTourDe(int n){
    this->auTourDe = n;
}
