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

Point::getX(){
    return this->x;
}

Point::getY(){
    return this->y;
}

Point::setX(int val){
    this->x = val;
}

Point::setY(int val){
    this->y = val;
}

Point::afficher(const Point &p){
    cout << this->getX() << endl;
    cout << this->getY() << endl;
}

Point::cloner(const Point &p){
    this->x = p.getX();
    this->y = p.getY();
}

Point::move(int x, int y){
    this->x += x;
    this->y += y;
}

Point::~Point(){
    cout << "appel au destructeur" << endl;
}
