/**
 *
 * myFuncts.h
 *
 */

#ifndef MYFUNCTS_H_INCLUDED
#define MYFUNCTS_H_INCLUDED

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "sllist.h"

struct maillon
{
    uint8_t vala;
    char   valb[2];
};

bool addData(struct maillon* oneData, struct sllist* oneIdx, uint8_t oneByte, const char* oneChar);

bool dispMultiMsg(struct sllist* oneIdx);

#endif // MYFUNCTS_H_INCLUDED
