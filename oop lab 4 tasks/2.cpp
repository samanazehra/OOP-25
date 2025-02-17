#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Polynomial
{
    int degree;
    double *coefficients;

public:
    Polynomial() : degree(0)
    {
        coefficients = new double[1];
        coefficients[0] = 0;
    }

    Polynomial(int deg, const double *coefs) : degree(deg)
    {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = coefs[i];
        }
    }

    Polynomial(const Polynomial &other) : degree(other.degree)
    {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = other.coefficients[i];
        }
    }

    Polynomial(Polynomial &&other) noexcept : degree(other.degree), coefficients(other.coefficients)
    {
        other.coefficients = nullptr;
        other.degree = 0;
    }

    ~Polynomial()
    {
        delete[] coefficients;
    }

    int getDegree() const
    {
        return degree;
    }

    double evaluate(double x) const
    {
        double result = 0;
        double power = 1;
        for (int i = 0; i <= degree; i++)
        {
            result += coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    Polynomial add(const Polynomial &other) const
    {
        int maxDegree = max(degree, other.degree);
        double *newCoefs = new double[maxDegree + 1]{};

        for (int i = 0; i <= degree; i++)
        {
            newCoefs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; i++)
        {
            newCoefs[i] += other.coefficients[i];
        }

        Polynomial result(maxDegree, newCoefs);
        delete[] newCoefs;
        return result;
    }

    Polynomial multiply(const Polynomial &other) const
    {
        int newDegree = degree + other.degree;
        double *newCoefs = new double[newDegree + 1]{};

        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= other.degree; j++)
            {
                newCoefs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(newDegree, newCoefs);
        delete[] newCoefs;
        return result;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        cout << "Usage: " << argv[0] << " <degree1> <coefficients1...> <degree2> <coefficients2...>" << endl;
        return 1;
    }

    int degree1 = atoi(argv[1]);
    if (argc < degree1 + 3)
    {
        cerr << "Insufficient arguments for first polynomial." << endl;
        return 1;
    }

    double *coefs1 = new double[degree1 + 1];
    for (int i = 0; i <= degree1; i++)
    {
        coefs1[i] = atof(argv[i + 2]);
    }

    int degree2 = atoi(argv[degree1 + 3]);
    if (argc < degree1 + degree2 + 5)
    {
        cerr << "Insufficient arguments for second polynomial." << endl;
        delete[] coefs1;
        return 1;
    }

    double *coefs2 = new double[degree2 + 1];
    for (int i = 0; i <= degree2; i++)
    {
        coefs2[i] = atof(argv[i + degree1 + 4]);
    }

    Polynomial p1(degree1, coefs1);
    Polynomial p2(degree2, coefs2);
    
    delete[] coefs1;
    delete[] coefs2;
    
    Polynomial sum = p1.add(p2);
    Polynomial product = p1.multiply(p2);

    cout << "Sum evaluated at x=2: " << sum.evaluate(2) << endl;
    cout << "Product evaluated at x=2: " << product.evaluate(2) << endl;

    return 0;
}