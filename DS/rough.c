#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int add(int a, int b);
struct NODE{
    int a; int b;
    int (*func)(int, int);
};
int main(int argc, char const *argv[])
{
    struct NODE one;
    one.a=5;
    one.b=6;
    one.func=add;
    printf("%d\n",one.func(one.a,one.b));
  return 0;
}

int add(int a, int b){

    return a+b;
}