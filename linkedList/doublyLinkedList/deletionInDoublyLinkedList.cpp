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

void display()
{
    if (head==0 && tail==0)//check if the queue is empty
    {
        cout<<"Queue is empty\n";
    }
    else{
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

        if (head == 0)//inserting first node
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

bool isEmpty()
{
    if (head == 0)
    {
        return 1;
    }
    else
        return 0;
}

void deleteFromBegining()
{
    Node *temp=head;
    if (head==tail)//if only one element left
    {
        head=tail=0;
        free(temp);
    }
    
    else if (!isEmpty())// deletion is possible when queue is not empty
    {
        temp = head;
        head = head->next;
        head->prev = 0;
        free(temp);
        cout << "Successfully deleted from the begining\n";
    }
    else
        cout << "Queue is empty\n";
        
}

void deleteFromEnd()
{
    Node *temp=tail;
    if (head==tail)//if only one element left
    {
        head=tail=0;
        free(temp);
    }
    
    else if (!isEmpty())
    {
        temp = tail;
        tail->prev->next = 0;
        tail = tail->prev;
        free(temp);
        cout << "Successfully deleted from the End\n";
    }
    else
        cout << "Sorry queue is empty\n";
        
}

void deleteFromPosition()
{
    int pos, i = 1;
    Node *temp = head;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos == 1)//if position is 1 and delete from begining
    {
        deleteFromBegining();
    }
    
    else
    {

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next==0)//check if the element is the last element
        {
            tail=tail->prev;
            tail->next=0;
            free(temp);
        }
        else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        }
        cout << "Successfully deleted at pos " << pos << endl;
        
    }
}

int main()
{
    int ch = 1;
    cout << "1.deleteFromBegining\n2.deleteFromEnd\n3.deleteFromPosition\n4.Craete linked list\n0.exit\n";
    do
    {

        cout << "\nEnter your choice (0/1/2/3/4): ";
        cin >> ch;
        switch (ch)
        {
        case 4:

            createLinkedList();

            break;
        case 1:
            deleteFromBegining();
            display();
            break;
        case 2:
            deleteFromEnd();
            display();
            break;
        case 3:
            deleteFromPosition();
            display();
            break;

        case 0:
            exit(0);
            break;
        default:
            cout << "Invaild input\n";
            break;
        }
    } while (ch != 0);

    return 0;
}