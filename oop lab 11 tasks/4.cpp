#include <iostream>

using namespace std;

template <typename T>
class Base {
protected:
    T a, b;

public:
    Base(T x, T y) : a(x), b(y) {}

    T multiplyBase() const {
        return a * b;
    }
};

template <typename T>
class Derived : public Base<T> {
private:
    T c, d;

public:
    Derived(T x, T y, T z, T w) : Base<T>(x, y), c(z), d(w) {}

    T multiplyDerived() const {
        return c * d;
    }

    void printResults() const {
        cout << "Base class multiplication: " << this->multiplyBase() << endl;
        cout << "Derived class multiplication: " << multiplyDerived() << endl;
    }
};

int main() {
    Derived<int> obj(2, 3, 4, 5);
    obj.printResults();

    return 0;
}
