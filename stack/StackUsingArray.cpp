#include<iostream>
using namespace std;
int n=5;
int stack[5];
int top=-1;

void push(){
    if (top == n-1) 
    {
        cout<<"Overflow -> stack is full \n";

    }
    else
    {  
        top++;
        cout<<"Enter the element you want to push: ";
        cin>>stack[top];
        cout<<"Succesfully pushed\n";
    }
}

void pop(){
    if (top == -1) 
    {
        cout<<"Underflow -> stack is empty \n";

    }
    else
    {  
        int temp = stack[top];
    top--;
        cout<<"Poped the element "<<temp<<endl;
        
    }
}

void peek(){
    if (top == -1) 
    {
        cout<<"Underflow -> stack is empty \n";

    }
    else
    {    
        cout<<"The top element is "<<stack[top]<<endl;  
    }
}

void display(){
    if (top == -1) 
    {
        cout<<"Underflow -> stack is empty \n";

    }
    else
    {
        int i;
        cout<<"Stack elements are : "<<endl;
        for ( i = top; i >= 0; i--)
        {
            cout<<stack[i]<<" ";
        }
        
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