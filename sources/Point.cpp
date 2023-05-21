#include "Point.hpp"
using namespace ariel;

Point :: Point(double x1, double y1){
    x_ = x1;
    y_ = y1;
}

bool Point :: operator==(const Point& other) const{
    if (x_ == other.getX() && y_ == other.getY())
        return true;
    return false;
}

double Point :: distance(const Point& other) const{
    double res = (pow((other.getX()-x_),2)+pow((other.getY()-y_),2));
    return sqrt(res);
}

void Point :: print() const{
    cout << "(" << x_ << "," << y_ << ")" << endl;
}

Point Point :: moveTowards(Point& source, Point& dest, double dist){
    double dist2 = source.distance(dest);
    if (dist2<=dist){
        return dest;
    }
    if (source.getX() == dest.getX()){
        if (dest.getY() < source.getY()){
            Point res(source.getX(),source.getY()-dist);
            return res;
        }
        Point res(source.getX(),source.getY()+dist);
        return res;
    }
    double slope = (dest.getY()-source.getY())/(dest.getX()-source.getX());
    double tmp = dist / sqrt(1 + pow(slope,2));
    Point vec(tmp,tmp*slope);
    Point res1(source.getX()+vec.getX(),source.getY()+vec.getY());
    Point res2(source.getX()-vec.getX(),source.getY()-vec.getY());
    if (inDomain(res1,source,dest)){
        return res1;
    }
    return res2;
}

bool Point :: inDomain(Point& subj, Point& edge1, Point& edge2){
    double minX = min(edge1.getX(),edge2.getX());
    double maxX = max(edge1.getX(),edge2.getX());
    double minY = min(edge1.getY(),edge2.getY());
    double maxY = max(edge1.getY(),edge2.getY()); 
    if ((subj.getX()>minX && subj.getX()<maxX)&&(subj.getY()>minY && subj.getY()<maxY))
        return true;
    return false;
}
    
double Point:: getX() const{
    return x_;
}
     
double Point:: getY() const{
    return y_;
}

