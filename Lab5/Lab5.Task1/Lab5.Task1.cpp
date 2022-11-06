#include "Matrix.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    srand(time(nullptr));

    Matrix* matrix1 = new Matrix(5, 4, 1, 10);

    cout << "Matrix 1 5x4: \n";
    cout << matrix1;

    Matrix* newMatrix = *matrix1 * 5;

    cout << "\nNew matrix after matrix1 * 5\n";
    cout << newMatrix;

    Matrix* matrix2 = new Matrix(3, 3, new int*[]
                                 {
                                     new int[]{1, 2, 3},
                                     new int[]{4, 5, 6},
                                     new int[]{7, 8, 9},
                                 });

    Matrix* matrix3 = new Matrix(3, 3, new int*[]
                                 {
                                     new int[]{1, 2, 3},
                                     new int[]{4, 5, 6},
                                     new int[]{7, 8, 9},
                                 });

    cout << "Matrix 2\n" << matrix2;
    cout << "Matrix 3\n" << matrix3;

    bool isMatrixEqual = *matrix2 == matrix3;

    cout << "\nResult operation matrix2 == matrix3: " << isMatrixEqual;

    Matrix* matrix4 = new Matrix(3, 3, new int*[]
                                 {
                                     new int[]{1, 2, 3},
                                     new int[]{4, 5, 6},
                                     new int[]{7, 8, 9},
                                 });

    Matrix* matrix5 = new Matrix(3, 3, new int*[]
                                 {
                                     new int[]{1, 2, 3},
                                     new int[]{4, 5, 6},
                                     new int[]{7, 8, 1},
                                 });

    cout << "\nMatrix 4\n" << matrix4;
    cout << "Matrix 5\n" << matrix5;

    isMatrixEqual = *matrix4 != matrix5;

    cout << "\nResult operation matrix4 != matrix5: " << isMatrixEqual;

    *matrix2 += matrix3;
    cout << "\nMatrix 1 after matrix2 += matrix3\n" << matrix2;
    
    delete newMatrix;
    delete matrix1;
    delete matrix2;
    delete matrix3;
    delete matrix4;
    delete matrix5;

    return 0;
}
