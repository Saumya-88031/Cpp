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

void OrderedLinkedList::addToHead(char data)
{
    Node *p = new Node;
    p->data = data;
    p->next = NULL;
    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    size++;
}

void OrderedLinkedList::addToTail(char data)
{
    Node *p = new Node;
    p->data = data;
    p->next = NULL;
    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
    size++;
}

void OrderedLinkedList::removeFromHead()
{
    if (head == NULL)
    {
        std::cout << "List is Empty\n";
        return;
    }
    Node *p = head;
    if (head == tail) // this means there is only 1 element
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
    }
    delete p;
    size--;
}

void OrderedLinkedList::removeFromTail()
{
    if (head == NULL)
    {
        std::cout << "List is Empty\n";
        return;
    }
    Node *p = head;
    if (head == tail) // means there is only 1 element
    {
        head = tail = NULL;
    }
    else
    {
        while (p->next != tail)
        {
            p = p->next;
        }
        Node *q = p;
        p = p->next;
        q->next = NULL;
        tail = q;
    }
    delete p;
    size--;
}

void OrderedLinkedList::insert(int index, char data) // zero based indexing
{
    if ((index > size) || (index < 0))
    {
        std::cout << "Invalid Index\n";
        return;
    }
    if (index == size)
    {
        addToTail(data);
        return;
    }
    if (index == 0)
    {
        addToHead(data);
        return;
    }
    Node *p = head;
    for (int i = 1; i < index; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    Node *r = new Node;
    r->data = data;
    r->next = q;
    p->next = r;
    size++;
}

void OrderedLinkedList::remove(int index)
{
    if ((index > size - 1) || (index < 0))
    {
        std::cout << "Invalid Index\n";
        return;
    }
    if (index == size - 1)
    {
        removeFromTail();
        return;
    }
    if (index == 0)
    {
        removeFromHead();
        return;
    }
    Node *p = head;
    for (int i = 1; i < index; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    Node *r = q->next;
    p->next = r;
    delete q;
    size--;
}

int main()
{
    int n;
    char x;
    OrderedLinkedList A;
    std::cout << "Enter size of A: ";
    std::cin >> n;
    if (n > 0)
    {
        std::cout << "Enter char value\n";
        for (int i = 0; i < n; i++)
        {
            std::cin >> x;
            A.insert(x);
        }
    }

    OrderedLinkedList B;
    std::cout << "Enter size of B: ";
    std::cin >> n;
    if (n > 0)
    {
        std::cout << "Enter char value\n";
        for (int i = 0; i < n; i++)
        {
            std::cin >> x;
            B.insert(x);
        }
    }

    std::cout << "Ordered LL A: \n";
    A.display();
    std::cout << "Ordered LL B: \n";
    B.display();
    std::cout << "\nMerging B in A\n";
    A.merge(B);
    std::cout << "A after merging with B: \n";
    A.display();
    return 0;
}
