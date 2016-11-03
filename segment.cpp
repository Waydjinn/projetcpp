#include "segment.h"

Segment::Segment(){
    this->A = Point();
    this->B = Point();
}
Segment::Segment(const Point &p1, const Point &p2){
    this->A = Point(p1);
    this->B = Point(p2);
}
Segment::Segment(const Segment &s){
    this->A = s.A;
    this->B = s.B;
}

void Segment::move(int x, int y){
    A.move(A.getX(), A.getY());
    B.move(B.getX(), B.getY());
}

void Segment::afficher(){
    cout << "Segment:" << endl;
    cout << "Point A : x = " << A.getX() << "y = " << A.getY() << endl;
    cout << "Point B : x = " << B.getX() << "y = " << B.getY() << endl;
}

Point Segment::get_A()const{
    return this->A;
}

Point Segment::get_B()const{
    return this->B;
}

int Segment::longueur(const Segment &s){
    return sqrt((((s.B.getX()-s.A.getX())^2)+((s.B.getY()-s.A.getY())^2)));
}

bool Segment::estVertical(){
    if(this->A.getX() == this->B.getX()){
        cout << "est vertical" << endl;
        return 1;
    }else{
        return 0;
    }
}

bool Segment::estHorizontal(){
    if(this->A.getY() == this->B.getY()){
        cout << "est horizontal" << endl;
        return 1;
    }else{
        return 0;
    }
}

bool Segment::estSurDiagonale(){
    if(!estHorizontal() && !estVertical()){
        return true;
    }else{
        return false;
    }
}

Segment::~Segment(){
    cout << "appel au destructeur" << endl;
}
