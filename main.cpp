#include "fenetre.h"


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    //Fenêtre
    Fenetre F1;
    //Terrain T1;
    //Affichages
    F1.show();
    //T1.show();
    return app.exec(); //Exécution de l'application
}
