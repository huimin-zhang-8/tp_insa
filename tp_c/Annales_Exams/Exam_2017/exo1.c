#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[8] ;
    char ch2[8] = "BBBBBBB" ; 

    printf("ch1 %p ch2 %p\n", ch1, ch2) ;
    strcpy(ch1, "AAAAAAAA") ; 
    printf("ch1 %s ch2 %s\n", ch1, ch2) ; 
    // ch1 AAAAAAAA ch2 BBBBBBB
    // le dernier A est écrit en mémoire juste après le tableau ch1
    return(0) ; 
}