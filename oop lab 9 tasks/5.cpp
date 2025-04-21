// Task 1: Define abstract class “Shape” that provides interface (through virtual functions)
// to the
// two derived classes “Rectangle” and “Triangle” to implement the function called.
// “getArea()”. The program will output the area of rectangle and area of triangle.
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual double getArea() = 0;
    virtual string getType() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double getArea()
    {
        return length * width;
    }
    string getType()
    {
        return "Rectangle";
    }
};

class Triangle : public Shape
{
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea ()
    {
        return 0.5 * base * height;
    }
    string getType()
    {
        return "Triangle";
    }
};

int main ()
{
    vector<Shape*>shapes;
    shapes.push_back(new Rectangle (5, 8));
    shapes.push_back(new Triangle (9, 6));
    for (int i = 0; i < shapes.size() ; i++)
    {
        cout << "Area of " << shapes[i]->getType() << ": "<< shapes[i]->getArea() << " square units"<< endl;
    }
    for (int i = 0; i < shapes.size() ; i++)
    {
        delete shapes[i];
    }
    return 0;
}