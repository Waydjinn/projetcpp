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

    //Carte de jeu
    terrain = new Terrain(this);

    //QLCDNumber
    QLCDNumber *lcd = new QLCDNumber(2, this);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setGeometry(0,500,50, 50);
    lcd->hide();
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

    //Tour de
    QLabel *tour = new QLabel("Au tour de joueur :", this);
    tour->setGeometry(170, 460, 120, 120);
    lcd2 = new QLCDNumber(1, this);
    lcd2->setSegmentStyle(QLCDNumber::Filled);
    lcd2->setGeometry(280,505,25,25);
    lcd2->display(this->getAuTourDe());
    tour->hide();
    lcd2->hide();


    //QSlider

    QSlider * slider1 = new QSlider(Qt::Horizontal,this);
    slider1->setRange(0, 360);
    slider1->setValue(0);
    slider1 -> setGeometry(0,585,100,15);
    slider1 -> hide();

    QSlider * slider2 = new QSlider(Qt::Vertical,this);
    slider2 -> setRange(0, 90);
    slider2 -> setValue(0);
    slider2 -> setGeometry(150,510,15,90);
    slider2 -> hide();


    //Canon
    angleCanon = slider1->value();



    //tankJ1
    tank1 = new Tank(this);
    tank1->setCapacite((terrain->getL()/10));

    //tankJ2
    tank2 = new Tank(this);
    tank2->setCapacite((terrain->getL()/10));

    //Actions

    //Slider 2
    QObject::connect(slider2, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    //Bouton 1 - Un joueur

    QObject::connect(bouton1, SIGNAL(clicked()), bouton1, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton2, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), bouton3, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), titre, SLOT(hide()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->carte, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->fond, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tank1->tankJ1, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tank2->tankJ2, SLOT(show()));

    /*
    for(int i=0; i<50; i++){
        QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs[i], SLOT(show()));
    }
    */

    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs1, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs2, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs3, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs4, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs5, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs6, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs7, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs8, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs9, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs10, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs11, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs12, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs13, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs14, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs15, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs16, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs17, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs18, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs19, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs20, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs21, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs22, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs23, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs24, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs25, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs26, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs27, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs28, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs29, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs30, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs31, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs32, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs33, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs34, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs35, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs36, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs37, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs38, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs39, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs40, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs41, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs42, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs43, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs44, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs45, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs46, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs47, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs48, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs49, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), terrain->Obs50, SLOT(show()));

    QObject::connect(bouton1, SIGNAL(clicked()), slider1, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), slider2, SLOT(show()));

    QObject::connect(bouton1, SIGNAL(clicked()), angleLabel, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcd, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), tour, SLOT(show()));
    QObject::connect(bouton1, SIGNAL(clicked()), lcd2, SLOT(show()));





    //Bouton 2 - Deux joueurs
    QObject::connect(bouton2, SIGNAL(clicked()), bouton1, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), bouton2, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), bouton3, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), titre, SLOT(hide()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->carte, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), tank1->tankJ1, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), tank2->tankJ2, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs1, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs2, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs3, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs4, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs5, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs6, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs7, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs8, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs9, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs10, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs11, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs12, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs13, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs14, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs15, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs16, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs17, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs18, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs19, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs20, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs21, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs22, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs23, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs24, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs25, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs26, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs27, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs28, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs29, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs30, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs31, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs32, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs33, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs34, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs35, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs36, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs37, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs38, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs39, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs40, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs41, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs42, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs43, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs44, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs45, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs46, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs47, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs48, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs49, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), terrain->Obs50, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), slider1, SLOT(show()));
    QObject::connect(bouton2, SIGNAL(clicked()), slider2, SLOT(show()));

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
                this->lcd2->display(this->getAuTourDe());
            }else if(this->getAuTourDe() == 2){
                this->setAuTourDe(1);
                this->lcd2->display(this->getAuTourDe());
            }
        }else if(c && c->key() == Qt::Key_Escape){
            this->close();
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

void Fenetre::paintEvent(QPaintEvent *event){

    QPainter painter(this);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter.setPen(pen);

    //painter.drawLine(110, 520, 110, 540);
    //painter.translate(0, height());
    painter.rotate(angleCanon);
    painter.drawRect(QRect(110, 550, 20, 0));


}
