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

    const int MIN = -10;
    const int MAX = 10;

    srand(time(nullptr));

    cout << "Enter row number: ";
    cin >> ROWS;

    cout << "Enter column number: ";
    cin >> COLS;

    /*int** matrix = new int*[ROWS]{
        new int[]{1, 2, 3},
        new int[]{4, 5, 6},
        new int[]{7, 8, 9},
        new int[]{10, 11, 12},
    };*/

    int** firstMatrix = allocateMatrix(ROWS, COLS);
    setRandomNumbersToMatrix(firstMatrix, ROWS, COLS, MIN, MAX);

    cout << "First matrix:\n";
    cout << matrixToString(firstMatrix, ROWS, COLS);

    int** secondMatrix = allocateMatrix(ROWS, COLS);
    setRandomNumbersToMatrix(secondMatrix, ROWS, COLS, MIN, MAX);

    cout << "\nSecond matrix:\n";
    cout << matrixToString(secondMatrix, ROWS, COLS);

    /*cout << matrixToString(matrix, ROWS, COLS) << endl << endl;

    int** transparateMatrix = transposeMatrix(matrix, ROWS, COLS);
    cout << matrixToString(transparateMatrix, COLS, ROWS);*/

    deAllocateMatrix(firstMatrix, ROWS);
    //deAllocateMatrix(secondMatrix, ROWS);

    getchar();
    getchar();

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
    int** matrixC = NULL;
    matrixC = allocateMatrix(ROWS, COLS);

    int* colPtrA = NULL;
    int* colPtrB = NULL;
    int* colPtrC = NULL;
    int* endColPtrA = NULL;
    int* endColPtrB = NULL;
    int* endColPtrC = NULL;

    int** rowPtrA = matrixA;
    int** rowPtrB = matrixB;
    int** rowPtrC = matrixC;
    int** endRowPtrA = matrixA + ROWS;
    int** endRowPtrB = matrixB + ROWS;
    int** endRowPtrC = matrixC + ROWS;

    while ((rowPtrA < endRowPtrA) && (rowPtrB < endRowPtrB) && (rowPtrC < endRowPtrC))
    {
        endColPtrA = *rowPtrA + COLS;
        endColPtrB = *rowPtrB + COLS;
        endColPtrC = *rowPtrC + COLS;

        colPtrA = *rowPtrA;
        colPtrB = *rowPtrB;
        colPtrC = *rowPtrC;

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
