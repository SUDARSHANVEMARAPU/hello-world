#include "SingleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node* createLinkedList(struct LinkedList *list,NODE* node){
    if(node!=NULL){     
        list->ROOT=node; 
        list->ROOT->index=0; list->length=1; list->created=1;
        list->ROOT->nextNode=NULL;
        return list->ROOT;
    }else{
        fprintf(stderr,"node is null");
        return NULL;
    }
}
void link(struct LinkedList *list,NODE *node){
    if(node==NULL){
        fprintf(stderr,"node have NULL address");
    }else if(list->created!=1 || list->ROOT==NULL){
        fprintf(stderr,"linkedist is not created");
    }else{
        NODE *current=list->ROOT; 
        while(current->nextNode!=NULL){
            current=current->nextNode;
        }
        current->nextNode=node;
        node->index=current->index+1;
        node->nextNode=NULL;
        list->length+=1;
    }
}
struct Node* get(struct LinkedList *list,int index){
    if(index<0){fprintf(stderr,"index is negative"); return NULL;}
    else{
        NODE *current=list->ROOT;
        while (current->index!=index){ current=current->nextNode;}
        return current;
    }    
}
void put(struct LinkedList *list,NODE *node,int index){
    if(node==NULL){
        fprintf(stderr,"node have NULL address");
    }else if(index<0){
        fprintf(stderr,"index is negative");
    }else if(index==0){
        
        NODE *current=node;//NODE *temp1=list->ROOT;
        current->nextNode=list->ROOT;
        list->ROOT=current;
        puts(list->ROOT->str);
        puts(list->ROOT->nextNode->str);
        
        while(current!=NULL){
            current->index=index;  
            current = current->nextNode;    
            ++index; 
        }
        list->length+=1;

    }else{
        NODE *current=node; NODE *temp2; NODE *temp1;
        temp1=get(list,index-1);  // take node before current --> temp1
        temp2=temp1->nextNode;    // take node after current --> temp2
        current->nextNode=temp2;  // set next node of current node to node after current 
        temp1->nextNode=current;  // set current node as next to node before current (temp1)
        while(current!=NULL){
            current->index=index;  
            current = current->nextNode;    
            ++index; 
        }
        list->length+=1;
    }   
}

int size(struct LinkedList *list){
    int length=1; NODE *current=list->ROOT;
    while( (current=current->nextNode)!=NULL){
        ++length;
    }
    return length;
}

void Traverse(struct LinkedList *list){
    NODE *current=list->ROOT; 
    printf("%d --> %s\n",current->index,current->str);
    while( (current=current->nextNode)!=NULL){
        printf("%d --> %s\n",current->index,current->str);
    }
}

void replaceNode(struct LinkedList*list,struct Node *node,int index){
    if(node!=NULL){
        NODE *current=node; NODE *temp1=get(list,index);  
        current->index=temp1->index;
        current->nextNode=temp1->nextNode;
        current=NULL;
    }else{
        fprintf(stderr,"node is null");
    }
}
