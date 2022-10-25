#include <iostream>
#include <cmath>
#include <iomanip>
#include "Point2D.h"

using namespace std;

Point2D::Point2D()
{
    x = 0;
    y = 0;
    label = "";
}
Point2D::Point2D(double new_x, double new_y, string new_label)
{
    x = new_x;
    y = new_y;
    label = new_label;
}
Point2D::Point2D(double new_x, double new_y)
{
    x = new_x;
    y = new_y;
    label = "";
}

double Point2D::getX()
{
    return x;
}
void Point2D::setX(double new_x)
{
    x = new_x;
}

double Point2D::getY()
{
    return y;
}
void Point2D::setY(double new_y)
{
    y = new_y;
}

string Point2D::getLabel()
{
    return label;
}
void Point2D::setLabel(string new_label)
{
    label = new_label;
}

void Point2D::print()
{
    cout << setprecision(1) << fixed;
    if (label == "") 
    {
        cout << "(" << x << "," << y << ")\n";
    } else
    {
        cout << label << ": (" << x << "," << y << ")\n"; 
    }
}

double Point2D::distance()
{
    double distance = sqrt(x * x + y * y);

    return distance;
}

double Point2D::distance(Point2D target_point)
{
    double distance = sqrt((x - target_point.getX())*(x - target_point.getX()) + (y - target_point.getY())*(y - target_point.getY()));

    return distance;
}

int main()
{
    Point2D a;
    Point2D b(2.5, 4.9);
    Point2D c(-6.5, 8.0, "My Point");

    a.print(); // (0.0, 0.0)
    b.print(); // (2.5, 4.9)
    c.print(); // My Point: (-6.5,8.0)

    b.setLabel("B");
    b.print(); // B: (2.5, 4.9)

    c.setY(0);
    c.print(); // My Point: (-6.5,0.0)

    cout << "Distance between A and B: " << a.distance(b) << "\n"; // 5.5
    cout << "Distance between B and C: " << b.distance(c) << "\n"; // 10.2
    cout << "Distance between C and the origin: " << c.distance() << "\n"; // 6.5

    return 0;
}