#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = 0;

void displayCLL()
{
    Node *temp;
    if (head == 0)
    {
        cout << "list is empty\n";
    }
    else
    {
        temp = head;
        cout << "List elements are:\n";
        while (temp->next!= head)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
        
        cout<<"incircular list last node contains "<<temp->next->data;
    }
    cout << endl;
}

int main()
{
    int choice = 1;
    do
    {

        Node *newNode, *temp;

        newNode = new Node();
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->next = 0;
        if (head == 0)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        temp->next = head;

        cout << "Do you want to continue (0/1) : ";
        cin >> choice;

    } while (choice != 0);

    displayCLL();

    return 0;
}