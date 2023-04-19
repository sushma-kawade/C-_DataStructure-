//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DisplaySmall()  
// Description   :  SinglY Circular Linked List
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
};
typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node**PPNODE;

class SinglyCL
{
    public:
    PNODE First; 
    PNODE Last;  //charactristics
    int iCount;

    SinglyCL();
        void InsertAtFirst(int No);
        void InsertAtLast(int No);
        void InsertAtPos(int No,int iPos);

        void DeleteAtFirst();
        void DeleteAtLast();
        void DeleteAtPos(int iPos);

        void Display();

};

SinglyCL :: SinglyCL()
{
    Last = NULL;
    First = NULL;
    iCount = 0;
}

void SinglyCL :: InsertAtFirst(int No)
{
    PNODE Newn = new NODE;
    Newn -> Data = No;
    Newn -> Next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First= Newn;
        Last = Newn;
    }
    else
    {
        Newn -> Next = First;
        First = Newn;
    }
    Last -> Next = First;
    iCount++;
}
void SinglyCL :: InsertAtLast(int No)
{
    PNODE Newn = new Node;

    Newn->Data = No;
    Newn->Next = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Newn;
        Last = Newn;
    }
    else
    {
        
        Last->Next = Newn;
        Last = Last->Next;
    }
    Last->Next = First;
    iCount++;

}
void SinglyCL::InsertAtPos(int No,int iPos)
{
    PNODE Newn = new Node;

    Newn->Data = No;
    Newn->Next = NULL;

    if((iPos < 1) || (iPos > iCount +1))
    {
        cout<<"Invalid Position :"<<"\n";
    }
    else if(iPos == 1)
    {
        InsertAtFirst(No);
    }
    else if(iPos == iCount +1)
    {
        InsertAtLast(No);
    }
    else
    {
        PNODE temp = First;
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> Next;
        }
        Newn -> Next = temp -> Next;
        temp -> Next = Newn;
        iCount++;
    } 
    
}
void SinglyCL::DeleteAtFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;
        First = First->Next;
        Last->Next = First;
        delete(temp);
        iCount--;
    }
}
void SinglyCL::DeleteAtLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else
    { 
        PNODE temp = First;
        for(int iCnt = 1; iCnt < iCount - 1; iCnt++)
        {
            temp = temp -> Next;
        }
        delete Last;
        Last = temp;
        Last -> Next = First;
        iCount--;
    }
}
void SinglyCL::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
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
        PNODE temp1 = First;
        for(int iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            temp1 = temp1->Next;
        }
        PNODE temp2 = temp1->Next;
        temp1->Next = temp2->Next;
        delete temp2;
        iCount--;

    }
}

void SinglyCL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;
    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << temp -> Data << " <->\t";
        temp = temp -> Next;
    }
    cout << "NULL\n";
}

int main()
{
    SinglyCL obj1;

    obj1.InsertAtFirst(101);
    obj1.InsertAtFirst(51);
    obj1.InsertAtFirst(21);
    obj1.InsertAtFirst(11);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtLast(111);
    obj1.InsertAtLast(121);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.InsertAtPos(151,3);

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

    
