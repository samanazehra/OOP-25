#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
protected:
    double x, y;
    string color;
    double borderThickness;

public:
    Shape(double x, double y, string color, double borderThickness = 1.0) : x(x), y(y), color(color), borderThickness(borderThickness) {}

    void getShapeInfo()
    {
        cout << "Position: (" << x << ", " << y << ")\n";
        cout << "Color: " << color << "\n";
        cout << "Border Thickness: " << borderThickness << "\n";
    }
    double calculateArea()
    {
        return 0;
    }
    double calculatePerimeter()
    {
        return 0;
    }
    void draw()
    {
        cout << "Drawing shape at position (" << x << ", " << y << ")\n";
    }
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double x, double y, string color, double radius) : Shape(x, y, color), radius(radius) {}

    double calculateArea()
    {
        return 3.1412 * radius * radius;
    }

    double calculatePerimeter()
    {
        return 2 * 3.1412 * radius;
    }

    void draw()
    {
        cout << "Drawing Circle with radius " << radius << " at (" << x << ", " << y << ")\n";
    }
};

class Rectangle : public Shape
{
    double width, height;

public:
    Rectangle(double x, double y, string color, double width, double height) : Shape(x, y, color), width(width), height(height) {}

    double calculateArea()
    {
        return width * height;
    }

    double calculatePerimeter()
    {
        return 2 * (width + height);
    }

    void draw()
    {
        cout << "Drawing Rectangle with width " << width << " and height " << height << " at (" << x << ", " << y << ")\n";
    }
};

int main()
{
    Circle c(10, 15, "Red", 5);
    Rectangle r(5, 5, "Blue", 20, 10);
    c.draw();
    cout << "Circle Area: " << c.calculateArea() << "\n";
    cout << "Circle Perimeter: " << c.calculatePerimeter() << "\n";
    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << "\n";
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << "\n";
    return 0;
}
