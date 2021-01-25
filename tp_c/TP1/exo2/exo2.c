#include <stdio.h>
#include <stdlib.h>

#include "exo2.h"

void Affiche(char ch[])
{
  printf("%s\n", ch) ;
}

int Fact(int n)
{
  /* int i ;
    int resultat = 1 ; 
    for (i=1 ; i<=n ; i++)
    resultat *= i ; 
    return resultat ; */
    if (n==1) return 1 ; 
    else return n*Fact(n-1) ; 
 
}

void Date()
{
  system("date /t") ; 
}

