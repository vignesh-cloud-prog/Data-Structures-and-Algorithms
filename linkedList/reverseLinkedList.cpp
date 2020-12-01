#include<iostream>
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

Node *addLinkedList()
{
    Node *head, *newNode, *temp;
    head = 0;
    int choice = 1;
    while (choice)
    {
        newNode = new Node;
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->next = 0;
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    cout << "Do you want to continue (0/1) \n";
    cin >> choice;
    }
    return head;
}

Node * reverseLinkedList(Node **head){
    Node *currentNode,*preNode=0,*nextNode;
    currentNode=nextNode=*head;
    while (nextNode != 0)
    {
        nextNode =nextNode->next;
        currentNode->next=preNode;
        preNode=currentNode;
        currentNode=nextNode;
    }
    *head = preNode;
    return *head;
    
}

int main()
{
    Node *head;
    head=addLinkedList();
    cout<<"Entered linked list "<<endl;
    printList(head);
    cout<<"Reversed linked list "<<endl;
    head = reverseLinkedList(&head);
    printList(head);
     
    return 0;
}