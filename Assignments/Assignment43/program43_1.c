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
//  Function Name : DisplayPerfect
//  Description :   It displays the perfect numbers in the linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Nidhi Girish Kadival
//  Date :          16/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayPerfect(PNODE first)
{
    int iNo = 0, iSum = 0, iCnt = 0;

    while (first != NULL)
    {
        iNo = first->data;
        iSum = 0;

        for (iCnt = 1; iCnt <= iNo/2; iCnt++)
        {
            if (iNo % iCnt == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        if (iSum == iNo)
        {
            printf("| %d |->",iNo);
        }

        first = first->next;
    }
    printf("NULL\n");
}

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

    InsertLast(&head, 11);
    InsertLast(&head, 28);
    InsertLast(&head, 17);
    InsertLast(&head, 41);
    InsertLast(&head, 6);
    InsertLast(&head, 89);

    printf("Perfect numbers:\n");
    DisplayPerfect(head);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases successfully handled by the application
//
//  Perfect numbers:
//  | 28 |->| 6 |->NULL
//
/////////////////////////////////////////////////////////////////////////////////////////////////