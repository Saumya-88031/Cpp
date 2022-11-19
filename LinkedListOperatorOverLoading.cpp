{
            result.addToTail(p->data);
            p = p->next;
        }
        return result;
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

// overloading + to join linkedlist and form new linkedlist
int main()
{
    LinkedList A;
    A.addToTail(1);
    A.addToTail(2);
    A.addToTail(3);
    std::cout << "Linked List A \n";
    A.display();
    LinkedList B;
    B.addToTail(4);
    B.addToTail(5);
    B.addToTail(6);
    std::cout << "Linked List B\n";
    B.display();
    LinkedList C = A + B;
    std::cout << "Linked List C(A+B)\n";
    C.display();
    std::cin.get();
    return 0;
}
