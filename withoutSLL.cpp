#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int main()
{
    /** Creating data structure **/
    struct maillon
    {
        uint8_t vala;
        char   valb[2];
    };
    maillon* myData;

    /** Creating node structure **/
    struct lnode
    {
        void* data;
        struct lnode *next;
    };
    lnode* myNode;
    lnode* tmpNode;

    /** Creating index structure **/
    struct sllist
    {
        struct lnode* head;
        struct lnode* current;
        struct lnode* tail;
        uint16_t size;
    };
    sllist* myIdx;

    puts("Creating index");
    myIdx = (sllist*)malloc(sizeof(sllist));
    myIdx->head = nullptr;
    myIdx->tail = nullptr;
    myIdx->size = 0;

    puts("Creating first data");
    myData = (maillon*)malloc(sizeof(maillon));
    myData->vala=10;
    strcpy(myData->valb,"a");

    puts("Creating first node");
    myNode = (lnode*)malloc(sizeof(lnode));
    myNode->data=myData;
    myNode->next=nullptr;

    /** Appending first node to index **/
    myIdx->head = myNode;
    myIdx->tail = myNode;
    myIdx->size++;

    /** Printing vala from node
                 valb from index **/
    printf("vala %u - valb %s\n",
           ((maillon*)myNode->data)->vala,
           ((maillon*)myIdx->head->data)->valb);

    /** Second data **/
    myData = (maillon*)malloc(sizeof(maillon));
    myData->vala=20;
    strcpy(myData->valb,"b");

    myNode = (lnode*)malloc(sizeof(lnode));
    myNode->data=myData;
    myNode->next=nullptr;

    myIdx->tail->next = myNode;
    /** Another method for appending node
        myIdx->head->next = myNode; **/
    myIdx->tail = myNode;
    myIdx->size++;

    printf("vala %u - valb %s\n",
           ((maillon*)myNode->data)->vala,
           ((maillon*)myIdx->head->next->data)->valb);

    /** Third data **/
    myData = (maillon*)malloc(sizeof(maillon));
    myData->vala=30;
    strcpy(myData->valb,"c");

    myNode = (lnode*)malloc(sizeof(lnode));
    myNode->data=myData;
    myNode->next=nullptr;

    myIdx->tail->next = myNode;
    /** myIdx->head->next->next = myNode; **/
    myIdx->tail = myNode;
    myIdx->size++;

    printf("vala %u - valb %s\n",
           ((maillon*)myNode->data)->vala,
           ((maillon*)myIdx->head->next->next->data)->valb);

    puts("Browsing first method");
    printf("vala =  %i\n", ((maillon*)myIdx->head->data)->vala);
    printf("vala =  %i\n", ((maillon*)myIdx->head->next->data)->vala);
    printf("vala =  %i\n", ((maillon*)myIdx->head->next->next->data)->vala);

    puts("Browsing second method");
    tmpNode=myIdx->head;
    printf("valb = %s\n", ((maillon*)tmpNode->data)->valb);

    tmpNode=tmpNode->next;
    printf("valb = %s\n", ((maillon*)tmpNode->data)->valb);

    tmpNode=tmpNode->next;
    printf("valb = %s\n", ((maillon*)tmpNode->data)->valb);

    puts("Browsing list loop");
    tmpNode = myIdx->head;

    while(tmpNode != nullptr)
    {
        printf("vala %i\n", ((maillon*)tmpNode->data)->vala);
        tmpNode = tmpNode->next;
    }

    puts("Clearing memory");
    lnode* bkpNextNode;
    myIdx->current = myIdx->head;

    while(myIdx->current != nullptr)
    {
        bkpNextNode = myIdx->current->next;
        free(myIdx->current->data);
        free(myIdx->current);
        myIdx->current = bkpNextNode;
    }

    /** All others node are already freed **/
    free(myIdx);

    return 0;
}
