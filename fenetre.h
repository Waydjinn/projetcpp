#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QObject>

#include <QGraphicsScene>
#include <QGraphicsView>

#include "terrain.h"
#include "tank.h"

class Fenetre : public QWidget
{
public:
    Fenetre();
    bool eventFilter(QObject *watched, QEvent *event);
    int getAuTourDe() const;
    void setAuTourDe(int n);
private:
    int auTourDe;
    QLabel *titre;
    Terrain *terrain;
    Tank *tank1;
    Tank *tank2;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QPushButton *bouton4;
};

#endif // FENETRE_H
