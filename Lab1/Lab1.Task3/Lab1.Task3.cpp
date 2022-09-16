#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int matrixSize = 3;

int** getMatrixWithRandomNumbers(int min, int max);
string matrixToString(int** matrix);
int** getSmoothingMatrix(int** matrix);
void deleteMatrix(int** matrix);
int getMatrixElementsSumBelowMainDiagonal(int** matrix);

int main(int argc, char* argv[])
{
    //int** matrix = getMatrixWithRandomNumbers(1, 9);

   int** matrix = new int*[matrixSize]{new int[]{1, 2, 3}, new int[]{4, 5, 6}, new int[]{7, 8, 9}};

    cout << "Initial matrix: " << endl;
    cout << matrixToString(matrix) << endl;

    int** newMatrix = getSmoothingMatrix(matrix);
    cout << "\nMatrix after smoothing: " << endl;
    cout << matrixToString(newMatrix) << endl;

    cout << "\nSum of the modules of the elements located below the main diagonal: "
        << getMatrixElementsSumBelowMainDiagonal(newMatrix)
        << endl;

    deleteMatrix(matrix);
    deleteMatrix(newMatrix);
    
    return 0;
}

int getMatrixElementsSumBelowMainDiagonal(int** matrix)
{
    int sum = 0;

    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum += abs(matrix[i][j]);
        }
    }

    return sum;
}

void deleteMatrix(int** matrix)
{
    for (int i = 0; i < matrixSize; i++)
    {
        delete [] matrix[i];
    }

    delete [] matrix;
}

int** getSmoothingMatrix(int** matrix)
{
    int sum, amountNumbers;
    int** newMatrix = new int*[matrixSize];

    for (int i = 0; i < matrixSize; i++)
    {
        newMatrix[i] = new int[matrixSize];

        for (int j = 0; j < matrixSize; j++)
        {
            sum = 0;
            amountNumbers = 0;

            if (i > 0)
            {
                sum += matrix[i - 1][j];
                amountNumbers++;
                if (j > 0)
                {
                    sum += matrix[i - 1][j - 1];
                    amountNumbers++;
                }
                if (j < matrixSize - 1)
                {
                    sum += matrix[i - 1][j + 1];
                    amountNumbers++;
                }
            }

            if (i < matrixSize - 1)
            {
                sum += matrix[i + 1][j];
                amountNumbers++;
                if (j > 0)
                {
                    sum += matrix[i + 1][j - 1];
                    amountNumbers++;
                }
                if (j < matrixSize - 1)
                {
                    sum += matrix[i + 1][j + 1];
                    amountNumbers++;
                }
            }

            if (j > 0)
            {
                sum += matrix[i][j - 1];
                amountNumbers++;
            }

            if (j < matrixSize - 1)
            {
                sum += matrix[i][j + 1];
                amountNumbers++;
            }
            newMatrix[i][j] = round((double)sum / amountNumbers);
        }
    }

    return newMatrix;
}

int** getMatrixWithRandomNumbers(int min, int max)
{
    int** matrix = new int*[matrixSize];

    srand(time(nullptr));

    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = new int[matrixSize];

        for (int j = 0; j < matrixSize; j++)
        {
            matrix[i][j] = min + rand() % (max - min + 1);
        }
    }

    return matrix;
}

string matrixToString(int** matrix)
{
    string result;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            result += to_string(matrix[i][j]) + "\t";
        }
        result += "\n";
    }

    return result;
}
