#include<iostream>
using namespace std;

template <class T>
struct SinglyCLLDoublyCLLnode 
{
    T data;
    struct SinglyCLLDoublyCLLnode<T> * next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLDoublyCLLnode<T> * first;
        struct SinglyCLLDoublyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
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
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL()\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    struct SinglyCLLDoublyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLDoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

template <class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    struct SinglyCLLDoublyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLDoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = NULL;
    }
    this->iCount--;
}

template <class T>
void SinglyCLL<T> :: DeleteLast()
{
    struct SinglyCLLDoublyCLLnode<T> * temp = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        this->last = temp;
    }
    this->last->next = this->first;
    this->iCount--;
}

template <class T>
void SinglyCLL<T> :: Display()
{
    struct SinglyCLLDoublyCLLnode<T> * temp = NULL;

    temp = this->first;

    do
    {
        cout<<" | "<<temp->data<<" | ->";
        temp = temp->next;
    }
    while(temp != this->last->next);
    cout<<"NULL\n";
}

template <class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

template <class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct SinglyCLLDoublyCLLnode<T> * temp = NULL;
    int iCnt = 0;

    if((pos<1) || (pos>this->iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct SinglyCLLDoublyCLLnode<T> * newn = NULL;

        newn = new struct SinglyCLLDoublyCLLnode<T>;

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
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    struct SinglyCLLDoublyCLLnode<T> * temp = NULL;
    struct SinglyCLLDoublyCLLnode<T> * target = NULL;
    int iCnt = 0;

    if((pos<1) || (pos>this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
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
    SinglyCLL<int> ssobj;
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