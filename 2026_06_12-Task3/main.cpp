#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

// Function Prototypes
void traverse(Node *head);
void search(Node *head);
void access(Node *head);
void insertEnd(Node *&head);
void insertAnywhere(Node *&head);
void deleteNode(Node *&head);

int main()
{
    // Create initial linked list
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();

    node1->data = "Aimar";
    node1->next = node2;

    node2->data = "Ahmad";
    node2->next = node3;

    node3->data = "Anjana";
    node3->next = NULL;

    Node *head = node1;

    int choice;

    do
    {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Traverse\n";
        cout << "2. Search\n";
        cout << "3. Access by Position\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert Anywhere\n";
        cout << "6. Delete Node\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            traverse(head);
            break;

        case 2:
            search(head);
            break;

        case 3:
            access(head);
            break;

        case 4:
            insertEnd(head);
            break;

        case 5:
            insertAnywhere(head);
            break;

        case 6:
            deleteNode(head);
            break;

        case 7:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 7);

    return 0;
}

// ================= Traverse =================
void traverse(Node *head)
{
    Node *temp = head;

    cout << "\nLinked List:\n";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// ================= Search =================
void search(Node *head)
{
    string target;

    cout << "Enter data to search: ";
    cin >> target;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == target)
        {
            cout << target << " Found.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Data Not Found.\n";
}

// ================= Access =================
void access(Node *head)
{
    int pos;

    cout << "Enter position: ";
    cin >> pos;

    Node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
        cout << "Invalid Position.\n";
    else
        cout << "Data = " << temp->data << endl;
}

// ================= Insert End =================
void insertEnd(Node *&head)
{
    Node *newNode = new Node();

    cout << "Enter data: ";
    cin >> newNode->data;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "Inserted Successfully.\n";
}

// ================= Insert Anywhere =================
void insertAnywhere(Node *&head)
{
    int pos;

    cout << "Enter position: ";
    cin >> pos;

    Node *newNode = new Node();

    cout << "Enter data: ";
    cin >> newNode->data;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid Position.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Inserted Successfully.\n";
}

// ================= Delete =================
void deleteNode(Node *&head)
{
    string target;

    cout << "Enter data to delete: ";
    cin >> target;

    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == target)
    {
        Node *del = head;
        head = head->next;
        delete del;

        cout << "Deleted Successfully.\n";
        return;
    }

    Node *current = head;

    while (current->next != NULL && current->next->data != target)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        cout << "Data Not Found.\n";
        return;
    }

    Node *del = current->next;
    current->next = del->next;
    delete del;

    cout << "Deleted Successfully.\n";
}