#include <iostream>
using namespace std;

#define N 5
int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void traverse()
{
    if (top1 == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Queue elements are\n";
        for (int i = 0; i < N; i++)
        {
            cout << s1[i] << " ";
        }
        cout << endl;
    }
}

void push1(int data)
{
    if (top1 == N - 1)
    {
        cout << "Stack is full";
    }
    else
    {
        top1++;
        s1[top1] = data;
    }
}
void push2(int data)
{
    if (top2 == N - 1)
    {
        cout << "Stack is full";
    }
    else
    {
        top2++;
        s2[top2] = data;
    }
}
int pop1()

{
    if (top1 == -1)
    {
        return 0;
    }
    else
    {
        return s1[top1--];
    }
}
int pop2()
{
    if (top2 == -1)
    {
        return 0;
    }
    else
    {

        return s2[top2--];
    }
}

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int a = pop1();
            push2(a);
        }
        int a = pop2();
        cout << "poped the element " << a << endl;
        count--;
        for (int i = 0; i < count; i++)
        {
            int a = pop2();
            push1(a);
        }
    }
}

int main()
{
    int ch = 1;

    do
    {
        cout << "What you want to perform\n 1.enqueue\n 2.dequeue\n3.traverse\n0.exit\nEnter tour choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int x;
            cout << "Enter the element: ";
            cin >> x;
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            traverse();
            break;

        case 0:
            exit(0);
            break;

        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (ch != 0);

    return 0;
}