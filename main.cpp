#include "fenetre.h"


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    //Fenêtre
    Fenetre F1;
    //Affichages
    F1.show();
    return app.exec(); //Exécution de l'application
}
