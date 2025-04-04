#include <iostream>
#include <numeric>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num, int denom) {
        if (denom == 0) {
            numerator = 0;
            denominator = 1;
        } else {
            numerator = num;
            denominator = denom;
            reduce();
        }
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            return Fraction(0, 1);  // Return a default value when dividing by zero
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            f.denominator = 1;
        }
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    cout << (f1 + f2) << endl;

    Fraction f3(7, 4), f4(5, 4);
    cout << (f3 - f4) << endl;

    Fraction f5(2, 3), f6(3, 4);
    cout << (f5 * f6) << endl;

    Fraction f7(7, 4), f8(5, 3);
    cout << (f7 / f8) << endl;

    return 0;
}
