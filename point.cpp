#include "point.h"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y){
    this->x = x;
    this->x = y;
}

Point::Point(const Point &p){
    this->x = p.getX();
    this->y = p.getY();
}

int Point::getX()const{
    return this->x;
}

int Point::getY()const{
    return this->y;
}

void Point::setX(int val){
    this->x = val;
}

void Point::setY(int val){
    this->y = val;
}

void Point::afficher(const Point &p){
    cout << p.getX() << endl;
    cout << p.getY() << endl;
}

void Point::cloner(const Point &p){
    this->x = p.getX();
    this->y = p.getY();
}

void Point::move(int x, int y){
    this->x += x;
    this->y += y;
}

Point::~Point(){
    cout << "appel au destructeur" << endl;
}
