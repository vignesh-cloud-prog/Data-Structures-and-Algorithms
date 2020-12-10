#include <iostream>
using namespace std;

#define N 100
int queue[N];
int front = -1, rear = -1;



void enqueue(int x)
{
    if (rear == N - 1)
    {
        cout << "Queue is full\n";
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        cout << "Enqueue is successfull \n";
    }
    else
    {
        rear++;
        queue[rear] = x;
        cout << "Enqueue is successfull \n";
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Sorry, Queue is empty\n";
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        cout << "Dequeued the element " << queue[front] << endl;
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Sorry, Queue is empty\n";
    }
    else
    {
        cout << "Elements in Queue are :" << endl;

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i]<<" ";
        }
        cout<<endl;
    }
}

int peek()
{
    if (front == -1 && rear == -1)
    {
        cout << "Sorry, Queue is empty\n";
        return 0;
    }
    else
    {
        cout << "Front element is " << queue[front] << endl;
        return queue[front];
    }
}
int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
    return 0;
}