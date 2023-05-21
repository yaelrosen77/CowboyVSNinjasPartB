#pragma once
#include <iostream>
#include <cmath>
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
            bool operator==(const Point& other) const;
            static bool inDomain(Point& subj, Point& edge1, Point& edge2);
            static Point moveTowards(Point& source, Point& dest, double dist);
};

}