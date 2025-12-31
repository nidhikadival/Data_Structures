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
//  Date :          31/12/2025
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
        *first = newn;
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
//  Date :          31/12/2025
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
        *first = newn;
    }
    else
    {
        temp = *first;

        while((temp)->next != NULL)
        {
            temp = (temp)->next;
        }
        (temp)->next = newn;
    }
} // End of InsertLast

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteFirst
//  Description :   It deletes the first element of the linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          31/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        (*first) = NULL;
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
//  Date :          31/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        (*first) = NULL;
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
//  Date :          31/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
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
//  Date :          31/12/2025
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
//  Date :          31/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;

    iSize = Count(*first);

    if((pos<1) || (pos>iSize+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if (pos == iSize+1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;

        newn = (PNODE) malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

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
//  Date :          31/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCnt = 0;
    int iSize = 0;

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
    else if (pos == iSize)
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
//  Function Name : DisplayOdd
//  Description :   It displays the odd elements in the linked list
//  Input :         PNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          31/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayOdd(PNODE head)
{
    while(head!=NULL)
    {
        if((head->data)%2 != 0)
        {
            printf("| %d | ",head->data);
        }
        head = head->next;
    }
    printf("\n");
} // End of DisplayOdd

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Entry point function for the application
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;
    bool bRet = false;
    int no = 0;

    InsertFirst(&head,11);
    InsertFirst(&head,10);
    InsertFirst(&head,10);

    Display(head);
    iRet = Count(head);
    printf("No of nodes are: %d\n",iRet);

    InsertLast(&head,30);
    InsertLast(&head,31);
    InsertLast(&head,51);

    Display(head);
    iRet = Count(head);
    printf("No of nodes are: %d\n",iRet);

    printf("Odd Elements: \n");
    DisplayOdd(head);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases successfully handled by the application
//
//  Output:
//  | 10 | -> | 10 | -> | 11 | -> NULL
//  No of nodes are: 3
//  | 10 | -> | 10 | -> | 11 | -> | 30 | -> | 31 | -> | 51 | -> NULL
//  No of nodes are: 6
// 
//  Odd Elements: 
//  | 11 | | 31 | | 51 |  
//
/////////////////////////////////////////////////////////////////////////////////////////////////