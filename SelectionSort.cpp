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

void selectionSort(int *a, int n)
{
    // a loop from begining to one lement before the last element
    for (int i = 0; i < n - 1; i++)
    {
        int indexOfMinEle = i;
        //to find smallest element for index i
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexOfMinEle])
            {
                indexOfMinEle = j;
            }
            // inserting smallest element to i th position
            int temp = a[i];
            a[i] = a[indexOfMinEle];
            a[indexOfMinEle] = temp;
        }
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

    cout << "Array after sorting by using selection sort" << endl;
    selectionSort(array, n);
    printArray(array, n);
    return 0;
}