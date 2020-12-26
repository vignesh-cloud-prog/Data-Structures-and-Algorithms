#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *tail = 0;

int getlenOfCLL()
{
    int count = 0;
    if (tail == 0)
    {
        return -1;
    }
    else
    {

        Node *temp = tail->next;
        while (temp->next != tail->next)
        {
            count++;
            temp = temp->next;
        }
        count++;
    }

    return count;
}

void displayCLL()
{
    Node *temp;
    if (tail == 0)
    {
        cout << "list is empty\n";
    }
    else
    {
        temp = tail->next;
        cout << "List elements are:\n";
        while (temp->next != tail->next)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;

        cout << "incircular list last node contains " << temp->next->data;
    }
    cout << endl;
}

void createCLL()
{
    int choice = 1;
    do
    {

        Node *newNode;
        newNode = new Node();
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->next = 0;
        if (tail == 0)
        {
            cout << " creating a new list\n";
            tail = newNode;
            tail->next = newNode;
        }
        else
        {
            cout << "inserting another one\n";
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Do you want to continue (0/1) : ";
        cin >> choice;

    } while (choice != 0);
}

void insertAtBeg()
{
    Node *newNode = new Node();
    cout << "Enter the Data : \n";
    cin >> newNode->data;
    newNode->next = 0;
    if (tail == 0)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insertAtEnd()
{
    Node *newNode = new Node();
    cout << "Enter the Data : \n";
    cin >> newNode->data;
    newNode->next = 0;
    if (tail == 0)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPos()
{
    int pos, i = 1;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos < 0 && pos > getlenOfCLL())
    {
        cout << "Invalid position\n";
    }
    else if (pos == 1)
    {
        insertAtBeg();
    }
    else if (pos == getlenOfCLL())
    {
        insertAtEnd();
    }
    else
    {
        Node *newNode = new Node(), *temp;
        cout << "Enter the Data : \n";
        cin >> newNode->data;
        newNode->next = 0;

        temp = tail->next;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
int main()
{
    createCLL();
    displayCLL();
    int choice;
    cout << "1.insertAtTheBegining\n2.insertAtTheEnd\n3.insertAtPostion\n0.exit\n";

    do
    {
        cout << "\nEnter your choice (0/1/2/3): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertAtBeg();
            displayCLL();
            break;
        case 2:
            insertAtEnd();
            displayCLL();
            break;
        case 3:
            insertAtPos();
            displayCLL();
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
