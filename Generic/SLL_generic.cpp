#include<iostream>
using namespace std;

template <class T>
struct SinglyLLLDoublyCLLnode
{
    T data;
    struct SinglyLLLDoublyCLLnode<T> * next;
};

template <class T>
class SinglyLLL
{
    private:
        struct SinglyLLLDoublyCLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);        
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Inside constructor of SinglyLLL()\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    struct SinglyLLLDoublyCLLnode<T> * newn = NULL;

    newn = new struct SinglyLLLDoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else 
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->iCount++;
}

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    struct SinglyLLLDoublyCLLnode<T> * newn = NULL;
    struct SinglyLLLDoublyCLLnode<T> * temp = NULL;

    newn = new struct SinglyLLLDoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    this->iCount++;
}

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    struct SinglyLLLDoublyCLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first->next;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        
        this->first = this->first->next;

        delete temp;
    }
    this->iCount--;
}

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    struct SinglyLLLDoublyCLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first->next;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

template <class T>
void SinglyLLL<T> :: Display()
{
    struct SinglyLLLDoublyCLLnode<T> * temp = NULL;

    temp = this->first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    struct SinglyLLLDoublyCLLnode<T> * newn = NULL;
    struct SinglyLLLDoublyCLLnode<T> * temp = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyLLLDoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    struct SinglyLLLDoublyCLLnode<T> * temp = NULL;
    struct SinglyLLLDoublyCLLnode<T> * target = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}

int main()
{
    SinglyLLL<int> ssobj;
    int iRet = 0;

    ssobj.InsertFirst(51);
    ssobj.InsertFirst(21);
    ssobj.InsertFirst(11);
    
    ssobj.InsertLast(101);
    ssobj.InsertLast(111);
    ssobj.InsertLast(121);
    
    ssobj.InsertAtPos(105,5);

    ssobj.Display();
    
    iRet = ssobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    ssobj.DeleteAtPos(5);

    ssobj.Display();
    
    iRet = ssobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    ssobj.DeleteFirst();

    ssobj.Display();
    
    iRet = ssobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    ssobj.DeleteLast();

    ssobj.Display();
    
    iRet = ssobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}