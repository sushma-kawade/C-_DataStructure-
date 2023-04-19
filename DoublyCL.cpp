//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DisplaySmall()  
// Description   :  Doubly Circular Linked List
// Input         :  Integer
// Output        :  Integer
// Author        :  Sushma Kawade
// Date          :  5 feb 2023
//
////////////////////////////////////////////////////////////////////////////


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
typedef struct Node *PNODE;
typedef struct Node **PPNODE;

class DoublyCL
{
    public:
    PNODE First;
    PNODE Last;
    int iCount;

    DoublyCL();
    void InsertAtFirst(int No);
    void InsertAtLast(int No);
    void InsertAtPos(int No,int iPos);

    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAtPos(int No);

    void Display();
};

DoublyCL :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}
void DoublyCL :: InsertAtFirst(int No)
{
    PNODE Newn = new NODE;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Prev = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Newn;
        Last = Newn;
    }
    else
    {
        Last-> Next = Newn;
        Newn->Prev = Last;
        Last = Newn;
    }

    First->Prev = Last;
    Last->Next = First;
    iCount++;
}

void DoublyCL :: InsertAtLast(int No)
{
    PNODE Newn = new NODE;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Next = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Newn;
        Last = Newn;
    }
    else
    {
        Last->Next = Newn;
        Newn->Prev = Last;
        Newn->Next = First;
        Last = Newn;
        iCount++;
    }
}

void DoublyCL :: InsertAtPos(int No,int iPos)
{
    PNODE Newn = new NODE;

    Newn->Data = No;
    Newn->Next = NULL;
    Newn->Prev = NULL;

    if((iPos < 1) || (iPos > iCount +1))
    {
        return;
    }
    else if(iPos == 1)
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
        PNODE temp = First;

        for(iCnt = 1; iCnt <iPos-1; iCnt++)
        {
            temp = temp->Next;
        }
        
        Newn->Next = temp->Next;
        temp->Next->Prev = Newn;

        temp->Next = Newn;
        Newn->Prev = temp;
        iCount++;
    }
}
void DoublyCL :: DeleteAtFirst()
{
    if((First == NULL) && (Last== NULL))
    {
        return;
    }

    else if(First == Last)
    {
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->Next;
        First->Prev = Last;
        delete Last->Next;
        Last->Next = First;
        iCount--;
    }
}

void DoublyCL :: DeleteAtLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        First = NULL;
        Last == NULL;
    }
    else
    {
        Last = Last->Prev;
        delete First->Prev;

        First->Prev = Last;
        Last->Next = First;
        iCount--;
    }
}
void DoublyCL ::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount +1))
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
void DoublyCL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;

    do
    {
        cout<<"|"<<temp->Data<<"|<=>";
        temp = temp->Next;
    }while(temp != Last->Next);
    cout<<"\n";
}

int main()
{
    DoublyCL obj1;
    obj1.InsertAtFirst(10);
    obj1.InsertAtFirst(20);
    obj1.InsertAtFirst(30);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtLast(40);

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

    obj1.DeleteAtPos(2);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";




}