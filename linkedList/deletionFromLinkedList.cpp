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
    cout << endl;
}

void deleteAtTheBegining(Node **head)
{
    Node *temp = *head;
    *head = temp->next;
    free(temp);
    cout << "Successfully deleted an element at the begining." << endl;
}
void deleteAtTheEnd(Node **head)
{
    Node *temp = *head, *prevNode;
    while (temp->next != 0)
    {
        prevNode = temp;
        temp = temp->next;
    }
    if (*head == temp)
    {
        head = 0;
    }
    else
    {
        prevNode->next = 0;
    }
    delete temp;
    cout << "Successfully deleted an element at the end." << endl;
}

void deleteAtSpecifiedPosition(Node **head)
{
    Node *temp = *head, *deleteNode;
    int pos, i = 1;
    cout << "Enter the position of the element :";
    cin >> pos;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
    cout << "successfully deleted the element at pos " << pos << endl;
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;

    // allocate 4 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 1;      // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    printList(head);
    deleteAtTheBegining(&head);
    printList(head);

    deleteAtTheEnd(&head);
    printList(head);

    deleteAtSpecifiedPosition(&head);
    printList(head);

    return 0;
}