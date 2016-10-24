#ifndef POINT_H
#define POINT_H


class Point
{
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    Point(const Point &p);

    int getX()const;
    int getY()const;
    void setX(int val);
    void setY(int val);
    void afficher(const Point &p);
    void cloner(const Point &p);
    void move(int x, int y);
    ~Point();

};

#endif // POINT_H
