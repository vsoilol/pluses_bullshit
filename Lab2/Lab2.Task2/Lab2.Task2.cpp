#include <iostream>
#include <string>
using namespace std;

int** allocateMatrix(int ROWS, int COLS);
void deAllocateMatrix(int** & matrix, const int ROWS);
string matrixToString(int** matrix, const int ROWS, const int COLS);
void setRandomNumbersToMatrix(int** matrix, const int ROWS, const int COLS, int min, int max);
int** transposeMatrix(int** matrix, const int ROWS, const int COLS);
int** addMatrix(int** matrixA, int** matrixB, const int ROWS, const int COLS);

int main(int argc, char* argv[])
{
    int ROWS, COLS;

    const int MIN = 1;
    const int MAX = 9;

    srand(time(nullptr));

    cout << "Enter row number: ";
    cin >> ROWS;

    cout << "Enter column number: ";
    cin >> COLS;

    int** firstMatrix = allocateMatrix(ROWS, COLS);
    setRandomNumbersToMatrix(firstMatrix, ROWS, COLS, MIN, MAX);

    cout << "\nFirst matrix:\n";
    cout << matrixToString(firstMatrix, ROWS, COLS);

    int** secondMatrix = allocateMatrix(ROWS, COLS);
    setRandomNumbersToMatrix(secondMatrix, ROWS, COLS, MIN, MAX);

    cout << "\nSecond matrix:\n";
    cout << matrixToString(secondMatrix, ROWS, COLS);

    int** firstTransposeMatrix = transposeMatrix(firstMatrix, ROWS, COLS);
    int** secondTransposeMatrix = transposeMatrix(secondMatrix, ROWS, COLS);

    cout << "\nFirst transpose matrix:\n";
    cout << matrixToString(firstTransposeMatrix, COLS, ROWS);

    cout << "\nSecond transpose matrix:\n";
    cout << matrixToString(secondTransposeMatrix, COLS, ROWS);

    int** matrixSum = addMatrix(firstTransposeMatrix, secondTransposeMatrix, COLS, ROWS);

    cout << "\nTranspose matrix sum:\n";
    cout << matrixToString(matrixSum, COLS, ROWS);

    deAllocateMatrix(firstMatrix, ROWS);
    deAllocateMatrix(secondMatrix, ROWS);
    deAllocateMatrix(firstTransposeMatrix, COLS);
    deAllocateMatrix(secondTransposeMatrix, COLS);
    deAllocateMatrix(matrixSum, COLS);

    return 0;
}

void setRandomNumbersToMatrix(int** matrix, const int ROWS, const int COLS, int min, int max)
{
    int** endRowPtr = matrix + ROWS;
    for (int** rowPtr = matrix; rowPtr < endRowPtr; rowPtr++)
    {
        int* endColPtr = *rowPtr + COLS;

        for (int* colPtr = *rowPtr; colPtr < endColPtr; colPtr++)
        {
            *colPtr = min + rand() % (max - min + 1);
        }
    }
}

int** allocateMatrix(int ROWS, int COLS)
{
    int** matrix = new int*[ROWS];

    for (int i = 0; i < ROWS; i++)
        matrix[i] = new int [COLS];

    return matrix;
}

void deAllocateMatrix(int** & matrix, const int ROWS)
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

string matrixToString(int** matrix, const int ROWS, const int COLS)
{
    string result;

    int** endRowPtr = matrix + ROWS;

    for (int** rowPtr = matrix; rowPtr < endRowPtr; rowPtr++)
    {
        int* endColPtr = *rowPtr + COLS;

        for (int* colPtr = *rowPtr; colPtr < endColPtr; colPtr++)
        {
            result += to_string(*colPtr) + "\t";
        }
        result += "\n";
    }

    return result;
}

int** transposeMatrix(int** matrix, const int ROWS, const int COLS)
{
    int** matrixD = allocateMatrix(COLS, ROWS);

    int** endRowPtr = matrix + ROWS;
    int** rowPtrD = matrixD;
    int** endRowPtrD = matrixD + COLS;

    int i = 0;

    while (rowPtrD < endRowPtrD)
    {
        int** rowPtr = matrix;
        int* colPtrD = *rowPtrD;

        while (rowPtr < endRowPtr)
        {
            int* colPtr = *rowPtr + i;
            *colPtrD = *colPtr;

            colPtrD++;
            rowPtr++;
        }

        i++;
        rowPtrD++;
    }

    return matrixD;
}

int** addMatrix(int** matrixA, int** matrixB, const int ROWS, const int COLS)
{
    int** matrixC = allocateMatrix(ROWS, COLS);

    int** rowPtrA = matrixA;
    int** rowPtrB = matrixB;
    int** rowPtrC = matrixC;
    int** endRowPtrA = matrixA + ROWS;
    int** endRowPtrB = matrixB + ROWS;
    int** endRowPtrC = matrixC + ROWS;

    while ((rowPtrA < endRowPtrA) && (rowPtrB < endRowPtrB) && (rowPtrC < endRowPtrC))
    {
        int* endColPtrA = *rowPtrA + COLS;
        int* endColPtrB = *rowPtrB + COLS;
        int* endColPtrC = *rowPtrC + COLS;

        int* colPtrA = *rowPtrA;
        int* colPtrB = *rowPtrB;
        int* colPtrC = *rowPtrC;

        while ((colPtrA < endColPtrA) && (colPtrB < endColPtrB) && (colPtrC < endColPtrC))
        {
            *colPtrC = *colPtrA + *colPtrB;

            colPtrA++;
            colPtrB++;
            colPtrC++;
        }

        rowPtrA++;
        rowPtrB++;
        rowPtrC++;
    }

    return matrixC;
}
