#include <iostream>

class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node *p = new Node;
        p->data = data;
        p->next = top;
        top = p;
        size++;
    }

    void pop()
    {
        if (top == NULL)
        {
            std::cout << "Stack is Empty\n";
        }
        Node *p = top;
        top = top->next;
        delete p;
        size--;
    }

    void display()
    {
        if (top == NULL)
        {
            std::cout << "Stack is Empty\n";
            return;
        }
        Node *p = top;
        std::cout << "Size: " << size << "\n";
        std::cout << "Top -> ";
        while (p->next != NULL)
        {
            std::cout << p->data << " -> ";
            p = p->next;
        }
        std::cout << p->data;
        std::cout << "\n";
    }

    int topel()         // top element
    {
        return top->data;
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        return false;
    }

    void clear()
    {
        Node *p = top;
        Node *q = NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
        top = NULL;
    }

    ~Stack()
    {
        Node *p = top;
        Node *q = NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
        top = NULL;
    }
};

int main()
{
    Stack A;
    int option;
    while (option != 6)
    {
        std::cout << "MENU\n";
        std::cout << "Select option\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Top\n";
        std::cout << "4. Display\n";
        std::cout << "5. Clear\n";
        std::cout << "6. End\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch (option)
        {

        case 1:
        {
            int x;
            std::cout << "Enter an integer value: ";
            std::cin >> x;
            A.push(x);
        }
        break;

        case 2:
            A.pop();
            break;
        case 3:
            std::cout << "Top Element: " << A.topel() << "\n";
            break;

        case 4:
            A.display();
            break;

        case 5:
            A.clear();
            break;

        case 6:
            break;
        default:
            std::cout << "Incorrect option\n";
        }
        std::cin.get();
        std::cout << "Press Enter to ";
        option == 6 ? std::cout << "exit..." : std::cout << "continue...";
        std::cin.get();
        std::cout << "\n";
    }
    return 0;
}
