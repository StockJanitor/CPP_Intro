/*
Abstract Base Class
Define an abstract base class called BasicShape.  The BasicShape class have the
following members:
• Private or Protected member data
o x and y -- int
• Public member functions
o Default constructor – use 0 for x and y
o Overload constructor -- 2 parameters for x and y
o getX() and getY()
o area()  -- a pure virtual function that returns a double
o print()  -- a void virtual function that prints x and y as (x, y)

Next, define a class called Circle.  It is a derived class from the BasicShape class and it
has the following members:
• Private member data
o radius  -- double
• Public member functions
o Default constructor – use 0 for x and y as center, use 1.0 for radius
o Overload constructor – 3 parameters for x, y, and radius in this order
o area()  -- returns the area of the circle (PI * radius * radius), PI = 3.14
o print()  -- prints center (x, y) and radius

Next, define a class called Rectangle.  It is a derived class from the BasicShape class and
it has the following members:
• Private member data
o width and height -- int
• Public member functions
o Default constructor – use 0 for x and y as top-left corner, use 1 for
width and height
o Overload constructor – 4 parameters for x, y, width, and height in this
order
o area()  -- returns the area of the rectangle (width * height)
o print()  -- prints top-left (x, y), width, and height

After you have created these classes, set up a driver to test them.  Use an array of base
class pointers to hold various Circle and Rectangle objects to demonstrate correct
operations are called at the right time as shown below (polymorphism).
Circle c1;          // center (0, 0) with radius 1.0
Circle c2(5, 7, 2.5);       // center (5, 7) with radius 2.5
Rectangle r1;               // top-left (0, 0) with 1 by 1
Rectangle r2(5, 7, 10, 15); // top-left (5, 7) with 10 by 15
BasicShape *pShapeArray[4] = {&c1, &r1, &c2, &r2};
for (int i = 0; i < 4; i++)
{
    pShapeArray[i]->print();
    cout << “\narea: “ << pShapeArray[i]->area() << endl << endl;
}

// Sample output for c1 and r2
circle: center point (0, 0) and radius 1.0
area: 3.14

Rectangle: top-left point (5, 7), 10 by 15
area: 150

*/

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class BasicShape
{
private:
    int x;
    int y;

public:
    // constructors
    BasicShape()
    {
        x = 0;
        y = 0;
    }
    BasicShape(int a, int b)
    {
        x = a;
        y = b;
    }

    // mutators
    void setX(int a)
    {
        x = a;
    }
    void setY(int a)
    {
        y = a;
    }

    // accessors
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    // service
    virtual double area() = 0;

    virtual void print()
    {
        cout << "center " << '(' << x << ',' << y << ')';
    }
    // destructor
};

class Circle : public BasicShape
{
private:
    double radius;

public:
    Circle()
    {
        radius = 1.0;
    }
    Circle(int a, int b, double c)
    {
        setX(a);
        setY(b);
        radius = c;
    }
    double area() override
    {
        return radius * radius * 3.14;
    }
    void print()
    {
        BasicShape::print();
        cout << fixed << setprecision(1) << " with radius " << radius << endl;
        cout << fixed << setprecision(2) << "area: " << area() << endl;
    }
};
class Rectangle : public BasicShape
{
private:
    int width;
    int height;

public:
    Rectangle()
    {
        width = 1;
        height = 1;
    }
    Rectangle(int a, int b, int c, int d)
    {
        setX(a);
        setY(b);
        width = c;
        height = d;
    }
    double area() override
    {
        return width * height;
    }

    double perimeter()
    {
        return 2 * (width + height);
    }
    void print()
    {
        cout << "top-left " << '(' << getX() << ',' << getY() << ')' << endl;
        cout << "top-right " << '(' << getX() + width << ',' << getY() << ')' << endl;
        cout << "bottom-left " << '(' << getX() << ',' << getY() + height << ')' << endl;
        cout << "bottm-right " << '(' << getX() + width << ',' << getY() + height << ')' << endl;
        cout << "with " << width << " by " << height << endl;
        cout << fixed << setprecision(2) << "area: " << area() << endl;
        cout << fixed << setprecision(2) << "Perimeter: " << perimeter() << endl;
    }
};
int main()
{
    Circle c1;
    c1.print();
    Circle c2(5, 7, 2.5);
    c2.print();

    Rectangle r1;
    r1.print();
    Rectangle r2(5, 7, 10, 15);
    r2.print();

    cout << "\nloop start here: \n";
    BasicShape *pShapeArray[4] = {&c1, &r1, &c2, &r2};
    for (int i = 0; i < 4; i++)
    {
        pShapeArray[i]->print();
    }
    return 0;
}