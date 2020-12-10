#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *addLinkedList()
{
    node *head, *newnode, *temp;
    head = 0;
    int choice = 1;
    while (choice)
    {
        newnode = new node;
        cout << "Enter the data: ";
        cin >> newnode->data;
        newnode->next = 0;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    cout << "Do you want to continue (0/1) \n";
    cin >> choice;
    }
    return head;
}

void printLinkedList(node *n)
{
    int count = 0;
    while (n!= 0)
    {

        cout << n->data << " ";
        count++;
        n = n->next;
    }
    cout << endl
         << "Total " << count << " elements" << endl;
}

int main()
{
    node *a = addLinkedList();
    printLinkedList(a);
    return 0;
}