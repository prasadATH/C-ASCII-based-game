#ifndef LINKEDLIST
#define LINKEDLIST


typedef struct ListNode
{
    int value;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;


typedef struct
{
    ListNode* head;
    ListNode* tail;
    int count;
} CIntlinkedList;




CIntlinkedList* createLinkedList();

void insertFirst( CIntlinkedList*, int);
void insertLast(CIntlinkedList*, int);
void printLinkedlist(CIntlinkedList*);
int removeFirst( CIntlinkedList* );
int removeLast( CIntlinkedList* );
int peekLast( CIntlinkedList* );
int peekFirst( CIntlinkedList* );
int peekBeforeLast( CIntlinkedList* );
void freeList(CIntlinkedList*);




#endif