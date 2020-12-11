#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *head = 0, *tail;

void display()
{
    if (head == 0 && tail == 0) //check if the queue is empty
    {
        cout << "Queue is empty\n";
    }
    else
    {
        Node *temp = head;
        cout << "\nLinked list elements are : \n";
        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void createLinkedList()
{
    int ch = 1;
    do
    {
        Node *newNode;
        newNode = new Node();
        cout << "Enter data: ";
        cin >> newNode->data;
        newNode->next = 0;
        newNode->prev = 0;

        if (head == 0) //inserting first node
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Do you want to continue (0/1) : ";
        cin >> ch;
    } while (ch != 0);
    display();
}

void reverse()
{
    Node *temp = head, *nextNode;
    while (temp != 0)
    {
        nextNode = temp->next;
        temp->next = temp->prev;
        temp->prev = nextNode;
        temp = nextNode;
    }
    temp = head;
    head = tail;
    tail = temp;
    cout << "\nAfter reverse of linkedlist";
    display();
}

int main()
{
    createLinkedList();
    reverse();
    return 0;
}