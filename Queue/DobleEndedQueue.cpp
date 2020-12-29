#include <iostream>
using namespace std;

#define N 5
int dequeue[N];
int f = -1, r = -1;

void enqueueFront(int x)
{
    if ((f == 0 && r == N - 1) || (f == (r + 1)))
    {
        cout << "Qeue is full\n";
    }
    else if (f == -1 && r == -1)
    {
        f=r=0;
        dequeue[f] = x;
    }
    else if (f == 0)
    {
        f = N - 1;
        dequeue[f] = x;
    }
    else
    {
        f--;
        dequeue[f] = x;
    }
}

void enqueueRear(int x)
{
    if ((f == 0 && r == N - 1) || (f == (r + 1)))
    {
        cout << "Qeue is full\n";
    }
    else if (f == -1 && r == -1)
    {
        f=r=0;
        dequeue[r] = x;
    }
    else if (r == N - 1)
    {
        r = 0;
        dequeue[r] = x;
    }
    else
    {
        r++;
        dequeue[r] = x;
    }
}

void display()
{
    int i = f;
    if (i==-1 && r==-1)
    {
        cout<<"list is empty\n";
    }
    
    while (i != r)
    {
        cout << dequeue[i] << " ";
        i = (i + 1) % N;
    }
    cout << dequeue[i] << endl;
}
void getFront()
{
    cout << dequeue[f] << endl;
}
void getRear()
{
    cout << dequeue[r] << endl;
}

void dequeueFront()
{
    if (f == -1 && r == -1)
    {
        cout << "List is empty\n";
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (f == N - 1)
    {
        cout << dequeue[f] << endl;
        f = 0;
    }
    else
    {
        cout << dequeue[f] << endl;
        f++;
    }
}

void dequeueRear()
{
    if (f == -1 && r == -1)
    {
        cout << "List is empty\n";
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (r == 0)
    {
        cout << dequeue[r] << endl;
        r = N - 1;
    }
    else
    {
        cout << dequeue[r] << endl;
        r--;
    }
}

int main()
{
    int choice, data;
    cout << "\n1.enqueueFront\n2.enqueueRear\n3.dequeueFront\n4.dequeueRear\n5.display\n6.getFront\n7.getRear\n0.exit\n";

    do
    {
        cout << "\nEnter your choice (0/1/2/3): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            enqueueFront(data);
            display();
            break;
        case 2:
            cout << "Enter the data: ";
            cin >> data;
            enqueueRear(data);
            display();
            break;
        case 3:
            dequeueFront();
            display();
            break;
        case 4:
            dequeueRear();
            display();
            break;
        case 5:

            display();
            break;
        case 6:
            getFront();

            break;
        case 7:
            getRear();

            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Invaild input\n";
            break;
        }
    } while (choice != 0);

    return 0;
}