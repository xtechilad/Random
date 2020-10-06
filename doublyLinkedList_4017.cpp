/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Doubly linked list implementation
*/

#include<iostream>
using namespace std;

class Node
{
    int elem;
    Node* next;
    Node* prev;
    public:
    Node()
    {
        next=NULL;
        prev=NULL;
    }
    friend class DoubleLinkedList;
};

class DoubleLinkedList
{
    Node* header = new Node;
    Node* trailer = new Node;
    public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void addTail(int x);
    void addAtPos(int x, int pos);

    void removeFromPos(int pos);
    void removeTail();

    Node* searchElem(int x);
    void concatenate(DoubleLinkedList& d2);
    void display();

};

DoubleLinkedList::DoubleLinkedList()
{
    header->next=trailer;
    trailer->prev=header;
}

DoubleLinkedList ::~DoubleLinkedList()
{
    if(header!=NULL)
    {
        Node* temp = header->next;
        while(temp!= trailer)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
    }
    
}

void DoubleLinkedList::addAtPos(int x, int pos)
{
    Node* temp = new Node;
    temp->elem = x;
    int count = 1;
    if(pos==1)
    {
        temp->next=header->next;
        temp->prev=header;
        header->next->prev = temp;
        header->next=temp;
    }
    else
    {
        Node* pt = header->next;
        while(count<pos-1 && pt->next!=trailer)
        {
            count++;
            pt=pt->next;
        }   
        temp->next=pt->next;
        temp->prev=pt;
        pt->next->prev = temp;
        pt->next=temp;
    }
    
}

void DoubleLinkedList::addTail(int x)
{
    Node* temp = new Node;
    temp->elem = x;

    temp->prev = trailer->prev;
    temp->next = trailer;
    trailer->prev->next = temp;
    trailer->prev = temp;


}

void DoubleLinkedList::removeTail()
{
    Node* pt= trailer->prev;
    pt->prev->next = trailer;
    trailer->prev =pt->prev;
    delete pt;
}

void DoubleLinkedList::removeFromPos(int pos)
{
    Node* pt= header->next;
    int count=1;
    if(pos==1)
    {
        header->next=pt->next;
        pt->next->prev = header;
        delete pt;
    }
    else
    {
        while(count<pos && pt->next!=trailer)
        {
            count++;
            pt=pt->next;
        }   
        pt->prev->next=pt->next;
        pt->next->prev = pt->prev;
        delete pt;
    }
    
}

Node* DoubleLinkedList :: searchElem(int x)
{
    int count=1;
    Node* pt = header->next;
    while(pt!=trailer)
    {
        if(pt->elem == x)
        {
            cout<<"The required element "<<x<<" is present at position: "<<count;
            return pt;
        }
        pt=pt->next;
        count++;
    }
    return NULL;
}
void DoubleLinkedList::concatenate(DoubleLinkedList& d2)
{
    trailer->prev->next=d2.header->next;
    d2.header->next->prev = trailer->prev;
    trailer=d2.trailer;
    d2.header = d2.trailer = NULL;
    
}
void DoubleLinkedList::display()
{
    if(header==trailer->prev)
    {
        cout<<"Empty list";
    }
    else
    {
        Node* pt=header->next;
        while(pt!=trailer)
        {
            cout<<pt->elem<<" ";
            pt=pt->next;
        }
    }
    cout<<endl;
}

void takeInput(DoubleLinkedList& l, string second="")
{
    int s;
    cout<<"Enter the the values in the "<<second<<" list(to stop enter '-1'): ";
    cin>>s;
    while(s!=-1)
    {
        l.addTail(s);
        cin>>s;
    }
    cout<<"Your entered list: ";
    l.display();
}


int main()
{
    int choice;
    char cont;
    int value;
    do
    {
        cout<<"\nChoose what you want to perform: \n";
        cout<<"1. Insert an element in the beginning of linked list\n";
        cout<<"2. Insert an element at the end of the linked list\n";
        cout<<"3. Insert an element at given position of linked list\n";
        cout<<"4. Remove an element from beginning of the linked list\n";
        cout<<"5. Remove an element from the tail of the linked list\n";
        cout<<"6. Remove an element from given position of linked list\n";
        cout<<"7. Search an element in the linked list\n";
        cout<<"8. Concatenate two linked list\n";
        cout<<"Your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int x;
                DoubleLinkedList d;
                takeInput(d);
                cout<<"Enter the element to insert in beginning: ";
                cin>>x;
                d.addAtPos(x,1);
                cout<<"The linked list after insertion: ";
                d.display();
                break;
            }
            case 2:
            {
                int x;
                DoubleLinkedList d;
                takeInput(d);
                cout<<"Enter the element to insert in end: ";
                cin>>x;
                d.addTail(x);
                cout<<"The linked list after insertion: ";
                d.display();
                break;
            }
            case 3:
            {  
                int x;
                int j; 
                DoubleLinkedList d;
                takeInput(d);
                cout<<"Enter the position on which you want to insert: ";
                cin>>j;
                cout<<"Enter the element to insert: ";
                cin>>x;
                d.addAtPos(x,j);
                cout<<"The linked list after insertion: ";
                d.display();
                break;
            }
            case 4:
            {
                DoubleLinkedList d;
                takeInput(d);
                cout<<"The linked list after removal of first element: ";
                d.removeFromPos(1);
                d.display();
                break;
            }
            case 5:
            {
                DoubleLinkedList d;
                takeInput(d);
                cout<<"The linked list after removal of element from the tail: ";
                d.removeTail();
                d.display();
                break;
            }
            case 6:
            {
                int j;
                DoubleLinkedList d;
                takeInput(d);
                cout<<"Enter the position from which you want to remove the element: ";
                cin>>j;
                cout<<"The linked list after removal of "<<j<<"th element: ";
                d.removeFromPos(j);
                d.display();
                break;
            }
            case 7:
            {
                DoubleLinkedList d;
                Node *p;
                takeInput(d);
                cout<<"Enter the element to search: ";
                cin>>value;
                p = d.searchElem(value);
                if(p!=NULL)
                cout<<" and at the node with address: "<<p<<endl;
                else
                {
                    cout<<"Not found\n";
                }
                
                break;
            }
            case 8:
            {
                DoubleLinkedList d;
                takeInput(d, "first");
                DoubleLinkedList d1;
                takeInput(d1,"second");
                d.concatenate(d1);
                cout<<"The list after concatenation is: ";
                d.display();
                break;
            }
            default:
                cout<<"Invalid choice!!!";
        }
        cout<<"Do you want to continue(Y/N):";
        cin>>cont;
    }while(cont=='Y'||cont=='y');
    return 0;
}
