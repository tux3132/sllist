#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"
#include "myFuncts.h"

int main()
{
    /**
    *
    * Single linked lists test
    *
    */

    /** Creating index of elements **/
    sllist* myIdx = sllist_create();
    if(myIdx==nullptr)
        return 1;

    /** Creating of data **/
    maillon* myData=nullptr;

    addData(myData, myIdx, 9, "a");
    addData(myData, myIdx, 8, "b");
    addData(myData, myIdx, 7, "c");
    addData(myData, myIdx, 6, "d");
    addData(myData, myIdx, 5, "e");
    addData(myData, myIdx, 4, "f");
    addData(myData, myIdx, 3, "g");
    addData(myData, myIdx, 2, "h");
    addData(myData, myIdx, 1, "i");

    printf("Nombre d'éléments : %u\n", myIdx->size);

    dispMultiMsg(myIdx);

    sllist_destroy(myIdx);
    free(myData);


    return EXIT_SUCCESS;
}
