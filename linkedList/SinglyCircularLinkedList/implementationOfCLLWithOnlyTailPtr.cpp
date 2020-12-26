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
            temp=temp->next;
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

int main()
{
    int n;
    // cout << "How many elements do you want to insert: ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    createCLL();
    // displayCLL();
    // }
    displayCLL();
    cout << getlenOfCLL();

    return 0;
}
