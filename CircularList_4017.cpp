/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Circular linked list implementation using cursor node pointing on last element of list
*/
#include <iostream>
using namespace std;

class Node
{
    int elem;
    Node *next;

public:
    Node()
    {
        next = NULL;
    }

    friend class CircularList;
};

class CircularList
{
    Node *cursor;

public:
    CircularList();
    ~CircularList();
    void removeNode(int value);
    void removeTail();
    void removeFirst();

    void addNode(const int &e, int pos);
    void addEndNode(int e);
    void display();

    Node *searchElem(int s);
    void concatenate(CircularList &l2);
};

CircularList::CircularList()
{
    cursor = NULL;
}

CircularList ::~CircularList()
{
    if (cursor != NULL)
    {
        Node *temp = cursor->next;
        while (temp != cursor)
        {
            Node *del = temp;
            temp = temp->next;
            delete del;
        }
    }
    delete cursor;
}

void CircularList::addEndNode(int e)
{
    Node *a = new Node;
    a->elem = e;
    if (cursor == NULL)
    {
        cursor = a;
        a->next = a;
    }
    else
    {
        Node *pt = cursor->next;
        while (pt != cursor)
        {
            pt = pt->next;
        }
        a->next = pt->next;
        pt->next = a;
        cursor = a;
    }
}
void CircularList::addNode(const int &e, int pos)
{
    int count = 1;
    Node *pt = cursor->next;
    Node *a = new Node;
    a->elem = e;

    if (pos == 1)
    {
        a->next = cursor->next;
        cursor->next = a;
    }
    else
    {
        while (count < pos - 1 && pt != cursor)
        {
            count++;
            pt = pt->next;
        }
        if (pt == cursor)
        {
            addEndNode(e);
        }
        else
        {
            a->next = pt->next;
            pt->next = a;
        }
    }
}

void CircularList::removeFirst()
{
    Node *pt = cursor->next;
    cursor->next = pt->next;
    delete pt;
}
void CircularList ::removeTail()
{
    if (cursor == NULL)
        return;
    else if (cursor->next == cursor)
    {
        delete cursor;
        cursor = NULL;
    }
    else
    {
        Node *temp = cursor->next;
        while (temp->next != cursor)
            temp = temp->next;
        temp->next = cursor->next;
        delete cursor;
        cursor = temp;
    }
}

void CircularList ::removeNode(int value)
{
    if (cursor == NULL)
        return;
    Node *del = cursor->next;
    Node *ptr = cursor;
    while (del != cursor)
    {
        if (del->elem == value)
            break;
        ptr = del;
        del = del->next;
    }
    if (del == cursor && del->elem == value)
    {
        removeTail();
    }
    else
    {
        ptr->next = del->next;
        delete del;
    }
}

void CircularList::display()
{
    if (cursor == NULL)
        cout << "Empty list";
    else
    {
        Node *pt = cursor->next;
        do
        {
            cout << pt->elem << " ";
            pt = pt->next;
        } while (pt != cursor->next);
    }
    cout << endl;
}

void CircularList ::concatenate(CircularList &l2)
{
    if (l2.cursor == NULL)
        return;
    Node *temp = cursor->next;
    cursor->next = l2.cursor->next;
    cursor = l2.cursor;
    cursor->next = temp;
    l2.cursor = NULL;
}
Node *CircularList ::searchElem(int s)
{
    int count = 1;
    Node *pt = cursor->next;
    do
    {
        if (pt->elem == s)
        {
            cout << "The required element " << s << " is present at position: " << count << endl;
            return pt;
        }
        pt = pt->next;
        count++;
    } while (pt != cursor->next);
    return NULL;
}

void takeInput(CircularList &l, string second = "")
{
    int s;
    cout << "Enter the the values in the " << second << " list(to stop enter '-1'): ";
    cin >> s;
    while (s != -1)
    {
        l.addEndNode(s);
        cin >> s;
    }
    cout << "Your entered list: ";
    l.display();
}

int main()
{
    int choice;
    char cont;
    int value;
    do
    {
        cout << "\nChoose what you want to perform: \n";
        cout << "1. Insert an element in the beginning of linked list\n";
        cout << "2. Insert an element at the end of the linked list\n";
        cout << "3. Insert an element at given position of linked list\n";
        cout << "4. Remove an element from beginning of the linked list\n";
        cout << "5. Remove an element from the tail of the linked list\n";
        cout << "6. Remove a given element from linked list\n";
        cout << "7. Search an element in the linked list\n";
        cout << "8. Concatenate two linked list\n";
        cout << "Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int x;
            CircularList c;
            takeInput(c);
            cout << "Enter the element to insert in beginning: ";
            cin >> x;
            c.addNode(x, 1);
            cout << "The linked list after insertion: ";
            c.display();
            break;
        }
        case 2:
        {
            int x;
            CircularList c;
            takeInput(c);
            cout << "Enter the element to insert in end: ";
            cin >> x;
            c.addEndNode(x);
            cout << "The linked list after insertion: ";
            c.display();
            break;
        }
        case 3:
        {
            int x;
            int j;
            CircularList c;
            takeInput(c);
            cout << "Enter the position on which you want to insert: ";
            cin >> j;
            cout << "Enter the element to insert: ";
            cin >> x;
            c.addNode(x, j);
            cout << "The linked list after insertion: ";
            c.display();
            break;
        }
        case 4:
        {
            CircularList c;
            takeInput(c);
            cout << "The linked list after removal of first element: ";
            c.removeFirst();
            c.display();
            break;
        }
        case 5:
        {
            CircularList c;
            takeInput(c);
            cout << "The linked list after removal of element from the end: ";
            c.removeTail();
            c.display();
            break;
        }
        case 6:
        {
            int j;
            CircularList c;
            takeInput(c);
            cout << "Enter the element to remove from the list: ";
            cin >> j;
            cout << "The linked list after removal of element " << j << ": ";
            c.removeNode(j);
            c.display();
            break;
        }
        case 7:
        {
            CircularList c;
            Node *p;
            takeInput(c);
            cout << "Enter the element to search: ";
            cin >> value;
            p = c.searchElem(value);
            if (p != NULL)
                cout << " and at the node with address: " << p << endl;
            else
            {
                cout << "Not found\n";
            }
            break;
        }
        case 8:
        {
            CircularList c;
            takeInput(c, "first");
            CircularList c1;
            takeInput(c1, "second");
            c.concatenate(c1);
            cout << "The list after concatenation is: ";
            c.display();
            break;
        }
        default:
            cout << "Invalid choice!!!";
        }
        cout << "Do you want to continue(Y/N):";
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');
    return 0;
}
