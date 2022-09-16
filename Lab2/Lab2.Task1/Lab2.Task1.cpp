#include <iostream>
#include <string>
using namespace std;

string arrayToString(int array[], int size);
string arrayToString(int* arrayBegin, const int* arrayEnd);
void setRandomNumbersToArray(int array[], int size, int min, int max);
int* getMinElements(int* begin, int size);
void setElementsToZeroNotEqualValue(int* arrayBegin, int size, int value);
void sortBubbleArray(int* arrayBegin, int* arrayEnd);

int main(int argc, char* argv[])
{
    int arraySize;
    cout << "Enter the size of array: ";
    cin >> arraySize;
    int* randArray = new int[arraySize];

    setRandomNumbersToArray(randArray, arraySize, -10, 10);

    cout << "\nInit array:\n";
    cout << arrayToString(randArray, arraySize) << endl;

    int* minElement = getMinElements(randArray, arraySize);

    cout << "\nMin element: " << *minElement << endl;

    cout << "\nElements before min elements:\n";
    cout << arrayToString(randArray, minElement) << endl;

    setElementsToZeroNotEqualValue(randArray, arraySize, *minElement);

    cout << "\nNew array:\n";
    cout << arrayToString(randArray, arraySize) << endl;

    int* newArray = new int[arraySize];
    setRandomNumbersToArray(newArray, arraySize, -10, 10);

    cout << "\nNot sorted array:\n";
    cout << arrayToString(newArray, arraySize) << endl;

    sortBubbleArray(newArray, newArray + arraySize);

    cout << "\nSorted array:\n";
    cout << arrayToString(newArray, arraySize) << endl;
    
    return 0;
}

void sortBubbleArray(int* arrayBegin, int* arrayEnd)
{
    for(int* first = arrayBegin; first < arrayEnd; first++)
    {
        for (int* second = first + 1; second < arrayEnd; second++)
        {
            if (*first > *second)
            {
                int temp = *second;
                *second = *first;
                *first = temp;
            }
        }
    }
}

void setElementsToZeroNotEqualValue(int* arrayBegin, int size, int value)
{
    int* arrayEnd = arrayBegin + size;
    
    for (int* arrayElement = arrayBegin; arrayElement < arrayEnd; arrayElement++)
    {
        if(*arrayElement != value)
        {
            *arrayElement = 0;
        }
    }
}

int* getMinElements(int* begin, int size)
{
    int* minElement = begin;
    int* arrayEnd = begin + size;
    
    for (int* arrayElement = begin + 1; arrayElement < arrayEnd; arrayElement++)
    {
        if(*minElement > *arrayElement)
        {
            minElement = arrayElement;
        }
    }

    return minElement; 
}

void setRandomNumbersToArray(int array[], int size, int min, int max)
{
    srand(time(nullptr));
    for (int i = 0; i < size; i++)
    {
        array[i] = min + rand() % (max - min + 1);
    }
}

string arrayToString(int* arrayBegin, const int* arrayEnd)
{
    string result;

    for (int* arrayElement = arrayBegin; arrayElement < arrayEnd; arrayElement++)
    {
        result += to_string(*arrayElement);

        if (arrayElement != arrayEnd - 1)
        {
            result += ", ";
        }
    }

    return result;
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
