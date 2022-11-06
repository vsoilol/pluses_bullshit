#pragma once
#include <iostream>

class Matrix
{
    const int ROWS;
    const int COLUMNS;
    int** matrix;
    void setRandomNumbersToMatrix(int** matrix, int min, int max);
    int** allocateMatrix(int ROWS, int COLS);
    void deAllocateMatrix(int** & matrix, const int ROWS);
public:
    int getMatrixValue(int row, int column);
    void setMatrixValue(int row, int column, int value);
    Matrix(int rows, int columns, int** matrix);
    Matrix(int rows, int columns, int min, int max);
    Matrix* operator * (int number);
    bool operator == (Matrix* secondMatrix);
    bool operator != (Matrix* secondMatrix);
    Matrix& operator += (Matrix* matrix);
    friend std::ostream &operator<<(std::ostream &output, const Matrix* matrix);
    ~Matrix();
};
