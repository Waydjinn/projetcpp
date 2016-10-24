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

Segment::move(int x, int y){
    A.move(A.get_x(), A.get_y());
    B.move(B.get_x(), B.get_y());
}

Segment::afficher(){
    cout << "Segment:" << endl;
    cout << "Point A : x = " << A.get_x() << "y = " << A.get_y() << endl;
    cout << "Point B : x = " << B.get_x() << "y = " << B.get_y() << endl;
}

Point::Point get_A()const{
    return this->A;
}

Point::get_B()const{
    return this->B;
}

Segment::longueur(const Segment &s){
    return sqrt((((s.B.get_x()-s.A.get_x())^2)+((s.B.get_y()-s.A.get_y())^2)));
}

Segment::estVertical(){
    if(this->A.get_x() == this->B.get_x()){
        cout << "est vertical" << endl;
        return 1;
    }else{
        return 0;
    }
}

Segment::estHorizontal(){
    if(this->A.get_y() == this->B.get_y()){
        cout << "est horizontal" << endl;
        return 1;
    }else{
        return 0;
    }
}

Segment::estSurDiagonale(){
    if(!estHorizontal() && !estVertical()){
        return true;
    }else{
        return false;
    }
}

Segment::~Segment(){
    cout << "appel au destructeur" << endl;
}
