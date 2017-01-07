PROJET CPP - JEU DE TANK

Féron Robin
Zaarour Martin

SEGMENT :

La classe Segment fait en TD.

POINT :

La classe Point fait en TD.

OBSTACLE :

La classe Obstacle, inclue la classe point.
Elle est constitué de: 
    Obstacle() constructeur par défauts qui crée un objet vide.

    Obstacle(QWidget *Fen) constructeur pour les obstacles arbres, rochers, eau. Dans ce constructeur on attribue un type aléatoire à l'obstacle (entre 1 et 3) qui déterminera si l'obstacle est un arbre (1) un rocher (2) ou de l'eau (3) et on initialise les attributs (vie, posX, posY, type) de l'obstacle en fonction de son type. On stock alors la position de l'obstacle crée dans un tableau de Point _TabPoint qui est une variable globale de la classe Obstacle et ses classes dérivées. A chaque création d'obstacle on incrémente une variable globale _nbrObstacle. 
    Lorsque l'on place un Obstacle on vérifie s'il n'y a pas déjà d'obstacle à cette position, si c'est le cas on donne de nouvel coordonnées x y pour placer l'obstacle actuel.

    Obstacle(QWidget *Fen, int x, int y, int typeO) le constructeur pour les obstacle de type impact, qui ont un fonctionnement différent que les autres obstacles (franchissables si assez de point de mouvement disponible). On stock alors la position des impact crée dans un tableau globale _TabImpacts et on garde un compteur globale _nbrImpacts à jour. 

    Les getters et setters pour les attributs de l'objet.

    Les méthodes int aleaObsX(int a, int b) et int aleaObsY(int a, int b) qui permettent de donner des positions aléatoires au obstacles sur la carte.

    La méthode int chercherObs(Point *Tab, int x, int y) qui vérifie si un obstacle existe à la position (x,y) d'un tableau de point.


TERRAIN :

La classe Terrain, inclue la classe obstacle. Elle est composé d'un constructeur qui :
    Crée un objet Terrain avec un pointeur QWidget  en paramètre, pour rattacher le label du terrain à la fenêtre principale.
    On initialise le terrain à une largeur C = 1000 et longueur L = 500, et on crée un Label, dans lequel on met une image, qui servira a afficher la carte sur le QWidget donné en paramètre.
    On crée également 50 objets Obstacle qui représentent les abres, rochers et zone d'eau de la carte. On stock ces objets Obstacle dans une QListe<Obstacle *> listObstacle.

    Les getters et setters pour les attributs de l'objet.


TANK :

La classe Tank inclue la classe Terrain et hérite de la classe Obstacle.

Un tank a une capacité (nbr de déplacements), un typeObusCharg (type d'obus chargé), des obus 1 2 et 3, une position x posx et y posy et un nombre de mouvements par tour nbrMouvTour

La classe contient :
    _nbrTank une variable global du nombre de tank crée.

    Un constructeur Tank(QWidget *Fen, Terrain *carte), qui crée un tank et le place à une position aléatoire sur le terrain, en vérifiant de ne pas poser le tank sur un obstacle grâce à son héritage avec la classe Obstacle.

    Les getters et setters pour les attributs de l'objet.

    Les méthodes int aleaTankX() et int aleaTankY() qui font en sorte de placer le tank du joueur 1 dans la partie gauche de la carte et le tank du joueur 2 dans la partie droite de la carte.

    La méthode void avancer(int mouv, int joueur, Tank *tankJoueur, Tank *tankAdverse) qui en fonction du mouvement donné en paramètre (1 : haut, 2 : bas, 3 : droite, 4 : gauche) permet de modifier la position du tank qui joue. Elle diminue également la capacité de déplacement des tank quand ils se déplacent et vérifie si le tank est sur un impact ou non, en effet si le tank est sur un impact le coût en déplacement est doublé.

    La méthode void tirer(QWidget *Fen, int angle, int force, Tank *tankJoueur) permet de faire tirer le tank en fonction de l'angle et de la force donnée et de modifier le nombre d'obus restant après le tir.

    La méthode int aTouche(Tank *tankAdverse) permet de vérifier si le tank adverse à été touché en comparant la position du dernier impact crée avec la position du tank adverse.

    La méthode int tireEffet(Tank *tankJoueur, int posTirX, int posTirY) permet de déterminé l'effet qu'aura le tire sur le terrain, comme la destruction d'un obstacle ou non.
    
    La méthode int verif(Tank *tankJoueur, int mouv) permet avant un mouvement du tank de vérifier si il peut effectuer ce mouvement ou si on obstacle le bloque.


FENETRE :

Fenetre hérite de QWidget et inclue la classe tank.

On a donc un constructeur:
    Dans le constructeur toute l'initialisation de la fenêtre, donc créations du terrain, du titre, des boutons, des label et des tanks...
        exemple:
        //tankJ1
        tank1 = new Tank();//Avant on crée le tank pour lequel on va créer un label
        tank1->setCapacite((terrain->getL()/10));                                       //Puis on lui met la capacité à L/10
        //Label du tank (image)
        tankJ1 = new QLabel(this); //Création du QLabel
        tankJ1->setObjectName("tankJ1");//On donne un nom à l'objet QLabel
        tankJ1->setGeometry(QRect(tank1->getPosx(), tank1->getPosY(), 40, 40));//On donne une position au QLabel
        tankJ1->setPixmap(QPixmap(QString("img/TankDroit.png"))); //tank1->getImage()//On met une image en fond du QLabel
        tankJ1->setScaledContents(true);//On étire l'image pour qu'elle remplisse le label peut importe la taille
        tankJ1->hide();//Là on cache le QLabel
    
    QPushButton permet de créer un bouton "appuyable"
    exemple:
    //Bouton Un joueur
    bouton1 = new QPushButton("Jouer - Un joueur", this); //création nouveau boutton donc on lui donne ce qui est écrit sur le bouton et le this représente la 
                                                          //fenêtre pour dire que le bouton est lié à la fenêtre c'est un sous Widget du Widget fenêtre

    bouton1->setCursor(Qt::PointingHandCursor);  //Change la forme du curseur quand il passe sur le bouton
    bouton1->setFont(QFont("Arial", 16));    //Choix de la police et taille du bouton
    bouton1->setGeometry(320, 180, 400, 90); //Forme et emplacement du bouton

    Pour le bouton quitter j'ai ajouter un bouton3->setToolTip("Arrêt de l'application"); Permet lorsque la souris est laissée sur le bouton d'afficher un message.

    /!\/!\/!\
    Pour les QObject::connect ... il est important de les mettre après avoir crée tout les objets de la fenêtre car si un objet est crée après il n'est pas accessible par la méthode QObjetct::connect
    /!\/!\/!\

    Les QObject::connect servent a connecter les les objets à des actions exemple : 
    "QObject::connect(objetQuiEmetLeSignal, SIGNAL(leTypeDeSignal), objetQuiReçoisLeSignal, SLOT(actionEffectuerLorsDeReceptionDeSignal))"
    
    Pour les actions du clavier on utilise un installEventFilter(this) dans le constructeur pour que notre Objet Fenêtre et QWidget filtre les événements et on interprète ces événements dans la méthode bool eventFilter(QObject *watched, QEvent *event).

    Le getteur int getAuTourDe() const et le setter void setAuTourDe(int n) pour savoir qui doit jouer.

    Les objets QSlider permette d'avoir des sliders sur un QWidget, et les QLCDNumber permettent d'afficher une valeur avec un min max avec un affichage digital.

MAIN :

#include "fenetre.h" //fenetre.h qui inclue tout le reste


int main(int argc, char *argv[]){
    QApplication app(argc, argv);//Création d'une application Qt
    //Fenêtre
    Fenetre F1;//Création d'une fenêtre
    //Affichages
    F1.show();//On affiche la fenêtre
    return app.exec(); //Exécution de l'application Qt      
}