#include <iostream>
using namespace std;

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int array[n];
    cout << "Enter " << n << " elemets of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Array before sorting" << endl;
    printArray(array, n);

    cout << "Array after sorting by using insertion sort" << endl;
    insertionSort(array, n);
    printArray(array, n);
    return 0;
}