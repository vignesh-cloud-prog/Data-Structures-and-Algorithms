#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printList(Node *n)
{
    Node *temp = n;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node *head)
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

void insertAtTheBegining(Node **head)
{
    Node *newNode = new Node();
    cout << "Enter the data you want to insert at the begining: ";
    cin >> newNode->data;
    newNode->next = *head;
    *head = newNode;

    cout << "After the insertion in the list" << endl;
    printList(*head);
}

void insertAtTheEnd(Node *head)
{
    Node *newNode = new Node(), *temp;
    cout << "Enter the data you want to insert at the end: ";
    cin >> newNode->data;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "After the insertion in the list" << endl;
    printList(head);
}

void insetAfterGivenNode(Node *head)
{
    Node *temp, *newNode;
    int pos, count = getLength(head);
    cout << "Enter the position: ";
    cin >> pos;
    if (pos > count)
    {
        cout << "Invalid position";
    }
    else
    {
  
    newNode = new Node();
    temp = head;
    int i = 0;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    // cout<<"temp is "<<temp->data<<endl;
    cout << "Enter data you want to insert after pos "<<pos<<": ";
    cin >> newNode->data;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "After the insertion in the list" << endl;
    printList(head);
    }
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;      // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;
    cout<<"List elements"<<endl;
    printList(head);
    insertAtTheBegining(&head);
    cout<<"After insertion in main "<<endl;
    printList(head);
    insertAtTheEnd(head);
    insetAfterGivenNode(head);
    return 0;
}