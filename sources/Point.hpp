#pragma once
#include <iostream>
using namespace std; 
namespace ariel{

    class Point{
        double x_;
        double y_;

        public:
            Point(double x1, double y1);
            double distance(const Point& other) const;
            void print() const;
            double getX() const;
            double getY() const;
            friend Point moveTowards(Point& source, Point& dest, double dist);
};

}