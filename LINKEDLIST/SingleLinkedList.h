#ifndef __STRUCTURE__H__
#define __STRUCTURE__H__

typedef struct Node{
    char *str;
    int index;
    struct Node *nextNode;
}NODE;

typedef struct LinkedList{
    struct Node *ROOT;
    int length;
    int created;
}LINKEDLIST;

struct Node* createLinkedList(struct LinkedList *list,NODE* root);
void link(struct LinkedList *list,NODE *node);
void Traverse(struct LinkedList *list);
void put(struct LinkedList *list,NODE *node,int index);
struct Node* get(struct LinkedList *list,int index);
int size(struct LinkedList *list);
void replaceNode(struct LinkedList*list,struct Node *node,int index);

#endif  //!__STRUCTURE__H__