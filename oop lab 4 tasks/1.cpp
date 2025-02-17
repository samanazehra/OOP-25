#include <iostream>
#include <string>
using namespace std;

class Matrix
{
    int rows;
    int columns;
public:
    double **m;
    Matrix()
    {
        rows = 0;
        columns = 0;
        m = nullptr;
    }
    Matrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        m = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            m[i] = new double[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                m[i][j] = 0;
            }
        }
    }
    Matrix(const Matrix &other)
    {
        rows = other.rows;
        columns = other.columns;
        m = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            m[i] = new double[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                m[i][j] = other.m[i][j];
            }
        }
    }
    Matrix(Matrix &&other) noexcept
    {
        rows = other.rows;
        columns = other.columns;
        m = other.m;
        other.m = nullptr;
        other.rows = 0;
        other.columns = 0;
    }
    ~Matrix()
    {
        if (m)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] m[i];
            }
            delete[] m;
        }
    }
    int getRows()
    {
        return rows;
    }
    int getColumns()
    {
        return columns;
    }
    double &at(int row, int column)
    {
        return m[row][column];
    }
    void fill(double value)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                m[i][j] = value;
            }
        }
    }
    Matrix transpose()
    {
        Matrix matrix(columns, rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix.m[j][i] = m[i][j];
            }
        }
        return matrix;
    }
    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    int rows = stoi(argv[1]);
    int columns = stoi(argv[2]);
    double value = stod(argv[3]);
    Matrix m1(rows, columns);
    m1.fill(value);
    Matrix m2 = m1;
    Matrix m3 = m1.transpose(); 
    cout << "Original Matrix:\n";
    m1.print();
    cout << "Transposed Matrix:\n";
    m3.print();
}
