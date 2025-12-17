/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Required header files
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : InsertLast
//  Description :   It inserts elements at the last index
//  Input :         PPNODE, int
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          16/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL) // LL is empty
    {
        *first = newn;
    }
    else // LL contains atleast one node
    {
        temp = *first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
} // End of InsertLast

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Description :   It displays all elements in the linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          16/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d |->", first->data);
        first = first->next;
    }
    printf("NULL\n");
} // End of Display

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name : SecMaximum
//  Description :   It return second maximum of all elements in the linked list
//  Input :         PPNODE
//  Output :        Int
//  Author :        Nidhi Girish Kadival
//  Date :          16/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

int SecMaximum(PNODE first)
{
    int iMax = first->data;
    int iSecMax = first->data;

    while (first != NULL)
    {
        if (first->data > iMax)
        {
            iSecMax = iMax;
            iMax = first->data;
        }
        else if (first->data > iSecMax && first->data != iMax)
        {
            iSecMax = first->data;
        }
        first = first->next;
    }

    return iSecMax;
} // End of SecMaximum

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Entry point function for the application
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iValue = 0;
    int iRet = 0;

    InsertLast(&head, 110);
    InsertLast(&head, 230);
    InsertLast(&head, 320);
    InsertLast(&head, 240);

    Display(head);

    iRet = SecMaximum(head);
    printf("Second maximum number : %d\n", iRet);
    

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases successfully handled by the application
//
//  Output:  
//  | 110 |->| 230 |->| 320 |->| 240 |->NULL
//  Second maximum number : 240
//
/////////////////////////////////////////////////////////////////////////////////////////////////