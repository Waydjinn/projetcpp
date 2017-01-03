#include "fenetre.h"


int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication app(argc, argv);
    //Fenêtre
    Fenetre *F1 = new Fenetre();
    //Affichages
    F1->show();
    return app.exec(); //Exécution de l'application
}
