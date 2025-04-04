#include <iostream>

using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) {
        value = v;
    }

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Number& n) {
        os << n.value;
        return os;
    }
};

int main() {
    Number x(8);

    cout << "Original: " << x << endl;

    --x;
    cout << "After prefix --x (multiply by 4): " << x << endl;

    x--;
    cout << "After postfix x-- (divide by 4): " << x << endl;

    return 0;
}
