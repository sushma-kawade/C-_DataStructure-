#include<iostream>
using namespace std;

#pragma pack(1)
struct Node
{
    int Data;
    struct Node *Next;
    struct Node *Prev;
};
typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

class DoublyLL
{
    public:
    PNODE First;   //charactristics
    int iCount;

    DoublyLL();
    void InsertAtFirst(int No);
    void InsertAtLast(int No);
    void InsertAtPos(int No,int iPos);

    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAtPos(int iPos);

    void Display();

};
DoublyLL :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

void DoublyLL::InsertAtFirst(int No)
{
    PNODE Newn = new NODE;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Prev = NULL;

    if(First == NULL)
    {
        First = Newn;
    }
    else
    {
        Newn->Next = First;
        First->Prev = Newn;
        First = Newn;
        iCount++;
    }

}
void DoublyLL :: InsertAtLast(int No)
{
    PNODE Newn = new NODE;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Prev = NULL;

    PNODE temp = First;

    if(First == NULL)
    {
        First = Newn;
    }
    else
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = Newn;
        Newn->Prev = temp;
        iCount++;

    }
}
void DoublyLL :: InsertAtPos(int No, int iPos)
{
    if((iPos < 1) || (iPos > iCount +1))
    {
        cout<<"Invalid Position"<<"\n";
    }
    if(iPos == 1)
    {
        InsertAtFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertAtLast(No);
    }
    else
    {
        int iCnt = 0;
        PNODE Newn = new NODE;

        Newn->Data = No;
        Newn->Next = NULL;

        PNODE temp = First;
        for(iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            temp = temp->Next;
        }
        Newn->Next = temp -> Next;
        temp->Next->Prev = Newn;    // X
        temp->Next = Newn;
        Newn->Prev = temp; 
        iCount++;
    }
}
void DoublyLL :: DeleteAtFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next== NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        First = First->Next;
        delete temp -> Prev;
        First->Prev = NULL;
        iCount--;
    }
}
void DoublyLL :: DeleteAtLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;

        while(temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        delete temp->Next;
        temp->Next = NULL;
        iCount--;
    }
}
void DoublyLL:: DeleteAtPos(int iPos)
{

    if((iPos <1) || (iPos > iCount + 1))
    {
        return;
    }
    else if(iPos == 1)
    {
        DeleteAtFirst();
    }
    else if(iPos == iCount + 1)
    {
        DeleteAtLast();
    }
    else
    {
        int iCnt = 0;
        PNODE temp2 = NULL;
        PNODE temp1 = First;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->Next;
        }
        temp2 = temp1->Next;
        temp1->Next = temp2->Next;
        temp2->Next->Prev = temp1;
        delete temp2;
        iCount--;

    }
}
void DoublyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    cout<<"NULL"<<"<=>";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->Data<<" |<=>";
        temp = temp->Next;
    }
    cout<<"NULL"<<"\n";
}
int main()
{  
    DoublyLL obj1;
    obj1.InsertAtFirst(30);
    obj1.InsertAtFirst(20);
    obj1.InsertAtFirst(10);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtLast(40);
    obj1.InsertAtLast(50);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtPos(15,2);
    obj1.InsertAtPos(25,4);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtFirst();

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtLast();

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtPos(4);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";





}