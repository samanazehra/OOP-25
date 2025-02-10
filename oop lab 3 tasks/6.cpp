#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
    int rows, cols;
    vector<vector<int>> elements;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        elements.resize(rows, vector<int>(cols, 0));
    }

    int getRows() const
    {
        return rows;
    }

    int getCols() const
    {
        return cols;
    }

    void setElement(int i, int j, int value)
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            elements[i][j] = value;
        }
    }

    Matrix add(const Matrix &other)
    {
        if (this->rows != other.rows || this->cols != other.cols)
        {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.elements[i][j] = this->elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix &other)
    {
        if (this->cols != other.rows)
        {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }

        Matrix result(this->rows, other.cols);
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                for (int k = 0; k < this->cols; ++k)
                {
                    result.elements[i][j] += this->elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }
    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    int rows1 = stoi(argv[1]);
    int cols1 = stoi(argv[2]);
    Matrix matrix1(rows1, cols1);
    int index = 3;
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j)
        {
            matrix1.setElement(i, j, stoi(argv[index++]));
        }
    }
    int rows2 = stoi(argv[index++]);
    int cols2 = stoi(argv[index++]);
    Matrix matrix2(rows2, cols2);
    for (int i = 0; i < rows2; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            matrix2.setElement(i, j, stoi(argv[index++]));
        }
    }
    cout << "Matrix 1:" << endl;
    matrix1.display();
    cout << "Matrix 2:" << endl;
    matrix2.display();
    Matrix sum = matrix1.add(matrix2);
    cout << "Sum of Matrix 1 and Matrix 2:" << endl;
    sum.display();
    Matrix product = matrix1.multiply(matrix2);
    cout << "Product of Matrix 1 and Matrix 2:" << endl;
    product.display();
    return 0;
}
