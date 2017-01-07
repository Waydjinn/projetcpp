#include "fenetre.h"

Fenetre::Fenetre() : QWidget()//Appel du constructeur QWidget
{
    installEventFilter(this); //Permet de récupérer les action (event) dans ce Widget

    //Fenêtre
    setFixedSize(1000, 600);    //Taille de la fenêtre
    auTourDe = 1;               //Le joueur 1 commence
    touche = 0;
    //Titre
    titre = new QLabel("Jeu de Tank - Projet CPP", this); //this->pointeur vers le widget parent
    titre->setGeometry(QRect(250, 30, 550, 150));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred); //Initialisation de la police du Label
    sizePolicy1.setHorizontalStretch(10);
    sizePolicy1.setVerticalStretch(10);
    sizePolicy1.setHeightForWidth(titre->sizePolicy().hasHeightForWidth());
    titre->setSizePolicy(sizePolicy1);
    QFont font;
    font.setPointSize(26);
    font.setBold(true);
    font.setWeight(75);
    titre->setFont(font);

    //Bouton Multijoueur
    bouton1 = new QPushButton("Jouer - Deux joueur", this);
    bouton1->setCursor(Qt::PointingHandCursor);  //Change la forme du curseur quand il passe sur le bouton
    bouton1->setFont(QFont("Arial", 16));    //Choix de la police et taille du bouton
    bouton1->setGeometry(320, 180, 400, 90); //Forme et emplacement du bouton
    bouton1->setFocusPolicy(Qt::NoFocus);

    //Bouton Un joueur
    bouton2 = new QPushButton("Jouer - Un joueur", this);
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

    //Carte de jeu
    terrain = new Terrain(this);

    //Angle vertical canon
    lcd = new QLCDNumber(2, this);
    lcd->setPalette(Qt::black);
    lcd->setGeometry(70,500,50, 50);
    lcd->hide();
    //Angle horizontal canon
    lcdH = new QLCDNumber(3, this);
    lcdH->setPalette(Qt::black);
    lcdH->setGeometry(0,500,50, 50);
    lcdH->hide();

    //Labels
    //Angle Y du canon
    QLabel *angleLabel = new QLabel("Angle tir", this);
    angleLabel->setGeometry(QRect(0, 520, 80, 80));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy2.setHorizontalStretch(6);
    sizePolicy2.setVerticalStretch(6);
    sizePolicy2.setHeightForWidth(angleLabel->sizePolicy().hasHeightForWidth());
    angleLabel->setSizePolicy(sizePolicy2);
    QFont font2;
    font2.setPointSize(10);
    font2.setBold(true);
    font2.setWeight(10);
    angleLabel->setFont(font2);
    angleLabel->hide();

    //Infos
    QLabel *info1 = new QLabel("1 : Obus légés\n2 : Obus moyens\n3 : Obus lourds",this);
    info1->setGeometry(420, 502, 120, 120);
    info1->hide();

    info2 = new QLabel("Joueur 1 - Gagne la partie",this);
    info2->setGeometry(670, 450, 200, 200);
    info2->hide();

    info3 = new QLabel("Joueur 2 - Gagne la partie",this);
    info3->setGeometry(670, 450, 200, 200);
    info3->hide();

    //Viseur
    viseur = new QLabel(this);
    viseur->setGeometry(850, 500, 100, 100);
    viseur->setPixmap(QPixmap(":/img/img/viseur.png"));
    viseur->setScaledContents(true);
    viseur->hide();

    //Changer d'obus
    QLabel *typeObus = new QLabel("Type obus :", this);
    typeObus->setGeometry(420, 502, 90, 30);
    lcdType = new QLCDNumber(1, this);
    lcdType->setPalette(Qt::black);
    lcdType->setGeometry(490,505,25, 25);
    lcdType->display(1);
    lcdType->hide();
    typeObus->hide();

    //Munitions
    QLabel *nbrObus = new QLabel("Munitions :", this);
    nbrObus->setGeometry(520, 502, 90, 30);
    lcdNbrObus = new QLCDNumber(2, this);
    lcdNbrObus->setPalette(Qt::black);
    lcdNbrObus->setGeometry(590,505,25, 25);
    lcdNbrObus->display(99);
    lcdNbrObus->hide();
    nbrObus->hide();

    //Tour de
    QLabel *tour = new QLabel("Au tour de joueur :", this);
    tour->setGeometry(170, 460, 120, 120);
    lcd2 = new QLCDNumber(1, this);
    lcd2->setPalette(Qt::black);
    lcd2->setGeometry(280,505,25,25);
    lcd2->display(this->getAuTourDe());
    tour->hide();
    lcd2->hide();

    //Nbr de déplacement
    QLabel *nbrMouv = new QLabel("Nombre de déplacements restants :", this);
    nbrMouv->setGeometry(170, 450, 210, 210);
    lcd3 = new QLCDNumber(2, this);
    lcd3->setPalette(Qt::black);
    lcd3->setGeometry(375,540,25,25);
    lcd3->display(50);
    nbrMouv->hide();
    lcd3->hide();


    //Nbr de déplacement pour le tour
    QLabel *nbrMouvTour = new QLabel("pour ce tour  :", this);
    nbrMouvTour->setGeometry(170, 490, 180, 180);
    lcd4 = new QLCDNumber(1, this);
    lcd4->setPalette(Qt::black);
    lcd4->setGeometry(255,565,25,25);
    lcd4->display(3);
    nbrMouvTour->hide();
    lcd4->hide();



    //QSlider
    slider1 = new QSlider(Qt::Horizontal,this);
    slider1->setRange(0, 360);
    slider1->setValue(0);
    slider1 -> setGeometry(0,585,100,15);
    slider1->setFocusPolicy(Qt::NoFocus);
    slider1 -> hide();

    slider2 = new QSlider(Qt::Vertical,this);
    slider2 -> setRange(10, 100);
    slider2 -> setValue(10);
    slider2 -> setGeometry(150,510,15,90);
    slider2->setFocusPolicy(Qt::NoFocus);
    slider2 -> hide();

    //tankJ1
    tank1 = new Tank(this, terrain);
    tank1->setCapacite((terrain->getL()/10));

    //tankJ2
    tank2 = new Tank(this, terrain);
    tank2->setCapacite((terrain->getL()/10));

    //Actions
    //Slider 1
    QObject::connect(slider1, SIGNAL(valueChanged(int)), lcdH, SLOT(display(int)));

    //Slider 2
    QObject::connect(slider2, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    //Bouton 1 - Un joueur
    QObject::connect(bouton1, SIGNAL(clicked()), bouton1, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton2, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton3, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), titre, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->carte, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tank1->tankJ1, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tank2->tankJ2, SLOT(show()));
    for(int i=0; i<50; i++){
        QObject::connect(bouton1, SIGNAL(clicked()), this->terrain->listObstacle[i], SLOT(show()));
    }
    QObject::connect(bouton1, SIGNAL(clicked()), slider1, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), slider2, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), angleLabel, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcd, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcdH, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tour, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcd2, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcd3, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcd4, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), nbrMouv, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), nbrMouvTour, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), typeObus, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcdType, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), info1, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), viseur, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), nbrObus, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcdNbrObus, SLOT(show()));


    //Bouton 3 - quitter
    QObject::connect(bouton3, SIGNAL(clicked()), qApp, SLOT(quit()));
    //methode statique de QT, SIGNAL -> macro préprocesseur
    //qApp -> QT créer automatiquement un pointeur qApp qui pointe vers l'objet QApplication créer


}

//Actions clavier
bool Fenetre:: eventFilter(QObject *obj, QEvent *event){
    if(touche == 0){
    if(event->type() == QEvent::KeyRelease){
        QKeyEvent *c = dynamic_cast<QKeyEvent *>(event);

        if(c && c->key() == Qt::Key_Up){
            if(this->getAuTourDe() == 1){
                this->tank1->avancer(1, 1,this->tank1, this->tank2);
                lcd3->display(this->tank1->getCapacite());
                lcd4->display(this->tank1->getNbrMouvTour());
            }else if(this->getAuTourDe() == 2){
                this->tank2->avancer(1, 2,this->tank2, this->tank1);
                lcd3->display(this->tank2->getCapacite());
                lcd4->display(this->tank2->getNbrMouvTour());
            }
        }else if(c && c->key() == Qt::Key_Down){
            if(this->getAuTourDe() == 1){
                this->tank1->avancer(2, 1,this->tank1, this->tank2);
                lcd3->display(this->tank1->getCapacite());
                lcd4->display(this->tank1->getNbrMouvTour());
            }else if(this->getAuTourDe() == 2){
                this->tank2->avancer(2, 2,this->tank2, this->tank1);
                lcd3->display(this->tank2->getCapacite());
                lcd4->display(this->tank2->getNbrMouvTour());
            }
        }else if(c && c->key() == Qt::Key_Right){
            if(this->getAuTourDe() == 1){
                this->tank1->avancer(3, 1,this->tank1, this->tank2);
                lcd3->display(this->tank1->getCapacite());
                lcd4->display(this->tank1->getNbrMouvTour());
            }else if(this->getAuTourDe() == 2){
                this->tank2->avancer(3, 2,this->tank2, this->tank1);
                lcd3->display(this->tank2->getCapacite());
                lcd4->display(this->tank2->getNbrMouvTour());
            }
        }else if(c && c->key() == Qt::Key_Left){
            if(this->getAuTourDe() == 1){
                this->tank1->avancer(4, 1,this->tank1, this->tank2);
                lcd3->display(this->tank1->getCapacite());
                lcd4->display(this->tank1->getNbrMouvTour());
            }else if(this->getAuTourDe() == 2){
                this->tank2->avancer(4, 2,this->tank2, this->tank1);
                lcd3->display(this->tank2->getCapacite());
                lcd4->display(this->tank2->getNbrMouvTour());
            }
        }else if(c && c->key() == Qt::Key_Space){

            if(this->getAuTourDe() == 1){
                this->tank1->tirer(this, this->lcdH->value(), this->lcd->value(), this->tank1);
                this->setAuTourDe(2);   //On passe au tour de l'autre joueur
                this->lcd2->display(this->getAuTourDe());   //On affiche qui jou à ce tour
                lcd3->display(this->tank2->getCapacite());  //On affiche le nbr total de déplacement du joueur actuel
                lcd4->display(this->tank2->getNbrMouvTour());   //On affiche le nbr de mouvement restant pour ce tour (3 max)
                this->tank1->setNbrMouvTour(3); //On remet le nbr de mouvement par tour à 3 pour le prochain tour de ce joueur
                this->lcdType->display(this->tank2->getTypeObusCharg()); //On affiche le type d'obus chargé
                touche = this->tank1->aTouche(this->tank2); //On vérifie si le tank adverse est touché
                if(this->tank2->getTypeObusCharg() == 1){
                    this->lcdType->display(this->tank2->getTypeObusCharg());
                    this->lcdNbrObus->display(99);
                }else if(this->tank2->getTypeObusCharg() == 2){
                    this->lcdType->display(this->tank2->getTypeObusCharg());
                    this->lcdNbrObus->display(this->tank2->getObus2());
                }else if(this->tank2->getTypeObusCharg() == 3){
                    this->lcdType->display(this->tank2->getTypeObusCharg());
                    this->lcdNbrObus->display(this->tank2->getObus3());
                }
            }else if(this->getAuTourDe() == 2){
                this->tank2->tirer(this, this->lcdH->value(), this->lcd->value(), this->tank2);
                this->setAuTourDe(1);
                this->lcd2->display(this->getAuTourDe());
                lcd3->display(this->tank1->getCapacite());
                lcd4->display(this->tank1->getNbrMouvTour());
                this->tank2->setNbrMouvTour(3);
                this->lcdType->display(this->tank1->getTypeObusCharg());
                touche = this->tank2->aTouche(this->tank1);
                if(this->tank1->getTypeObusCharg() == 1){
                    this->lcdType->display(this->tank1->getTypeObusCharg());
                    this->lcdNbrObus->display(99);
                }else if(this->tank1->getTypeObusCharg() == 2){
                    this->lcdType->display(this->tank1->getTypeObusCharg());
                    this->lcdNbrObus->display(this->tank1->getObus2());
                }else if(this->tank1->getTypeObusCharg() == 3){
                    this->lcdType->display(this->tank1->getTypeObusCharg());
                    this->lcdNbrObus->display(this->tank1->getObus3());
                }

            }
            tank1->tankJ1->raise(); //Permet de remettre l'image du tank au premier plan
            tank2->tankJ2->raise(); //Sinon le tank passe sous l'image des impacts d'obus
        }else if(c && c->key() == Qt::Key_Escape){
            this->close();
        }else if(c && c->key() == Qt::Key_C){
            if(this->getAuTourDe() == 1){

                if(this->tank1->getTypeObusCharg() == 1){
                    this->tank1->setTypeObusCharg(2);
                    this->lcdType->display(this->tank1->getTypeObusCharg());
                    this->lcdNbrObus->display(this->tank1->getObus2());
                }else if(this->tank1->getTypeObusCharg() == 2){
                    this->tank1->setTypeObusCharg(3);
                    this->lcdType->display(this->tank1->getTypeObusCharg());
                    this->lcdNbrObus->display(this->tank1->getObus3());
                }else if(this->tank1->getTypeObusCharg() == 3){
                    this->tank1->setTypeObusCharg(1);
                    this->lcdType->display(this->tank1->getTypeObusCharg());
                    this->lcdNbrObus->display(99);
                }

            }else if(this->getAuTourDe() == 2){

                if(this->tank2->getTypeObusCharg() == 1){
                    this->tank2->setTypeObusCharg(2);
                    this->lcdType->display(this->tank2->getTypeObusCharg());
                    this->lcdNbrObus->display(this->tank2->getObus2());
                }else if(this->tank2->getTypeObusCharg() == 2){
                    this->tank2->setTypeObusCharg(3);
                    this->lcdType->display(this->tank2->getTypeObusCharg());
                    this->lcdNbrObus->display(this->tank2->getObus3());
                }else if(this->tank2->getTypeObusCharg() == 3){
                    this->tank2->setTypeObusCharg(1);
                    this->lcdType->display(this->tank2->getTypeObusCharg());
                    this->lcdNbrObus->display(99);
                }
            }
        }
    }
    }else if (touche == 1){
        if(this->getAuTourDe() == 1){
            this->tank1->tankJ1->setPixmap(QPixmap(":/img/img/tankDetruit.png"));
            this->info3->show();
        }else if(this->getAuTourDe() == 2){
            this->tank2->tankJ2->setPixmap(QPixmap(":/img/img/tankDetruit.png"));
            this->info2->show();
        }

    }
    return false;
}

//Fonctions

int Fenetre::getAuTourDe() const{
    return this->auTourDe;
}

void Fenetre::setAuTourDe(int n){
    this->auTourDe = n;
}
