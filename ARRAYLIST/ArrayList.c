#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "structure.h"


void Traverse(struct ArrayList *arrayList){
   
    for( int i=0;i<arrayList->index;++i){
        if(arrayList->list[i]!=NULL){
            fprintf(stdout,"%s",(arrayList->list[i]));
            if(i!=arrayList->index-1){
                fprintf(stdout,", ");
            }     
        }
        if(i%7==0 && i!=0){ putchar(10);}
    }
}


static void resize(struct ArrayList *arrayList,int requiredLength){
    realloc(arrayList->list,sizeof(char*)*requiredLength);
    arrayList->length+=requiredLength;
}

/******************************************************************************************/
/********************************* INSERT METHOD FIRST DRAFT *****************************/
/******************************************************************************************/
// void Insert(struct ArrayList *arrayList,int numberOfElements,...){ 
   
//   if(arrayList->created){
//     va_list args; char  *temp1; 
//     va_start(args,numberOfElements);
//     if(arrayList->index+numberOfElements>arrayList->length){
//         int requiredElements=arrayList->index+numberOfElements - arrayList->length+10;
//         resize(arrayList,requiredElements);  
//     }

//     for(int i=arrayList->index;i<arrayList->index+numberOfElements;++i){            
//         temp1 = va_arg(args,char*);        
//         arrayList->list[i]=temp1;               
//     }    
//     arrayList->index+=numberOfElements;
//     va_end(args);    
//   }else{
//       fprintf(stderr,"array is not created");
//       exit(EXIT_FAILURE);
//   }
// }
/******************************************************************************************/
/********************************* INSERT METHOD FIRST DRAFT *****************************/
/******************************************************************************************/

char* get(struct ArrayList *arraylist,int index){
    if(index<arraylist->length){
        if(arraylist->list[index]==NULL){
            return NULL;
        }
        return arraylist->list[index];
    }
    fprintf(stderr,"index is out of bound\n");
    return NULL;
}

void put(struct ArrayList *arrayList,int index,char *ch){
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
char* delete(struct ArrayList *ArrayList,int index){
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
void replace(struct ArrayList *ArrayList,int index,char *ch){
    
    if(index>=ArrayList->length){
        fprintf(stderr,"index is out of bounds");
        
    }else{
        ArrayList->list[index]=ch;
    }
        
    
}

int NumberOfElements(struct ArrayList *arrayList){
    char *ch;  int i=0; int n=0;
    while(i<arrayList->length){
        ch=arrayList->list[i];
        if(ch!=NULL){ n+=1;}
        ++i;
    }
    return n;
}


void closeArrayList(struct ArrayList *arrayList){
    free(arrayList->list); 
}




void Isrt(struct ArrayList *arrayList,...){ 
   
  if(arrayList->created){
    va_list args; char  *temp1; int numberOfElements=0; 
    va_start(args,arrayList);
    while(va_arg(args,char*)!=NULL){
        ++numberOfElements;
    }
    va_start(args,arrayList);
    
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


struct ArrayList* createArrayList(struct ArrayList *arrayList){
    arrayList->length=10;
    arrayList->index=0;
    arrayList->list=(char**)calloc(sizeof(char*),arrayList->length);    
    if(arrayList->list==NULL){
        fprintf(stderr,"memory not allocated, exiting");
        exit(EXIT_FAILURE);
    }

    
    arrayList->created=true;
    arrayList->Insert=Isrt;
    arrayList->delete=delete;
    arrayList->put=put;
    arrayList->replace=replace;
    arrayList->Traverse=Traverse;
    arrayList->NumberOfElements=NumberOfElements;
        

    return arrayList;
}