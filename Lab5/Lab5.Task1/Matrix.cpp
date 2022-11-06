#include "Matrix.h"

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

Matrix::Matrix(int rows, int columns, int** matrix) : ROWS(rows), COLUMNS(columns)
{
    this->matrix = matrix;
}

Matrix::Matrix(int rows, int columns, int min, int max) : ROWS(rows), COLUMNS(columns)
{
    this->matrix = allocateMatrix(ROWS, COLUMNS);
    setRandomNumbersToMatrix(this->matrix, min, max);
}

Matrix* Matrix::operator*(int number)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            (*this).setMatrixValue(row, column, (*this).getMatrixValue(row, column) * number);
        }
    }
    return this;
}

int Matrix::getMatrixValue(int row, int column)
{
    return matrix[row][column];
}

void Matrix::setMatrixValue(int row, int column, int value)
{
    matrix[row][column] = value;
}

std::ostream& operator<<(std::ostream& output, const Matrix* matrix)
{
    string result;

    for (int row = 0; row < (*matrix).ROWS; row++)
    {
        for (int column = 0; column < (*matrix).COLUMNS; column++)
        {
            result += to_string((*matrix).matrix[row][column]) + "\t";
        }
        result += "\n";
    }

    return output << result;
}

void Matrix::setRandomNumbersToMatrix(int** matrix, int min, int max)
{
    int** endRowPtr = matrix + ROWS;
    for (int** rowPtr = matrix; rowPtr < endRowPtr; rowPtr++)
    {
        int* endColPtr = *rowPtr + COLUMNS;

        for (int* colPtr = *rowPtr; colPtr < endColPtr; colPtr++)
        {
            *colPtr = min + rand() % (max - min + 1);
        }
    }
}

bool Matrix::operator!=(Matrix* secondMatrix)
{
    if (this->ROWS != secondMatrix->ROWS || this->COLUMNS != secondMatrix->COLUMNS)
    {
        return true;
    }

    for (int row = 0; row < this->ROWS; row++)
    {
        for (int column = 0; column < this->ROWS; column++)
        {
            if (this->getMatrixValue(row, column) != secondMatrix->getMatrixValue(row, column))
            {
                return true;
            }
        }
    }

    return false;
}

bool Matrix::operator==(Matrix* secondMatrix)
{
    if (this->ROWS != secondMatrix->ROWS || this->COLUMNS != secondMatrix->COLUMNS)
    {
        return false;
    }

    for (int row = 0; row < this->ROWS; row++)
    {
        for (int column = 0; column < this->ROWS; column++)
        {
            if (this->getMatrixValue(row, column) != secondMatrix->getMatrixValue(row, column))
            {
                return false;
            }
        }
    }

    return true;
}

Matrix& Matrix::operator+=(Matrix* matrix)
{
    for (int row = 0; row < this->ROWS; row++)
    {
        for (int column = 0; column < this->ROWS; column++)
        {
            this->setMatrixValue(row, column, this->getMatrixValue(row, column) + matrix->getMatrixValue(row, column));
        }
    }

    return *this;
}


int** Matrix::allocateMatrix(int ROWS, int COLS)
{
    int** matrix = new int*[ROWS];

    for (int i = 0; i < ROWS; i++)
        matrix[i] = new int [COLS];

    return matrix;
}

void Matrix::deAllocateMatrix(int**& matrix, const int ROWS)
{
    if (matrix)
    {
        for (int i = 0; i < ROWS; i++)
        {
            delete[] matrix[i];
        }

        delete[] matrix;
    }

    matrix = NULL;
}

Matrix::~Matrix()
{
    deAllocateMatrix(matrix, ROWS);
}
