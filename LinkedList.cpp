LinkedList operator+(LinkedList const &obj)
    {
        LinkedList result;
        Node *p = head;
        while (p != NULL)
        {
            result.addToTail(p->data);
            p = p->next;
        }
        p = obj.begin();
        while (p != NULL)
        {
            result.addToTail(p->data);
            p = p->next;
        }
        return result;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    void reverse()
    {
        Node *p = head, *q = NULL, *r = NULL;
        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        tail = head;
        head = q;
    }

    int search(int key)
    {
        Node *p = head;
        int i = 0;
        while (p != NULL)
        {
            if (p->data == key)
                return i; 
            p = p->next;
            i++;
        }
        return -1;
    }

    ~LinkedList()
    {
        Node *p = head;
        Node *q = NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
        head = tail = NULL;
    }
};

int main()
{
    LinkedList A;
    int option;
    while (option != 10)
    {
        std::cout << "MENU\n";
        std::cout << "Select option\n";
        std::cout << "1. PushBack(addtotail)\n";
        std::cout << "2. PushFront(addtohead)\n";
        std::cout << "3. RemoveFromHead\n";
        std::cout << "4. RemoveFromTail\n";
        std::cout << "5. Insert\n";
        std::cout << "6. Remove\n";
        std::cout << "7. Display\n";
        std::cout << "8. Reverse\n";
        std::cout << "9. Search\n";
        std::cout << "10. End\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch (option)
        {
            case 1:
            {
                int x;
                std::cout << "Enter an integer value: ";
                std::cin >> x;
                A.addToTail(x);
            }
            break;
    
            case 2:
            {
                int x;
                std::cout << "Enter an integer value: ";
                std::cin >> x;
                A.addToHead(x);
            }
            break;
    
            case 3:
                A.removeFromHead();
                break;
            case 4:
                A.removeFromTail();
                break;
            case 5:
            {
                int pos, value;
                std::cout << "Enter position: ";
                std::cin >> pos;
                std::cout << "Enter an integer value: ";
                std::cin >> value;
                A.insert(pos - 1, value);
            }
            break;
    
            case 6:
            {
                int pos;
                std::cout << "Enter position: ";
                std::cin >> pos;
                A.remove(pos - 1);
            }
            break;
    
            case 7:
                A.display();
                break;
    
            case 8:
                A.reverse();
                break;
    
            case 9:
            {
                int key;
                std::cout << "Enter value you want to search: ";
                std::cin >> key;
                int searchResult = A.search(key) ;
                if (searchResult == -1)
                    std::cout << "Element not found\n";
                else 
                    std::cout << "Element found at postion " << searchResult + 1 << "\n";
                break;
            }
    
            case 10:
                break;
            default:
                std::cout << "Incorrect option\n";
        }
        std::cin.get();
        std::cout << "Press Enter to ";
        option == 10 ? std::cout << "exit..." : std::cout << "continue...";
        std::cin.get();
        std::cout << "\n";
    }
    return 0;
}
