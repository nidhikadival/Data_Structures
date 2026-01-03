#include<iostream>
using namespace std;

template <class T>
struct DoublyLLLnode 
{
    T data;
    struct DoublyLLLnode<T> * next;
    struct DoublyLLLnode<T> * prev;
};

template <class T>
class DoublyLLL
{
    private:
        struct DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();
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
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Inside constructor of DoublyLLL()\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;
    struct DoublyLLLnode<T> * temp = NULL;

    newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

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
        newn->prev = temp;
    }
    this->iCount++;
}

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    struct DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
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
void DoublyLLL<T> :: Display()
{
    struct DoublyLLLnode<T> * temp = NULL;

    temp = this->first;

    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyLLLnode<T> * newn = NULL;
    struct DoublyLLLnode<T> * temp = NULL;
    
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
        newn = new struct DoublyLLLnode<T>;

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
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if((pos<1)||(pos>iCount))
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
    DoublyLLL<int> ssobj;
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