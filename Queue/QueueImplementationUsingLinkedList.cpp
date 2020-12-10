#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *front = 0;
Node *rear = 0;

void enqueue(int x)
{
    Node *newNode;
    newNode = new Node();
    newNode->data = x;
    newNode->next = 0;

    if (front == 0 && rear == 0)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        Node *temp = front;
        cout << "Dequeued the element " << front->data<<endl;
        front = front->next;
        delete temp;
    }
}
void display(){
    Node *temp = front;
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout<<"Queue elements are\n";
        while (temp!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        
    }
    
    
}
int peek(){
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty\n";
        return 0;

    }
    else
    {
        cout<<"Front element is "<<front->data<<endl;
        return front->data;
    }
    

}

int main()
{
    enqueue(5);
    enqueue(0);
    enqueue(-3);
    display();
    dequeue();
    peek();

    return 0;
}