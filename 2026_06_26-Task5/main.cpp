#include <iostream>
#include <string>

using namespace std;

/*
Aimar
Ahmad
Anajana
Jessy
*/

class Stack
{
public:
    string name;
    Stack *next = NULL;
    Stack *top = NULL;
    // push
    void push(string name)
    {
        Stack *newnode = new Stack();
        newnode->name = name;
        newnode->next = top;
        top = newnode;
    }
    // pop
    void pop()
    {
        top = top->next;
    }

    // peek

    // display
    void display()
    {
        Stack *display_node = top;
        while (display_node != NULL)
        {
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
    }
};

int main()
{
    Stack *stack = new Stack();
    stack->push("Aimar");
    stack->push("Ahmad");
    stack->push("Anajana");
    stack->pop();
    stack->push("Jessy");
    stack->display();
    return 0;
}