#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QObject>

class Fenetre : public QWidget //On hérite de QWidget
{
public:
    Fenetre();
    void on_pushBouton1_clicked();
private:
    QLabel *titre;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
};

#endif // FENETRE_H
