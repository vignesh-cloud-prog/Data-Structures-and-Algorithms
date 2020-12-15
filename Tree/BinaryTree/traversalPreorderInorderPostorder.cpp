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

void preOrder(Node *root)
{
    // root left right
    if (root == 0)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    //  left root right

    if (root == 0)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    //  left right root
    if (root == 0)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root;
    root = create();
    cout << "\nPreorder is \n";
    preOrder(root);
    cout << "\nPostorder is \n";
    postOrder(root);
    cout << "\nInorder is \n";
    inOrder(root);

    return 0;
}