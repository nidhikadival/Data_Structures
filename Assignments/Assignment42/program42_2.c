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
//  Function Name : SearchLastOcc
//  Description :   It returns the index of the last occurence of an element 
//  Input :         PPNODE, Int
//  Output :        Int
//  Author :        Nidhi Girish Kadival
//  Date :          16/12/2025
// 
/////////////////////////////////////////////////////////////////////////////////////////////////

int SearchLastOcc(PNODE first, int iNo)
{
    int iCount = 0, iLastOcc = -1;

    while (first != NULL)
    {
        if (first->data == iNo)
        {
            iLastOcc = iCount;
        }
        iCount++;
        first = first->next;
    }

    return iLastOcc;
} // End of SearchLastOcc

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

    InsertLast(&head, 10);
    InsertLast(&head, 20);
    InsertLast(&head, 30);
    InsertLast(&head, 40);
    InsertLast(&head, 50);
    InsertLast(&head, 30);
    InsertLast(&head, 70);

    Display(head);

    printf("Enter number to search : \n");
    scanf("%d", &iValue);

    iRet = SearchLastOcc(head, iValue);
    if(iRet == -1)
    {
        printf("Element is not present\n");
    }
    else
    {
        printf("Last occurence of %d is at index : %d\n", iValue, iRet);
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases successfully handled by the application
//
//  | 10 |->| 20 |->| 30 |->| 40 |->| 50 |->| 30 |->| 70 |->NULL
//  Enter number to search : 
//  30
//  Last occurence of 30 is at index : 5
//
//  | 10 |->| 20 |->| 30 |->| 40 |->| 50 |->| 30 |->| 70 |->NULL
//  Enter number to search : 
//  33
//  Element is not present
//
/////////////////////////////////////////////////////////////////////////////////////////////////