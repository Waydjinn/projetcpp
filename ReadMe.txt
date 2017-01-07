PROJET CPP - JEU DE TANK

SEGMENT :

La classe Segment fait en TD.

POINT :

La classe Point fait en TD.

OBSTACLE :

La classe Obstacle, inclue la classe point.
Elle est constitué de: 
    Obstacle() constructeur par défauts qui crée un objet vide.

    Obstacle(QWidget *Fen) constructeur pour les obstacles arbres, rochers, eau. Dans ce constructeur on attribue un type aléatoire à l'obstacle (entre 1 et 3) qui déterminra si l'obstacle est un arbre (1) un rocher (2) ou de l'eau (3) et on initialise les attributs (vie, posX, posY, type) de l'obstacle en fonction de son type. On stock alors la position de l'obstacle crée dans un tableau de Point _TabPoint qui est une variable globale de la classe Obstacle et ses classes dérivées. A chaque création d'obstacle on incrémente une variable globale _nbrObstacle. 
    Lorsque l'on place un Obstacle on vérifie s'il n'y a pas déjà d'obstacle à cette position, si c'est le cas on donne de nouvel coordonnées x y pour placer l'obstacle actuel.

    Obstacle(QWidget *Fen, int x, int y, int typeO) le constructeur pour les obstacle de type impact, qui ont un fonctionnement différent que les autres obstacles (franchissables si assez de point de mouvement disponible). On stock alors la posisition des impact crée dans un tableau globale _TabImpacts et on garde un compteur globale _nbrImpacts à jour. 

    Les getters et setters pour les attributs de l'objet.

    Les fonctions int aleaObsX(int a, int b) et int aleaObsY(int a, int b) qui permettent de donner des positions aléatoires au obstacles sur la carte.

    La fonction int chercherObs(Point *Tab, int x, int y) qui vérifie si un obstacle éxiste à la position (x,y) d'un tableau de point.


TERRAIN :

La class Terrain, inclue la classe obstacle. Elle est composé d'un constructeur qui :
    Crée un objet Terrain avec un pointeur QWidget  en paramètre, pour rattacher le label du terrain à la fenêtre principale.
    On initialise le terrain à une largeur C = 1000 et longueur L = 500, et on crée un Label, dans lequel on met une image, qui servira a afficher la carte sur le QWidget donné en paramètre.
    On crée également 50 objets Obstacle qui représentent les abres, rochers et zone d'eau de la carte. On stock ces objets Obstacle dans une QListe<Obstacle *> listObstacle.

    Les getters et setters pour les attributs de l'objet.


TANK :



FENETRE :

Fenetre hérite de QWidget dans le .h "class Fenetre : public QWidet" et dans le .cpp on met "Fenetre::Fenetre() : QWidget()" comme ça quand on crée une fenêtre c'est aussi un QWidget et QWidget c'est une fenêtre avec pleins de fonctions comme "setFixedSize()" qui sont apportées par Qt.

Rapidement sans les détails ce que j'ai fait c'est pour commencer un menu avec un titre et 3 boutons (un joueur, deux joueurs, quitter), quand on clique sur "un joueur" ou "deux joueurs" ça cache le menu avec des "hide()" et ça affiche le terrain, les tanks et un nouveau bouton "retour menu" avec des show.
J'explique à la fin comment ça marche les clique sur boutons.

On a donc un constructeur:
	Dans le constructeur tout l'initialisation de la fenêtre, donc créations du terrain, du titre, des boutons, des label et des tanks...
	Alors je me sert des QLabel pour placer des images sur la fenêtre:
		exemple:
		//tankJ1
    	tank1 = new Tank();																//Avant on crée le tank pour lequel on va créer un label
    	tank1->setCapacite((terrain->getL()/10));										//Puis on lui met la capacité à L/10
		//Label du tank (image)
    	tankJ1 = new QLabel(this); 														//Création du QLabel
    	tankJ1->setObjectName("tankJ1");												//On donne un nom à l'objet QLabel
    	tankJ1->setGeometry(QRect(tank1->getPosx(), tank1->getPosY(), 40, 40));			//On donne une position au QLabel
    	tankJ1->setPixmap(QPixmap(QString("img/TankDroit.png"))); //tank1->getImage()	//On met une image en fond du QLabel
    	tankJ1->setScaledContents(true);												//On étire l'image pour qu'elle remplisse le label peut importe la taille
    	tankJ1->hide();																	//La on cache le QLabel
    Les fonctions que j'utilise avec tankJ1->... c'est des fonctions de base de QLabel de Qt.
    C'est comme ça que je met le terrain et les tanks.
    Pour le titre je rajoute la taille de la police etc mais pas d'image de fond.
    
    QPushButton c'est pour créer un bouton "appuyable"
    exemple:
    //Bouton Un joueur
    bouton1 = new QPushButton("Jouer - Un joueur", this); //création nouveau boutton donc on lui donne ce qui est écrit sur le bouton et le this représente la 
    													  //fenêtre pour dire que le bouton est lié à la fenêtre c'est un sous Widget du Widget fenêtre si j'ai bien //compris.
    bouton1->setCursor(Qt::PointingHandCursor);  //Change la forme du curseur quand il passe sur le bouton
    bouton1->setFont(QFont("Arial", 16));    //Choix de la police et taille du bouton
    bouton1->setGeometry(320, 180, 400, 90); //Forme et emplacement du bouton

    Pour le bouton quitter j'ai ajouter un bouton3->setToolTip("Arrêt de l'application"); c'est pour que quand tu laisse la souris sur le bouton ça affiche un msg.

    /!\/!\/!\
    Pour les QObject::connect ... c'est important de les mettres après avoir crée tout les objets de la fenêtre sinon si t'essaye d'intéragir avec un objet que t'as crée plus bas dans le code il le trouve pas
    /!\/!\/!\

    Les QObject::connect c'est pour connecter les les objets Qt à des actions ex : 
    "QObject::connect(objetQuiEmetLeSignal, SIGNAL(leTypeDeSignal), objetQuiReçoisLeSignal, SLOT(actionEffectuerLorsDeReceptionDeSignal))"
    Vu que je fais que des connect sur des boutons on a que des SIGNAL(clicked()) et les SLOT(hide()) ou SLOT(show()) c'est pour cacher ou monter les objets
    le SLOT(quit()) quitte l'appli, et le qApp du bouton 3 c'est un pointeur que Qt crée tout seul quand on fait un QApplication (voir MAIN).

    Pour les actions du clavier je sais pas encore si faut mettre ça dans la classe fenêtre ou la classe tank (ou autre part).

MAIN :

#include "fenetre.h" //fenetre.h qui inclue tout le reste


int main(int argc, char *argv[]){
    QApplication app(argc, argv); 							//Création d'une application Qt
    //Fenêtre
    Fenetre F1;												//Création d'une fenêtre
    //Affichages
    F1.show();												//On affiche la fenêtre
    return app.exec(); 										//Exécution de l'application Qt		
}