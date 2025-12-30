// Singly Circular Linked List
#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:

        SinglyCL()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

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
            this->last->next = first;

            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            
            newn->data = no;
            newn->next = NULL;

            if((this->first == NULL)&&(this->last == NULL))
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                this->last->next = newn;
                this->last = newn;
            }
            this->last->next = first;

            this->iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

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
                temp = this->first;
                this->first = this->first->next;
                delete temp;
            }
            this->last->next = first;

            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

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
                temp = this->first;

                while(temp->next != this->last)
                {
                    temp = temp->next;
                }
                this->last = temp;

                delete temp->next;
            }
            this->last->next = this->first;

            this->iCount--;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;

            PNODE temp = NULL;
            
            PNODE newn = NULL;

            if((pos<1) || (pos>iCount+1))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if( pos == iCount+1 )
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

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

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

            if((pos<1) || (pos>iCount))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if( pos == iCount )
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

                free(target);

                this->iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = this->first;

            do
            {
                cout<<" | "<<temp->data<<" | ->";
                temp = temp->next;
            }
            while(temp != this->last->next);
            cout<<"NULL\n";

        }

        int Count()
        {
            return this->iCount;
        }
};

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    return 0;
}