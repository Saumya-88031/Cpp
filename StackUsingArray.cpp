// clear, isEmpty, push, pop, top, size

#include <iostream>

class Stack
{
private:
    int top;
    int capacity;
    int *array;

public:
    Stack(int capacity)
    {
        top = -1;
        this->capacity = capacity;
        array = new int[capacity];
    }

    void push(int data)
    {
        if (top == capacity-1)
        {
            std::cout << "Stack is full.\n";
            return;
        }
        top++;
        array[top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            std::cout << "Stack is Empty\n";
            return;
        }
        top--;
    }

    void display()
    {
        if (top == -1)
        {
            std::cout << "Stack is Empty\n";
            return;
        }
        std::cout << "Top -> ";
        for (int i=top; i>0; i--)
        {
            std::cout << array[i] << " -> ";
        }
        std::cout << array[0] << "\n";
    }

    int topel() // top element
    {
        return array[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

    void clear()
    {
        top = -1;
    }

    ~Stack()
    {
        top = -1;
        delete[] array;
    }
};

int main()
{
    int capacity;
    std::cout << "Enter capacity of stack: ";
    std::cin >> capacity;
    std::cout << "\n";
    Stack A(capacity);
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
