#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QObject>

#include "terrain.h"

class Fenetre : public QWidget
{
public:
    Fenetre();

private:
    QLabel *titre;
    QLabel *map;
    QLabel *tankJ1;
    QLabel *tankJ2;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QPushButton *bouton4;
};

#endif // FENETRE_H
