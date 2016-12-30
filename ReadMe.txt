PROJET CPP - JEU DE TANK

REMARQUE :
Pour que ce soit plus lisible ouvre le ReadMe avec un éditeur de text.
/!\/!\/!\
Si les images apparaisent pas quand l'application est lancé, verifié que dans le dossier "build-nomDuProjet-Desktop_Qt_5_7_0_MinGW_32bit-Debug" ,normalement à la racine du dossier du projet, tu ai le dossier img, si c'est pas le cas tu le prend dans le dossier du projet et tu le copie juste.
/!\/!\/!\

SEGMENT :

La classe Segment fait en TD, /!\Pas utilisé pour le moment/!\.

POINT :

La classe Point fait en TD, /!\Pas utilisé pour le moment/!\.

JOUEURH :

La classe pour les joueurs humains, je l'utilise pas encore, faut peut être attribuer un tank à chaque joueurs et du coup passer par le joueur pour modifier son tank et tout mais pour le moment je me suis surtout occupé du terrain et des tanks.

TERRAIN :

Pour l'instant juste un constructeur qui initialise la taille du terrain, L Longueur et C largeur. Peut être ajouter un tableau ou autre chose avec les coordonnées des obstacles quand on les aura mit.

TANK :

La classe pour créer les tanks, pour commencer on a une variable global pour avoir le nombre de tank crée (faudra peut être faire pareille pour les joueurs), l'idée c'est qu'un tank à 3 types d'obus mais on touche pas à obus1 vu qu'ils sont inifini faudra juste gérer les dégats qu'ils font en fcontion de quel obus et tout.
Donc dans le constructeur on initialise les obus2 et obus3, ensuite on donne la position de départ du tank sur le terrain (posx et posy) et la capacité c'est censé être L/10 (j'ai mit 25 dans le construct mais je le modifie au moment ou je crée le tank dans la classe fenetre) c'est le nombre de déplacement qu'on peut faire dans la partie.
Et du coup en fcontion du nombre de tank qu'on a déjàa crée on change la position de départ, en haut à gauche pour le premier et en bas à droite pour le second pour le moment.

On a les getters et les setters de base.

La fonction "int avancer(int mouv)", l'idée c'est quand fonction de l'entier mouv qui sera 1, 2, 3 ou 4 ou aille soit vers haut, bas, droite, gauche. Le "int aBouge" sert de booléen pour savoir si on a bien modifier les coordonées du tank et à chaque fois avant de modifier les coordonnées on vérifie que le tank sorte pas du terrain.
Les coordonnées c'est des pixels à chaque fois en fait.
Quand les obstacles seront fait faudra aussi vérfifier qu'on traverse pas un obtacle et même le tank adverse.

La fonction "void keyPressEvent(QKeyEvent *event)" c'est une tentative d'utiliser les fonctions de Qt pour les keyEvent mais j'ai pas tous compris, ça compile mais j'arrive pas à voir si ça change quoi que ce soit.

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