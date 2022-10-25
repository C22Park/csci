#ifndef POINT2D_H 
#define POINT2D_H

#include <iostream>

using namespace std;

class Point2D
{
    private:
        double x;
        double y;
        string label;

    public:
        Point2D();
        Point2D(double new_x, double new_y, string new_label);
        Point2D(double new_x, double new_y);

        double getX();
        void setX(double new_x);

        double getY();
        void setY(double new_y);

        string getLabel();
        void setLabel(string new_label);

        void print();

        double distance();
        double distance(Point2D target_point);7
};

#endif