/**
 *
 * sllist.cpp
 * Routines for single linked lists
 *
 */

#include "sllist.h"

sllist* sllist_create(void)
{
    sllist* theIdx;
    theIdx = (sllist*)malloc(sizeof(sllist));
    if (theIdx != nullptr)
    {
        theIdx->head = nullptr;
        theIdx->tail = nullptr;
        theIdx->current = nullptr;
        theIdx->size = 0;
    }
    return theIdx;
}

void sllist_destroy(sllist* theIdx)
{
    lnode* save_next;
    theIdx->current = theIdx->head;
    while(theIdx->current != nullptr)
    {
        save_next = theIdx->current->next;
        free(theIdx->current->data);
        free(theIdx->current);
        theIdx->current = save_next;
    }
    free(theIdx);
}

int sllist_push_front(sllist* theIdx, void* theData)
{
    lnode* theNode;
    theNode = (lnode*)malloc(sizeof(lnode));
    if (theNode == nullptr)
        return -1;
    theNode->data = theData;
    theNode->next = theIdx->head;
    theIdx->head = theNode;
    if (theIdx->size == 0)
        theIdx->tail = theNode;
    theIdx->size++;
    return 0;
}

int sllist_push_back(sllist* theIdx, void* theData)
{
    lnode* theNode;
    theNode = (lnode*)malloc(sizeof(lnode));
    if (theNode ==nullptr)
        return -1;
    theNode->data = theData;
    theNode->next = nullptr;
    if (theIdx->size == 0)
    {
        theIdx->head = theNode;
        theIdx->tail = theNode;
    }
    else
    {
        theIdx->tail->next = theNode;
        theIdx->tail = theNode;
    }
    theIdx->size++;
    return 0;
}

void* sllist_pop_front(sllist* theIdx)
{
    if (theIdx->size == 0)
        return nullptr;
    void* theData = theIdx->head->data;
    lnode* save_head = theIdx->head;
    if (theIdx->size == 1)
    {
        theIdx->head = nullptr;
        theIdx->tail = nullptr;
        //Clear current since it shouldn't be used.
        theIdx->current = nullptr;
    }
    else
    {
        theIdx->head = theIdx->head->next;
    }
    free(save_head);
    theIdx->size--;
    return theData;
}

void* sllist_pop_back(sllist* theIdx)
{
    if (theIdx->size == 0)
        return nullptr;
    void* theData = theIdx->tail->data;
    lnode *save_tail = theIdx->tail;
    if (theIdx->size == 1)
    {
        theIdx->head = nullptr;
        theIdx->tail = nullptr;
        //Clear current since it shouldn't be used.
        theIdx->current = nullptr;
    }
    else
    {
        lnode *new_tail = theIdx->head;
        while(new_tail->next->next != nullptr)
            new_tail = new_tail->next;
        theIdx->tail = new_tail;
        theIdx->tail->next = nullptr;
    }
    free(save_tail);
    theIdx->size--;
    return theData;
}

int sllist_step(sllist* theIdx)
{
    if (theIdx->current == nullptr)
        return 1;
    else
    {
        theIdx->current = theIdx->current->next;
        return 0;
    }
}

void* sllist_read_index(sllist* theIdx, int theRow)
{
    if ( ((theIdx->size - theRow - 1) < 0 ) || (theRow < 0) )
        return nullptr;
    lnode *target;
    target = theIdx->head;
    for(int i = 0; i < theRow; i++)
        target = target->next;
    return (target->data);
}

int sllist_insert_after(sllist* theIdx, int theRow, void* theData)
{
    if ( ((theIdx->size - theRow - 1) < 0 ) || (theRow < 0) )
        return 1;
    lnode* target;
    target = theIdx->head;
    for(int i = 0; i < theRow; i++)
        target = target->next;
    lnode* theNode;
    theNode = (lnode*)malloc(sizeof(lnode));
    if (theNode == nullptr)
        return -1;
    theNode->data = theData;
    theNode->next = target->next;
    target->next = theNode;
    if (theRow == theIdx->size - 1) //if inserting after tail
        theIdx->tail = theNode;
    theIdx->size++;
    return 0;
}

void* sllist_extract_after(sllist* myIdx, int theRow)
{
    if ( ((myIdx->size - theRow - 2) < 0 ) || (theRow < 0) )
        return nullptr;
    lnode *target;
    target = myIdx->head;
    for(int i = 0; i < theRow; i++)
        target = target->next;
    if (theRow == myIdx->size - 1) //if extracting tail
        myIdx->tail = target;
    void* theData = target->next->data;
    lnode* save_obsolete = target->next;
    target->next = target->next->next;
    free(save_obsolete);
    myIdx->size--;
    return theData;
}
