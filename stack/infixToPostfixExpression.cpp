#include <iostream>
#include <string>
using namespace std;
char n = 100;
char stack[100];
char top = -1;

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

void push(char ele)
{
    if (top == n - 1)
    {
        cout << "Overflow -> stack is full \n";
    }
    else
    {
        top++;
        stack[top] = ele;
        cout << "Succesfully pushed " << ele << endl;
    }
}

void pop()
{
    if (top == -1)
    {
        // cout << "Underflow -> stack is empty \n";
    }
    else
    {
        char temp = stack[top];
        top--;
        cout << "Poped the element " << temp << endl;
    }
}
int isEmpty()
{
    if (stack[top] == -1)
    {
        return 1;
    }
    return 0;
}

char peek()
{
    if (top == -1)
    {
        // cout << "Underflow -> stack is empty \n";
        return -1;
    }
    // else
    // {
    //     cout << "The top element is " << stack[top] << endl;
    // }
    return stack[top];
}

void display()
{
    if (top == -1)
    {
        cout << "Underflow -> stack is empty \n";
    }
    else
    {
        int i;
        cout << "Stack elements are : " << endl;
        for (i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}
bool isOperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '-' || ch == '+' || ch == '%' || ch == '^')
        return true;
    else
        return false;
}

string infixToPostfix(char *exp)
{
    string postfix;
    int i = 0;
    while (exp[i] != '\0')
    {
        cout << "inside exp string" << endl;
        if (exp[i] == '(')
        {
            push(exp[i]);
            i++;
            display();
        }
        else if (exp[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                
                char c = peek();
                postfix += c;
                pop();
                display();
            }
            if (stack[top] == '(')
            {
                cout<<"poped (\n";
                pop();
            }

            i++;
        }
        else if (!(isOperator(exp[i])))
        {
            postfix += exp[i];
            i++;
        }

        else if ((isOperator(exp[i])))
        {
            cout << "insde ops" << endl;
            if (prec(exp[i]) > prec(stack[top]))
            {
                push(exp[i]);
                display();
               
            }
            else
            {
                while (top != -1 && prec(exp[i]) <= prec(stack[top]))
                {
                    char c = peek();
                    pop();
                    display();
                    postfix += c;

                   
                }
            }
             i++;
        }
    }
    cout << "outside exp" << endl;
    while (top != -1)
    {
        char c = peek();
        pop();
        display();
        postfix += c;
    }
    postfix += '\0';
    cout << postfix << endl;
    return postfix;
}

int main()
{
    char exp[] = "a+b*c/4+t+5";
    infixToPostfix(exp);
    cout << "returned to main\n";
    cout<<"Sorry currently the output is wrong\n";

    return 0;
}