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
    Node *temp = head;
    cout << "\nLinked list elements are : \n";
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength()
{
    Node *temp = head;
    int count = 0;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
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

        if (head == 0)
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

void insertAtTheBegining()
{
    Node *newNode;
    newNode = new Node();
    cout << "Enter data: ";
    cin >> newNode->data;
    newNode->next = 0;
    newNode->prev = 0;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    cout << "Successfully inserted at the begining\n";
}
void insertAtTheEnd()
{
    Node *newNode;
    newNode = new Node();
    cout << "Enter data: ";
    cin >> newNode->data;
    newNode->next = 0;
    newNode->prev = 0;
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    cout << "Successfully inserted at the end\n";
}
void insertAtPostion()
{
    int pos, i = 1;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos > getLength())
    {
        cout << "Invaild position\n";
    }
    else if (pos == 1)
    {
        insertAtTheBegining();
    }
    else
    {
        Node *newNode, *temp;
        temp= head;
        newNode = new Node();
        cout << "Enter data: ";
        cin >> newNode->data;
        newNode->next = 0;
        newNode->prev = 0;

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
        cout << "Insertion at pos " << pos << " is succesfull" << endl;
    }
}
void insertAfterPostion()
{
    int pos, i = 1;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos > getLength())
    {
        cout << "Invaild position\n";
    }
    if (pos== getLength())
    {
        insertAtTheEnd();
    }
    
    else
    {
        Node *newNode, *temp;
        temp = head;
        newNode = new Node();
        cout << "Enter data: ";
        cin >> newNode->data;
        

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        cout<<"temp is "<<temp->data<<endl;
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
        cout << "Insertion after pos " << pos << " is succesfull" << endl;
    }
}


int main()
{
    createLinkedList();
    int choice;
    cout << "1.insertAtTheBegining\n2.insertAtTheEnd\n3.insertAtPostion\n4.insertAfterPostion\n0.exit\n";

    do
    {
        cout << "\nEnter your choice (0/1/2/3/4): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertAtTheBegining();
            display();
            break;
        case 2:
            insertAtTheEnd();
            display();
            break;
        case 3:
            insertAtPostion();
            display();
            break;
        case 4:
            insertAfterPostion();
            display();
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