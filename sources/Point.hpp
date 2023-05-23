#ifndef POINT_
#define POINT_
#include <iostream>
#include <cmath>
using namespace std; 
namespace ariel{

    class Point{
        double x_;
        double y_;

        public:
            Point(double xl1, double yl1);
            double distance(const Point& other) const;
            string print() const;
            double getX() const;
            double getY() const;
            static bool inDomain(const Point& subj, const Point& edge1, const Point& edge2);
            static Point moveTowards(const Point& source, const Point& dest, double dist);
            void SetX(double xl1){x_ = xl1;}
            void SetY(double yl1){y_ = yl1;}
            
};

}

#endif