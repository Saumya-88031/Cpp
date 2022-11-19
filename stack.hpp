#pragma once
#include <iostream>

// 1. stack using ll 2. pop func modified
template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
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

    void push(T data)
    {
        Node *p = new Node;
        p->data = data;
        p->next = top;
        top = p;
        size++;
    }

    T pop()
    {
        if (top == NULL)
        {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        Node *p = top;
        T popedValue = top->data;
        top = top->next;
        delete p;
        size--;
        return popedValue;
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

    T topel() // top element
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
