#include<iostream>
using namespace std;

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> * next;
    struct DoublyCLLnode<T> * prev;
};

template <class T>
class DoublyCLL
{
    private:
    struct DoublyCLLnode<T> * first;
    struct DoublyCLLnode<T> * last;
    int iCount;

    public:
        DoublyCLL();
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
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside constructor of DoublyCLL()\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T>  *  newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> *  newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last; 
    
    this->iCount++;
    
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
    }

    this->last->next = this->first;
    this->first->prev = this->last; 
    
    this->iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
    }

    this->last->next = this->first;
    this->first->prev = this->last; 
    
    this->iCount--;
}

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> *  temp = NULL;

    temp = this->first;

    cout<<"NULL <=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    while(temp != this->last->next);

    cout<<"NULL\n";

}

template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> *  temp = NULL;
    struct DoublyCLLnode<T> *  newn = NULL;

    int iCnt = 0;

    if((pos<1) || (pos>iCount+1))
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
        newn = new struct DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        temp = this->first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> *  temp = NULL;

    int iCnt = 0;

    if((pos<1) || (pos>iCount))
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

        temp->next = temp->next->next;

        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;

    }

}        

int main()
{
    DoublyCLL<int> sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    
    sobj.InsertAtPos(105,5);

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteAtPos(5);

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteFirst();

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteLast();

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}