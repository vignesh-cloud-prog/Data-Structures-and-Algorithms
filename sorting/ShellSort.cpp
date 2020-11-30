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
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void shellSort(int *a, int n)
{
    for (int gap = (n / 2); gap >= 1; gap /= 2)
    {
        cout<<"gap"<<gap<<endl;
        for (int j = gap; j < n; j++)
        {
            cout<<"j"<<j<<endl;
            for (int i = (j - gap); i >= 0; i -= gap)
            {
                cout<<"i"<<i<<endl;
                if (a[i + gap] > a[i])
                {
                    break;
                }
                else
                {
                    int temp = a[i + gap];
                    a[i + gap] = a[i];
                    a[i] = temp;
                }
            }
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

    cout << "Array after sorting by using shell sort" << endl;
    shellSort(array, n);
    printArray(array, n);

    return 0;
}