#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create a new node
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
Node *insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search for a node
bool search(Node *root, int value)
{
    if (root == NULL)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Preorder Traversal
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    // Insert nodes
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 7);

    // Display traversals
    cout << "Preorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    // Search
    int key;
    cout << "\n\nEnter a number to search: ";
    cin >> key;

    if (search(root, key))
        cout << key << " exists in the tree.";
    else
        cout << key << " does not exist in the tree.";

    return 0;
}