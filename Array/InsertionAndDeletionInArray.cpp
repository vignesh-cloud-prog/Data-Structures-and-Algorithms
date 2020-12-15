#include <iostream>
using namespace std;

void traverse(int *a, int size)
{
    cout << "array elements are : ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertion(int *a, int *size)
{
    int pos, x;
    cout << "Enter the position you want insert : ";
    cin >> pos;
    if (pos <= 0 || pos > *size + 1)
    {
        cout << "invalid position.\n";
        return;
    }
    cout << "Enter data: ";
    cin >> x;
    for (int i = *size - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = x;
    *size+=1;
}
void deletion(int *a, int *size)
{
    int pos;
    cout << "Enter the positon of the element to delete: ";
    cin >> pos;
    if (pos <= 0 || pos > *size)
    {
        cout << "invalid position.\n";
        return;
    }
    for (int i = pos - 1; i < *size - 1; i++)
    {
        a[i] = a[i + 1];
    }
    *size-=1;
}
int main()
{
    int n, ch = 1;
    cout << "Enter the maximum size of the array : ";
    cin >> n;
    int a[n], size;
    cout << "Enter the number of elements: ";
    cin >> size;
    cout<<"Enter the elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    traverse(a, size);

    do
    {
        cout<<"Enter your choice(0/1/2)\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            insertion(a,&size);
            traverse(a,size);
            break;
        case 2:
            deletion(a,&size);
            traverse(a,size);
            break;
        case 0:
            exit(0);
            break;

        default:
        cout<<"Invalid position\n";
            break;
        }
    } while (ch!=0);

    return 0;
}