#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *link;
};
Node *top = 0;

bool isOperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '-' || ch == '+' || ch == '%' || ch == '^')
        return true;
    else
        return false;
}

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int isEmpty()
{
    if (top == 0)
    {
        return 1;
    }
    return 0;
}

void display()
{
    if (top == 0)
    {
        cout << "Underflow -> stack is empty \n";
        return;
    }
    else
    {
        Node *temp;
        temp = top;
        cout << "Stack elements are:\n";
        while (temp != 0)
        {

            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
}

void push(char ch)
{
    Node *newNode;
    newNode = new Node();
    newNode->data = ch;
    newNode->link = top;
    top = newNode;
    cout << "Successfully pushed " << ch << endl;
}

void pop()
{
    if (top == 0)
    {
        cout << "Underflow -> stack is empty" << endl;
        return;
    }
    else
    {
        Node *temp = top;
        top = temp->link;
        cout << "Succesfully poped " << temp->data << endl;
        delete temp;
    }
}

char peek()
{
    if (top == 0)
    {
        cout << "Stack is empty" << endl;
        exit(0);
    }
    else
    {
        cout << "Top element is " << top->data << endl;
        return top->data;
    }
}

string infixToPostfix(char *exp)
{
    string postfix;
    int i = 0; //expression iterator
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if ((isOperator(exp[i])))
        {

            while (top != 0 && prec(exp[i]) <= prec(peek()))
            {
                char c = peek();
                pop();
                display();
                postfix += c;
                cout << "pushed " << c << " to postfix\n";
            }
            push(exp[i]);
        }

        else if (exp[i] == ')')
        {
            while (top != 0 && peek() != '(')
            {

                char c = peek();
                postfix += c;
                cout << "pushed " << c << " to postfix\n";

                pop();
                display();
            }
            if (peek() == '(')
            {
                cout << "poped (\n";
                pop();
            }
        }
        else
        {
            postfix += exp[i];
            cout << "pushed " << exp[i] << " to postfix\n";
        }
        i++;
    }
    while (top != 0)
    {
        char c = peek();
        pop();
        display();
        postfix += c;
        cout << "pushed " << c << " to postfix\n";
    }
    
    return postfix;
}

int main()
{
    char exp[] = "A+(B*C-(D/E^F)*G)*H";
    cout<<"Enter your expression (Ex: A+(B*C-(D/E^F)*G)*H) : \n";
   cin>>exp;
    string postfix = infixToPostfix(exp);
    cout <<"Infix expression is "<<exp<<endl<<"Postfix expression is "<<postfix<<endl;

    return 0;
}