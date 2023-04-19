//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DisplaySmall()  
// Description   :  Singly Linear Linked List
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

class SinglyLL
{
    public:
    PNODE First;   //charactristics
    int iCount;

    SinglyLL();
        void InsertAtFirst(int No);
        void InsertAtLast(int No);
        void InsertAtPos(int No,int iPos);

        void DeleteAtFirst();
        void DeleteAtLast();
        void DeleteAtPos(int iPos);

        void Display();

};

SinglyLL :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

void SinglyLL :: InsertAtFirst(int No)
{
    // Step1 : Allocate memory for node
    PNODE Newn = new NODE;

    // Step2 : Initialise node
    Newn->Data = No;
    Newn->Next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = Newn;
        iCount++;
    }
    else    // If LL contains atleast one node
    {
        Newn->Next = First;
        First = Newn;
        iCount++;
    }
}
void SinglyLL :: InsertAtLast(int No)
{
    PNODE Newn = new NODE;

    Newn->Data = No;
    Newn->Next = NULL;

    if(First == NULL)
    {
        First = Newn;
        iCount++;
    }
    else
    {
        PNODE temp = First;
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = Newn;
        iCount++;
    }
}
void SinglyLL :: InsertAtPos(int No,int iPos)
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
        Newn->Next = temp->Next;
        temp->Next = Newn;
        iCount++;
    }
}

void SinglyLL :: DeleteAtFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> Next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;
        First = First -> Next;
        delete temp;
        iCount--;
    }
}
void SinglyLL :: DeleteAtLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->Next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
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
void SinglyLL :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount +1))
    {
        cout<<"Invalid Position"<<"\n";
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
        int iCnt = 0;

        for(iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            temp1 = temp1->Next;
        }
        PNODE temp2 = temp1->Next;
        temp1->Next = temp2->Next;
        delete temp2;
        iCount--;

    }

}

void SinglyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->Data<<" |->";
        temp = temp->Next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    SinglyLL obj1;

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

    obj1.InsertAtPos(151,2);
    obj1.InsertAtPos(221,4);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtFirst();

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtLast();

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtPos(3);

    obj1.Display();
    cout<<"No of Nodes of linked List are: "<<obj1.iCount<<"\n";



    
}
