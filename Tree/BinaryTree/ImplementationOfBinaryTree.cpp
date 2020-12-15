#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *create()
{
    int x;
    Node *newNode;
    newNode = new Node;
    cout << "Enter data (-1 for no node) : ";
    cin >> x;
    if (x == -1)
    {
        return 0;
    }
    newNode->data = x;
    cout << "Enter left child of " << x << "\n";
    newNode->left = create();
    cout << "Enter right child of " << x << "\n";
    newNode->right = create();
    return newNode;
}

int main()
{
    Node *root;
    root = create();

    return 0;
}