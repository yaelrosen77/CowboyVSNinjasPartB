#include "Point.hpp"
using namespace ariel;

Point :: Point(double x1, double y1){
    x_ = x1;
    y_ = y1;
}

double Point :: distance(const Point& other) const{
    return 0;
}

void Point :: print() const{
    // return;
}

Point ariel :: moveTowards(Point& source, Point& dest, double dist){
    return Point(1,0);
}

double Point:: getX() const{
    return x_;
}
     
double Point:: getY() const{
    return y_;
}