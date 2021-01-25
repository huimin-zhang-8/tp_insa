#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"

// 1. L'ensemble des blocs mem est de type struct bloc *
struct bloc 
{
    unsigned char etat ; 
    unsigned int taille ; 
    char * data ; 
} ; 

int main()
{
    
    return 0 ; 
}