#include <stdio.h>
//#include "List.h"
#include "structure.h"


int main(int argc, char const *argv[])
{       
    ARRAYLIST *ptr;
    ARRAYLIST mylist; 
    ptr=&mylist;
    createArrayList(ptr);

    ptr->Insert(ptr,"J&K","himachal pradesh","uttarakhand","uttar pradesh","punjab","haryana",
    "NCR","Madhya Pradesh","rajasthan","bihar","jharkhand","gujarat",NULL);
     ptr->Insert(ptr,"westbengal","manipur","arunachal pradesh","mizoram","sikkim","meghalaya","nagaland","assam",NULL);
      ptr->put(ptr,1,"ladakh");
      ptr->replace(ptr,0,"jammu&kashmir");
      ptr->replace(ptr,19,NULL);
     ptr->Traverse(ptr); // first traversal
     printf("\nlength: %d\nlast index filled: %d\n",ptr->length,ptr->index-1);
     printf("number of elements: %d\n",ptr->NumberOfElements(ptr));
      ptr->delete(ptr,2);
      ptr->Traverse(ptr); // second traversal
      printf("\nlength: %d\nnumber of elements filled: %d\n",mylist.length,mylist.index);
        
     closeArrayList(ptr);

     
    return 0;
}