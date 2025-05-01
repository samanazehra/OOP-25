#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c, T init_val = T()) : rows(r), cols(c) {
        data.resize(rows, vector<T>(cols, init_val));
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols) {
            throw out_of_range("Index out of bounds");
        }
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols) {
            throw out_of_range("Index out of bounds");
        }
        return data[r][c];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw logic_error("Dimension mismatch for matrix addition");
        }

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.at(i, j) = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw logic_error("Dimension mismatch for matrix multiplication");
        }

        Matrix<T> result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                result.at(i, j) = T();
                for (size_t k = 0; k < cols; ++k) {
                    result.at(i, j) += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> m1(2, 2, 1);
        m1.at(0, 1) = 2;
        m1.at(1, 0) = 3;
        m1.at(1, 1) = 4;

        Matrix<int> m2(2, 2, 5);
        m2.at(0, 1) = 6;
        m2.at(1, 0) = 7;
        m2.at(1, 1) = 8;

        Matrix<int> sum = m1 + m2;
        cout << "Matrix 1 + Matrix 2:" << endl;
        sum.print();

        Matrix<int> product = m1 * m2;
        cout << "Matrix 1 * Matrix 2:" << endl;
        product.print();
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
