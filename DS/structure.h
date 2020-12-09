#include <stdbool.h>
#ifndef __STRUCTURE__H__
#define __STRUCTURE__H__
typedef struct ArrayList{
    char **list;
    bool created;
    int length;
    int index;
    
}ARRAYLIST;

// extern void Traverse(ARRAYLIST *arrayList);
#endif  //!__STRUCTURE__H__
