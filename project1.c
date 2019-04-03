#include<stdio.h>

int main(){

    char str[1024]= "happy projecting";    // string inside " ";
    char c = 53;                    // ascii number 53 is output 5
        printf("read: %s\n", str);  // %s reads strings
        printf("ascii %c\n", c);      // %c reads ascii

int i;
    for ( i= 97; i< 123; i++){       
    printf("%c", i);                //ascii for lower case
    }                               
  printf("\n");                    
    for (i=65;i<91;i++){            // ascii lower case
    printf("%c", i);                
    }
hello
return 0;
}

/*
meun
1 encript with rotation with text and key shift
2 decript rotation "   "
3 encript with substitution text and sub
4 decript substitution      "    "
5 decript rotation text only
6 decript substitution text only
*/