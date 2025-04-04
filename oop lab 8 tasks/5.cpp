#include <iostream>

using namespace std;

class shape {
private:
    float length;
    float width;

public:
    shape(float l = 0, float w = 0) {
        length = l;
        width = w;
    }

    float Area() const {
        return length * width;
    }

    shape operator+(const shape& other) {
        float totalArea = this->Area() + other.Area();
        return shape(totalArea, 1);
    }

    void displayArea() const {
        cout << "Area: " << Area() << endl;
    }

    friend ostream& operator<<(ostream& os, const shape& s) {
        os << "Area: " << s.Area();
        return os;
    }
};

int main() {
    shape shape1(4, 5);
    shape shape2(3, 2);

    shape total = shape1 + shape2;

    cout << "Shape1: " << shape1 << endl;
    cout << "Shape2: " << shape2 << endl;
    cout << "Total (Shape1 + Shape2): " << total << endl;

    return 0;
}
