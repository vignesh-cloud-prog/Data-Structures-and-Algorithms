#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* link;
};
Node *top = 0;

void display(){
    if (top==0)
    {
        cout<<"Underflow -> stack is empty \n";
        return; 
    }
    else
    {
        Node *temp;
        temp = top;
        cout<<"Stack elements are:\n";
        while (temp!=0)
        {
            
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        
    }
    
}

void push(){
    Node *newNode;
    newNode= new Node();
    cout<<"Enter the data you want to push: ";
    cin>>newNode->data;
    newNode->link=top;
    top=newNode;
    cout<<"Successfully pushed\n";
}

void pop()
{
    if (top == 0)
    {
        cout<<"Underflow -> stack is empty"<<endl;
        return;

    }
    else
    {
        Node *temp = top;
        top=temp->link;
        cout<<"Succesfully poped "<<temp->data;
        delete temp;
    }
    
    
}

void peek(){
    if (top==0) 
    {
      cout<<"Stack is empty"<<endl;

    }
    else
    {
        cout<<"Top element is "<<top->data<<endl;
    }
    
    
}

int main()
{
    int ch;
    do
    {
        cout<<"\nWhich operation do you want to perform: \n1.push\n2.pop\n3.peek\n4.display\n0.exit\n\nEnter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 0:
        cout<<"Bye.."<<endl;
            exit(0);
            break;
        
        default:
        cout<<"Invalid input\n";
            break;
        }


    } while (ch!=0);
     
    return 0;
}