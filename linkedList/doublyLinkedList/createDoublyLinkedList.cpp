#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *head = 0, *temp;

void createLinkedList()
{
    Node *newNode;
    newNode = new Node();
    cout << "Enter data: ";
    cin >> newNode->data;
    newNode->next = 0;
    newNode->prev = 0;

    if (head == 0)
    {
        head = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
}

void display()
{
    Node *temp = head;
    cout<<"\nLinked list elements are : \n";
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int ch = 1;
    do
    {
        createLinkedList();
        cout << "Do you want to continue (1/0) : ";
        cin >> ch;
    } while (ch != 0);
    display();

    return 0;
}