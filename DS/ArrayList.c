#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "structure.h"
//#pragma  war -par

void Traverse(ARRAYLIST *arrayList){
    for( int i=0;i<arrayList->index;++i){
        if(arrayList->list[i]!=NULL){
            fprintf(stdout,"%s",(arrayList->list[i]));
            if(i!=arrayList->index-1){
                fprintf(stdout,", ");
            }     
        }
        if(i%7==0){ putchar(10);}
    }
}

ARRAYLIST* createArrayList(ARRAYLIST *arrayList){

    arrayList->list=(char**)calloc(sizeof(char*),arrayList->length);
    arrayList->length=10;
    arrayList->index=0;
    arrayList->created=true;
    
    if(arrayList->list==NULL){
        fprintf(stderr,"memory not allocated, exiting");
        exit(EXIT_FAILURE);
    }
    return arrayList;
}
static void resize(ARRAYLIST *arrayList,int requiredLength){
    realloc(arrayList->list,sizeof(char*)*requiredLength);
    arrayList->length+=requiredLength;
}

void Insert(ARRAYLIST *arrayList,int numberOfElements,...){ 
  if(arrayList->created){
    va_list args; char  *temp1; 
    va_start(args,numberOfElements);
    if(arrayList->index+numberOfElements>arrayList->length){
        int requiredElements=arrayList->index+numberOfElements - arrayList->length+10;
        resize(arrayList,requiredElements);  
    }

    for(int i=arrayList->index;i<arrayList->index+numberOfElements;++i){            
        temp1 = va_arg(args,char*);        
        arrayList->list[i]=temp1;               
    }    
    arrayList->index+=numberOfElements;
    va_end(args);    
  }else{
      fprintf(stderr,"array is not created");
      exit(EXIT_FAILURE);
  }
}
char* get(ARRAYLIST *arraylist,int index){
    if(index<arraylist->length){
        if(arraylist->list[index]==NULL){
            return NULL;
        }
        return arraylist->list[index];
    }
    fprintf(stderr,"index is out of bound\n");
    return NULL;
}

void put(ARRAYLIST *arrayList,int index,char *ch){
    char *temp1,*temp2;
    if(arrayList->index+1>arrayList->length){
        resize(arrayList,10);
    }
    temp1=ch;
    for(int i=arrayList->index;i>index;--i){ // i=8 to i=3
        temp2=arrayList->list[i-1]; // i-1= 7 6 5 4 3 2   
        arrayList->list[i]=temp2; //    i = 8 7 6 5 4 3        
    }
    // 0 1 2 3 4 5 6 7 8 9 10 
    arrayList->list[index]=temp1;
    arrayList->index+=1;
}
char* delete(ARRAYLIST *ArrayList,int index){
    if(ArrayList->index==ArrayList->length){
        resize(ArrayList,10);
    }
    if(get(ArrayList,index)==NULL){
        fprintf(stderr,"value at index %d is NULL\n",index);
        return NULL;
    }else{
        char*temp1;
        for(int i=index;i<ArrayList->index;++i){  // i=2 to  i=7
            temp1=ArrayList->list[i+1]; // 3 4 5 6 7 8
            ArrayList->list[i]=temp1; // 2 3 4 5 6 7            
        }
        ArrayList->index-=1;
    }
    return get(ArrayList,index);    
}
void replace(ARRAYLIST *ArrayList,int index,char *ch){
    
    if(index>=ArrayList->length){
        fprintf(stderr,"index is out of bounds");
        
    }else{
        ArrayList->list[index]=ch;
    }
        
    
}



int NumberOfElements(ARRAYLIST *arrayList){
    char *ch;  int i=0; int n=0;
    while(i<arrayList->length){
        ch=arrayList->list[i];
        if(ch!=NULL){ n+=1;}
        ++i;
    }
    return n;
}
void closeArrayList(ARRAYLIST *arrayList){
    free(arrayList->list); 
}




