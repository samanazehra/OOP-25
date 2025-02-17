#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
class Circle
{
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const
    {
        return M_PI * radius * radius;
    }

    double getPerimeter() const
    {
        return 2 * M_PI * radius;
    }
};

int main(int argc, char *argv[])
{   
    double radius = atof(argv[1]);
    Circle c(radius);

    cout << "Area: " << c.getArea() << " cm^2 " << endl;
    cout << "Perimeter: " << c.getPerimeter() << " cm " << endl;

    return 0;
}
