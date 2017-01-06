#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QSlider>
#include <QLCDNumber>
#include <QPainter>

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
    QLCDNumber *lcd;
    QLCDNumber *lcdH;
    QLCDNumber *lcd2;
    QLCDNumber *lcd3;
    QLCDNumber *lcd4;
    QLCDNumber *lcdType;
    QSlider * slider1;
    QSlider * slider2;
    QLabel *titre;
    Terrain *terrain;
    Tank *tank1;
    Tank *tank2;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
};

#endif // FENETRE_H
