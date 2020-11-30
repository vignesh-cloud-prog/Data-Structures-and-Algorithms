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
    //here  i th and after elements are in unsorted portion and jth and before elements are in sorted portion
    //first loop for passes starting from index 1 to index n-1
    for (int i = 1; i < n; i++)
    {
        int key = a[i];//key will stores i th element of unsorted portion
        int j = i - 1;//j is the element of sorted portion just before i
        while (j >= 0 && a[j] > key)//here we run the loop if  element before is i is smaller, if it' true then we copy the sorted portions's y th element to next index, this procedure continues until we reach the starting of the array 
        {
            a[j+1] = a[j];  
            j--;
        }
        a[j + 1] = key;//here we insert the unsorted element into it's position in sorted portion
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

// full demonstration of insertion sort with an example
   // -1   0    1   2   3   4   5     <- indexes
   
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 