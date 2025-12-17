/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Required header files
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
//  Function Name : IsPrime
//  Description :   checks if the number is prime 
//  Input :         Int
//  Output :        Bool
//  Author :        Nidhi Girish Kadival
//  Date :          16/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

bool IsPrime(int iNo)
{
    int iCnt = 0;

    if (iNo < 2)
    {
        return false;
    }

    for (iCnt = 2; iCnt <= iNo / 2; iCnt++)
    {
        if (iNo % iCnt == 0)
        {
            return false;
        }
    }
    return true;
} // End of IsPrime

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
        if (IsPrime(first->data) == true)
        {
            printf("| %d |->", first->data);
        }
        
        first = first->next;
    }
    printf("NULL\n");
} // End of Display

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
    InsertLast(&head, 20);
    InsertLast(&head, 31);
    InsertLast(&head, 41);
    InsertLast(&head, 55);
    InsertLast(&head, 60);
    InsertLast(&head, 7);

    printf("Prime numbers : \n");
    Display(head);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases successfully handled by the application
//
//  Prime numbers : 
//  | 11 |->| 31 |->| 41 |->| 7 |->NULL
//
/////////////////////////////////////////////////////////////////////////////////////////////////