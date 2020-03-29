/**
 *
 * myFuncts.cpp
 *
 */

#include "myFuncts.h"

/**
 *
 * Append data to list
 *
 */
bool addData(struct maillon* oneData, struct sllist* oneIdx, uint8_t oneByte, const char* oneChar)
{
    oneData = (struct maillon*)malloc(sizeof(maillon));
    oneData->vala=oneByte;
    strcpy(oneData->valb, oneChar);

    if(sllist_push_back(oneIdx, oneData))
        return false;

    return true;
}

/**
 *
 * Display multi message
 *
 */
bool dispMultiMsg(struct sllist* oneIdx)
{
    for(uint8_t i=0; i<oneIdx->size; i++)
    {
        struct maillon* tmpIdx = (struct maillon*)sllist_read_index(oneIdx, i);

        if(tmpIdx==nullptr)
            return false;

        printf("Row %u - vala = %u - valb = \"%s\"\n", i+1, tmpIdx->vala, tmpIdx->valb);
    }

    return true;
}
