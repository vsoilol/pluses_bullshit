#include <iostream>
#include <string>
using namespace std;

string arrayToString(int array[], int size);
void setRandomNumbersToArray(int array[], int size, int min, int max);
int getMaxNumber(int array[], int size);
int getSumBetweenFirstAndSecondPositiveNumbers(int array[], int size);
void shiftArrayElements(int array[], int size, int startPosition);
void zeroNumbersAfterOtherElements(int array[], int size);

int main(int argc, char* argv[])
{
    int arraySize;
    cout << "Enter the size of array: ";
    cin >> arraySize;
    int* randArray = new int[arraySize];

    setRandomNumbersToArray(randArray, arraySize, -5, 5);

    cout << "\nInitial array: \n";
    cout << arrayToString(randArray, arraySize) << endl;

    cout << "\nMax module number: " << getMaxNumber(randArray, arraySize) << endl;

    cout << "\nElements sum between first and second positive numbers: "
        << getSumBetweenFirstAndSecondPositiveNumbers(randArray, arraySize)
        << endl;

    zeroNumbersAfterOtherElements(randArray, arraySize);

    cout << arrayToString(randArray, arraySize) << endl;

    delete [] randArray;
    
    return 0;
}

void zeroNumbersAfterOtherElements(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if(array[i] == 0)
        {
            shiftArrayElements(array, size, i);
        }
    }
}

void shiftArrayElements(int array[], int size, int startPosition)
{
    int temp;
    for (int i = startPosition; i < size - 1; i++)
    {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
}

int getSumBetweenFirstAndSecondPositiveNumbers(int array[], int size)
{
    int sum = 0;

    int state = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            state++;
            continue;
        }
        
        if (state == 1)
        {
            sum += array[i];
        }

        if (state == 2)
        {
            break;
        }
    }

    return sum;
}

int getMaxNumber(int array[], int size)
{
    int max = 0;

    for (int i = 0; i < size; i++)
    {
        if (fabs(array[i]) > fabs(max))
        {
            max = array[i];
        }
    }

    return max;
}

void setRandomNumbersToArray(int array[], int size, int min, int max)
{
    srand(time(nullptr));
    for (int i = 0; i < size; i++)
    {
        array[i] = min + rand() % (max - min + 1);
    }
}

string arrayToString(int array[], int size)
{
    string result;

    for (int i = 0; i < size; i++)
    {
        result += to_string(array[i]);

        if (i != size - 1)
        {
            result += ", ";
        }
    }

    return result;
}
