#include "Point.hpp"
using namespace ariel;

Point :: Point(double xl1, double yl1): x_(xl1), y_(yl1){}

double Point :: distance(const Point& other) const{
    double res = (pow((other.getX()-x_),2)+pow((other.getY()-y_),2));
    return sqrt(res);
}

string Point :: print() const{
    string str = "(" + to_string(x_) + "," + to_string(y_) + ")";
    return str;
}

Point Point :: moveTowards(const Point& source, const Point& dest, double dist){
    if (dist<=0)
        throw invalid_argument("cannot move with negative distance");
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

bool Point :: inDomain(const Point& subj, const Point& edge1, const Point& edge2){
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

