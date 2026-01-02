/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Required header files
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : InserFirst
//  Description :   It inserts elements at the first index
//  Input :         PPNODE, int
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        (*first) = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
} // End of InsertFirst

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : InsertLast
//  Description :   It inserts elements at the last index
//  Input :         PPNODE, int
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE) malloc(sizeof(NODE));
    
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        (*first) = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }    
} // End of InsertLast

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteFirst
//  Description :   It deletes the first element of the linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
} // End of DeleteFirst

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteLast
//  Description :   It deletes the last element of the linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
} // End of DeleteLast

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Description :   It displays all the elements of the linked list
//  Input :         PNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |-> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
} // End of Display

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : Count
//  Description :   It returns the no of elements in the linked list
//  Input :         PNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
} // End of Count

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : InsertAtPos
//  Description :   It inserts elements at the given position
//  Input :         PPNODE, int, int
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE newn = NULL;

    iSize = Count(*first);

    if((pos<1) || (pos>iSize+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE) malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
} // End of InsertAtPos

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteAtPos
//  Description :   It deletes the element at given position
//  Input :         PPNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first);

    if((pos<1) || (pos>iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt=1; iCnt<pos-1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }
} // End of DeleteAtPos

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : MakeAbsolute
//  Description :   It converts negative elements into positive
//  Input :         PNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          02/01/2026
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void MakeAbsolute(PPNODE head)
{
    PNODE temp = NULL;

    temp = *head;

    while(temp != NULL)
    {
        if(temp->data < 0 )
        {
            temp->data = -(temp->data);
        }

        temp = temp->next;
    }

} // End of MakeAbsolute

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Entry point function for the application
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    int iRet = 0;

    InsertFirst(&head,20);
    InsertFirst(&head,11);
    InsertFirst(&head,10);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are: %d\n",iRet);

    InsertLast(&head,-21);
    InsertLast(&head,-30);
    InsertLast(&head,-31);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are: %d\n",iRet);

    MakeAbsolute(&head);

    Display(head);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases successfully handled by the application
//
//  Output:
//  | 10 |-> | 11 |-> | 20 |-> NULL
//  Number of nodes are: 3
//  | 10 |-> | 11 |-> | 20 |-> | -21 |-> | -30 |-> | -31 |-> NULL
//  Number of nodes are: 6
//  | 10 |-> | 11 |-> | 20 |-> | 21 |-> | 30 |-> | 31 |-> NULL
//
/////////////////////////////////////////////////////////////////////////////////////////////////