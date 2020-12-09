
#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"
int main(int argc, char const *argv[])
{
    NODE a1; NODE a2;   NODE a3; NODE a4; NODE a5; //NODE a6;
    LINKEDLIST mylist;
    LINKEDLIST *ptr=&mylist;
    a1.str="Jammu&Kashmir"; a2.str="Ladakh"; a3.str="punjab"; a4.str="haryana"; a5.str="uttarakhand"; // a6.str="Himachal Pradesh";
    createLinkedList(ptr,&a1);
    link(ptr,&a2); link(ptr,&a3); link(ptr,&a4); link(ptr,&a5);
  //  put(ptr,&a6,2);
    
   
    Traverse(ptr);
    printf("size: %d\n",ptr->length);
    return 0;
}
