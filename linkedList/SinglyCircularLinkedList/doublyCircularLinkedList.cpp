#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *head = 0, *tail = 0;

void display()
{
    Node *temp;
    temp = head;
    if (head == 0)
    {
        cout << "List  is empty\n";
    }
    else
    {
        cout << "List elements are:\n";
        while (temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";

        cout << endl;
    }
}

void createDCLL()
{
    int n;
    cout << "How many elements do you want to insert? \n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node *newNode;
        newNode = new Node();
        cout << "Enter data : ";
        cin >> newNode->data;
        if (head == 0)
        {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }
}

void insertAtTheBegining()
{
    Node *newNode;
    newNode = new Node();
    cout << "Enter the data : ";
    cin >> newNode->data;
    if (head == 0)
    {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    }

    else
    {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        head = newNode;
    }
}
void insertAtTheEnd()
{
    Node *newNode;
    newNode = new Node();
    cout << "Enter the data : ";
    cin >> newNode->data;
    if (head == 0)
    {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }
}
int getlenOfCLL()
{
    int count = 0;
    if (head == 0)
    {
        return 0;
    }
    else
    {

        Node *temp = head;
        while (temp != tail)
        {
            count++;
            temp = temp->next;
        }
        count++;
    }

    return count;
}

void insertAtPos()
{
    
    int pos, i = 1, l = getlenOfCLL();
    cout << "Enter the pos: ";
    cin >> pos;
    if (pos < 1 || pos > l)
    {
        cout << "invalid position";
    }
    else if (pos == 1)
    {
        insertAtTheBegining();
    }
    else
    {
        Node *newNode, *temp=head;
        newNode = new Node();
        cout << "Enter the data : ";
        cin >> newNode->data;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteFromBeg(){
    Node *temp=head;
    if (head==0)
    {
        cout<<"There is no node in the list\n";

    }
    else if (head->next==head)
    {
        head=tail=0;
        delete temp;
    }
    else{
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
  
}
void deleteFromEnd(){
    Node *temp=tail;
    if (head==0)
    {
        cout<<"There is no node in the list\n";

    }
    else if (head->next==head)
    {
        head=tail=0;
        delete temp;
    }
    else{
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
    }
}
void deleteFromPos(){
    Node *temp=head;
    int pos,i=1,l=getlenOfCLL();
    cout<<"Enter the position: ";
    cin>>pos;
    if (pos<1 || pos>l)
    {
        cout<<"Invaild input\n";

    }
    else if (pos==1)
    {
        deleteFromBeg();
    }
    else{
        while (i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if (temp->next==head)
        {
            tail=temp->prev;
        }
        free(temp);
        
    }
    
    
}

int main()
{
    createDCLL();
    display();
    cout<<getlenOfCLL();
    int choice;
    cout << "\n1.insertAtTheBegining\n2.insertAtTheEnd\n3.insertAtPostion\n4.deleteFromBeg\n5.deleteFromEnd\n6.deleteFromPos\n0.exit\n";

    do
    {
        cout << "\nEnter your choice (0/1/2/3): ";
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
            insertAtPos();
            display();
            break;
        case 4:
            deleteFromBeg();
            display();
            break;
        case 5:
            deleteFromEnd();
            display();
            break;
        case 6:
            deleteFromPos();
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