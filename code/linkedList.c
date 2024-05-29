/*
 NAME: Thilina Athukorala 
 PURPOSE: to control the undo feature of the game by storing each move of player and the blocks created. 
 (built for practical sheet 7 based on the lecture slides)
 MODIFIED : 2022-10-16
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedList.h"

/* ============================================================
**    Function: createLinkedList()
**    purpose: Initialise a new linked list.
**      Imports: none
**      Export: none
** ============================================================ */
CIntlinkedList* createLinkedList()
{
    CIntlinkedList* list = (CIntlinkedList*)malloc( sizeof(CIntlinkedList) );
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    return list;
}

/* =======================================================================
**    Function: insertFirst()
**    purpose: Insert a new node to the first position of the linked list.
**      Imports: CIntlinkedList* list, int inValue 
**      Export: none
** ======================================================================= */
void insertFirst( CIntlinkedList* list, int inValue )
{
    ListNode* newNode = (ListNode*)malloc( sizeof(ListNode) );
    ListNode* prevHead;


    newNode->value = inValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if( list->head == NULL )
    {

        list->head = newNode;
        list->tail = newNode;
    }
    else
    {

        newNode->next = list->head;
        prevHead = newNode->next;
        prevHead->prev = newNode;

        list->head = newNode;

    }

    list->count += 1;

      
}
/* ============================================================
**    Function: insertLast()
**    purpose: Insert a new node to the  end of linked list.
**      Imports: CIntlinkedList* list, int inValue 
**      Export: none
** ============================================================ */
void insertLast( CIntlinkedList* list, int inValue )
{
    ListNode* newNode = (ListNode*)malloc( sizeof(ListNode) );
    ListNode* prevTail;


    newNode->value = inValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if( list->head == NULL )
    {

        list->head = newNode;
        list->tail = newNode;
    }
    else
    {

        newNode->prev = list->tail;
        prevTail = newNode->prev;
        prevTail->next = newNode;

        list->tail = newNode;
    }

    list->count += 1;

    

}

/* ============================================================
**    Function: peekLast()
**    purpose: return the last element of the linked list.
**      Imports: CIntlinkedList* list 
**      Export: int (lastnode)
** ============================================================ */

int peekLast(CIntlinkedList* list)
{
    return ((list->tail)->value);

}


/* ============================================================
**    Function: peekFirst()
**    purpose: return the first element of the linked list.
**      Imports: CIntlinkedList* list 
**      Export: int (firstnode)
** ============================================================ */
int peekFirst(CIntlinkedList* list)
{
    return ((list->head)->value);

}

/* ============================================================
**    Function: peekBeforeLast()
**    purpose: return the one before last element of the linked list.
**      Imports: CIntlinkedList* list 
**      Export: int (node before the last node)
** ============================================================ */
int peekBeforeLast(CIntlinkedList* list)
{
    return (((list->tail)->prev)->value);

}


/* ==================================================================
**    Function: removeFirst()
**    purpose: remove and return the first element of the linked list.
**      Imports: CIntlinkedList* list 
**      Export: int (first node)
** ================================================================== */

int removeFirst( CIntlinkedList* list )
{
    int nodeValue;
    ListNode* prevHead;

    if( list->count == 0 )
    {
        nodeValue = 0;
    }
    else if( list->count == 1 )
    {
        nodeValue = ( list->head )->value;
        prevHead = list->head;

        list->head = NULL;
        list->tail = NULL;
        free( prevHead );
    }
    else
    {
        nodeValue = ( list->head )->value;
        prevHead = list->head;

        list->head = ( list->head )->next;
        list->head->prev = NULL;
        free( prevHead );
    }

    list->count -= 1;

    return nodeValue;
}

/* ==================================================================
**    Function: removeLast()
**    purpose: remove and return the first element of the linked list.
**      Imports: CIntlinkedList* list 
**      Export: int (last node)
** ================================================================== */


int removeLast( CIntlinkedList* list )
{
    int nodeValue;
    ListNode* prevTail;

    if( list->count == 0 )
    {
        nodeValue = 0;
    }
    else if( list->count == 1 )
    {
        nodeValue = ( list->tail )->value;
        prevTail = list->tail;

        list->head = NULL;
        list->tail = NULL;
        free( prevTail );
    }
    else
    {
        nodeValue = ( list->tail )->value;
        prevTail = list->tail;

        list->tail = ( list->tail )->prev;
        list->tail->next = NULL;
        free( prevTail );
    }

    list->count -= 1;

    return nodeValue;
}
/* ==================================================================
**    Function: printLinkedlist()
**    purpose: prints the elements of the linked list.
**      Imports: CIntlinkedList* list 
**      Export: none
** ================================================================== */
void printLinkedlist(CIntlinkedList* list)
 {
     ListNode* temp = list->head;
  
  while ((temp) != NULL)
   {
    printf("%d ", ((temp)->value));
    temp = (temp)->next;
  }
}
/* ========================================================================
**    Function: freeList()
**    purpose: Frees all the dynamically allocated memories in linked list 
**             and the list itself.
**      Imports: CIntlinkedList* list 
**      Export: none
** ======================================================================== */

void freeList( CIntlinkedList* list )
{
    ListNode* currNode = list-> head;
    ListNode* prevNode;
    while(currNode != NULL)
    {
       
        prevNode = currNode;
        currNode = (currNode->next);
        free(prevNode);
    }
    free(list);


}