#ifndef SEGMENT_H
#define SEGMENT_H


class Segment:public Point
{
private:
    Point A,B;
public:
    Segment();
    Segment(const Point &p1, const Point &p2);
    Segment(const Segment &s);
    Point get_A()const;
    Point get_B()const;
    void move(int x, int y);
    void afficher();
    int longueur(const Segment &s);
    bool estVertical();
    bool estHorizontal();
    bool estSurDiagonale();

    ~Segment();


};

#endif // SEGMENT_H
