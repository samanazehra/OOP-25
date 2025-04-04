#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class PolynomialUtils;

class Polynomial {
private:
    vector<int> coefficients;

    void trim() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

public:
    Polynomial() {}

    Polynomial(const vector<int>& coeffs) {
        coefficients = coeffs;
        trim();
    }

    Polynomial operator+(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); i++) {
            result[i] += other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); i++) {
            result[i] -= other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
        for (size_t i = 0; i < coefficients.size(); i++) {
            for (size_t j = 0; j < other.coefficients.size(); j++) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }

        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; i--) {
            int c = p.coefficients[i];
            if (c == 0) continue;

            if (!first) {
                os << (c > 0 ? " + " : " - ");
                c = abs(c);
            } else {
                if (c < 0) {
                    os << "-";
                    c = -c;
                }
                first = false;
            }

            if (i == 0 || c != 1) {
                os << c;
            }
            if (i > 0) {
                os << "x";
                if (i > 1) os << "^" << i;
            }
        }

        return os;
    }

    friend class PolynomialUtils;
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power = 1;
        for (size_t i = 0; i < p.coefficients.size(); i++) {
            result += p.coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        vector<int> deriv;
        for (size_t i = 1; i < p.coefficients.size(); i++) {
            deriv.push_back(p.coefficients[i] * i);
        }
        return Polynomial(deriv);
    }
};

int main() {
    Polynomial p1({2, 0, 5, 2});
    Polynomial p2({1, -1, 3});

    cout << "P1: " << p1 << endl;
    cout << "P2: " << p2 << endl;

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    cout << "P1 + P2: " << sum << endl;
    cout << "P1 - P2: " << diff << endl;
    cout << "P1 * P2: " << prod << endl;

    cout << "P1 evaluated at x = 2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of P1: " << PolynomialUtils::derivative(p1) << endl;

    return 0;
}
