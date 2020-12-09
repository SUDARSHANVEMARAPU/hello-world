#include "structure.h"
#ifndef __LIST__H__
#define __LIST__H__
extern ARRAYLIST* createArrayList(ARRAYLIST *arrayList);
extern void Insert(ARRAYLIST *arrayList,int,...);
extern char* get(ARRAYLIST *arraylist,int index);
extern char* delete(ARRAYLIST *ArrayList,int index);
extern void closeArrayList(ARRAYLIST *arrayList);
extern int NumberOfElements(ARRAYLIST *arrayList);
void replace(ARRAYLIST *ArrayList,int index,char *ch);
extern void Traverse(ARRAYLIST *arrayList);
extern void put(ARRAYLIST *arrayList,int index,char *ch);
#endif  //!__LIST__H__
