#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *link;
};
Node *top = 0;

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

int isEmpty()
{
    if (top == 0)
    {
        cout << "Stack is empty\n";
        return 1;
    }
    return 0;
}

void push(char data)
{
    Node *newNode;
    newNode = new Node();
    newNode->data = data;
    newNode->link = top;
    top = newNode;
    // cout << "Successfully pushed\n";
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
        // cout << "Succesfully poped " << temp->data;
        delete temp;
    }
}

char peek()
{
    if (top == 0)
    {
        // cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        // cout << "Top element is " << top->data << endl;
    }
    return top->data;
}
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int parenthesisMatch(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {

            char topEle = peek();

            if (!match(topEle, exp[i]))
            {
                return 0;
            }
            pop();
        }
    }
    if (isEmpty())
    {
        cout << "Parenthesis matching\n";
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[] = "[4-6]((8){(9-8)})";
    cout<<"Enter your expression (Ex: [4-6]((8){(9-8)}) )\n";
    cin>>exp;

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is balanced");
    }
    else
    {
        printf("The parenthesis is not balanced");
    }

    return 0;
}