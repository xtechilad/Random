/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Addition of two large intergers using Doubly Linked Lists 
*/

#include<iostream>
using namespace std;

class Node{
    public:
    int elem;
    Node *prev=NULL;
    Node *next=NULL;
    friend class LargeInt;
};

class LargeInt{
    Node *head, *tail;
    public:
    LargeInt();
    void addTailNode(int val);
    void addBegNode(int val);

    void stringToInt(string s);
    bool empty() const;

    LargeInt operator+(const LargeInt& l);
    friend ostream& operator<<(ostream&, const LargeInt& l);
};

LargeInt::LargeInt()
{
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->prev=head;
}
void LargeInt:: addTailNode(int val)
{
    Node *temp = new Node;
    temp->elem=val;
    tail->prev->next=temp;
    temp->prev=tail->prev;
    temp->next=tail;
    tail->prev=temp;

}
void LargeInt :: addBegNode(int val)
{
    Node *temp = new Node;
    temp->elem=val;
    temp->prev=head;
    temp->next=head->next;
    head->next=temp;
    temp->next->prev=temp;
}

bool LargeInt::empty() const
{
    return head->next==tail;
}

void LargeInt::stringToInt(string s)
{
    int count=0;
    string num, tempNum;
    bool added;
    for (int i = s.length()-1; i>=0; i--)
    {
        added=false;
        tempNum+=s[i];
        count++;
        if(count%4==0)
        {
            for(int j=3; j>=0; j--)
                num+=tempNum[j];

            addBegNode(stoi(num));
            added=true;   
            num="";
            tempNum="";
        }
        else
        {
            added=false;
        }
    }
    if(added==false)
    {
        for(int j=tempNum.length()-1; j>=0; j--)
            num+=tempNum[j];
        addBegNode(stoi(num));
    }
            

}

LargeInt LargeInt::operator+(const LargeInt& li)
{
    if(li.empty())
        return *this;
    if(this->empty())
        return li;
    LargeInt li2;
    Node *p1=this->tail->prev;
    Node *p2=li.tail->prev;
    int c=0, sum;
    while (p1!=this->head || p2!=li.head)
    {
        if(p1==this->head)
        {
            sum=(c+p2->elem)%10000;
            c=(c+p2->elem)/10000;
            p2=p2->prev;
        }
        else if(p2==li.head)
        {
            sum=(c+p1->elem)%10000;
            c=(c+p1->elem)/10000;
            p1=p1->prev;
        }
        else
        {
            sum=(c+p1->elem+p2->elem)%10000;
            c=(c+p1->elem+p2->elem)/10000;
            p1=p1->prev;
            p2=p2->prev;
        }
        
        li2.addBegNode(sum);
    }

    if(c!=0)
        li2.addBegNode(c);

    return li2;
}

ostream& operator<<(ostream& out, const LargeInt& li)
{
    if(li.empty()){
        out<<0;
        return out;
    }
    Node *temp=li.head->next;
    while (temp!=li.tail)
    {
        out<<temp->elem;
        temp=temp->next;
    }
    return out;
}


int main()
{
    string number;
    LargeInt N1, N2, N3;
    cout<<"Enter the first large integer: ";
    cin>>number;
    N1.stringToInt(number);
    cout<<"The first number is: "<<N1<<endl;

    cout<<"Enter the second large integer: ";
    cin>>number;
    N2.stringToInt(number);
    cout<<"The second number is: "<<N2<<endl;
 
    N3 = N1 + N2;
    cout<<"Result : "<<N3<<endl;

    return 0;
}