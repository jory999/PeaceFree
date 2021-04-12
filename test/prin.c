#include <stdio.h>
#include "hello.h"

void myprint(char *p,...)
{
    int n;
    for( n=0; *p!='\0';p++){

        n++;
    }
    
    printf("aaa:%d\n",n);
    
    return ;

}
