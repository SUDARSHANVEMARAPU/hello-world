#include <stdio.h>
#include "List.h"



int main(int argc, char const *argv[])
{       
    ARRAYLIST *ptr;
    ARRAYLIST mylist; 
    ptr=&mylist;
    createArrayList(ptr);

    Insert(ptr,12,"J&K","himachal pradesh","uttarakhand","uttar pradesh","punjab",
    "haryana","NCR","Madhya Pradesh","rajasthan","bihar","jharkhand","gujarat");
    Insert(ptr,8,"westbengal","manipur","arunachal pradesh","mizoram","sikkim","meghalaya","nagaland","assam");
    put(ptr,1,"ladakh");
    replace(ptr,0,"jammu&kashmir");
    replace(ptr,19,NULL);
    Traverse(ptr);
    printf("\nlength: %d\nlast index filled: %d\n",mylist.length,mylist.index);
    printf("number of elements: %d\n",NumberOfElements(ptr));
   // delete(ptr,2);
   // Traverse(ptr);
    //printf("\nlength: %d\nnumber of elements filled: %d\n",mylist.length,mylist.index);
        
    closeArrayList(&mylist);
    return 0;
}