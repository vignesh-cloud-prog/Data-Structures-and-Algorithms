#include <iostream>
using namespace std;

void traverse(int *a,int size)
{
    cout << "array elements are : ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the maximum size of the array : ";
    cin >> n;
    int a[n], size;
    cout << "Enter the number of elements: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    traverse(a,size);

    return 0;
}