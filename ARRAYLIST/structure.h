#include <stdbool.h>
#ifndef __STRUCTURE__H__
#define __STRUCTURE__H__
typedef struct ArrayList{
    char **list;
    bool created;
    int length;
    int index;
    void (*Insert)(struct ArrayList *ArrayList,...);
    char* (*get)(struct ArrayList *ArrayList,int index);
    char* (*delete)(struct ArrayList *ArrayList,int index);    
    
    int (*NumberOfElements)(struct ArrayList *ArrayList);
    void (*Traverse)(struct ArrayList *ArrayList);
    void (*put)(struct ArrayList *ArrayList,int index,char *ch);
    void (*replace)(struct ArrayList *ArrayList,int index,char *ch);

}ARRAYLIST;
ARRAYLIST* createArrayList(ARRAYLIST *arrayList);
void closeArrayList(ARRAYLIST *arrayList);
// extern void Traverse(struct ArrayList *struct ArrayList);
#endif  //!__STRUCTURE__H__
