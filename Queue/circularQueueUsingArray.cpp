#include <iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        cout << "Enqueue "<<x<<" is successfull\n";
    }
    else if ((rear + 1) % N == front)
    {
        cout << "Queue is full\n";
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
        cout << "Enqueue "<<x<<" is successfull\n";
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout
            << "Queue is empty \n";
    }
    else if (front == rear)
    {
        cout << "dequeueing the element " << queue[front];
        front = rear = -1;
        cout << "\nSucceed\n";
    }

    else
    {
        cout << "dequeueing the element " << queue[front];
        front = (front + 1) % N;
        cout << "\nSucceed\n";
    }
}
void display(){
   if (front == -1 && rear == -1)
    {
        cout<< "Queue is empty \n";
    }
    else
    {
        cout<<"The queue is\n";
        int i=front;
        while (i!=rear)
        {
            cout<<queue[i]<<" ";
            i=(i+1)%N;

        }
        cout<<queue[rear]<<endl;
        
    }
    
}

int main()
{
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(7);
    display();
    dequeue();
    display();
    dequeue();
    display();
    enqueue(0);
     display();
    enqueue(8);
     display();
     dequeue();
     display();


    return 0;
}