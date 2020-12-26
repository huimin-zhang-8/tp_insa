#include <stdio.h>
#include <stdlib.h>
#include "constante.h"
#include <string.h>

struct Eleve Init_Eleve(char * Un_Nom, int Sa_Promo)
{
  struct Eleve Un_Eleve ;
  strcpy(Un_Eleve.Nom, Un_Nom) ;
  Un_Eleve.Promo = Sa_Promo ;
  return Un_Eleve ; 
}

void Affiche_Eleve(struct Eleve Un_Eleve)
{
  printf("Nom : %s \n Promo : %d\n", Un_Eleve.Nom, Un_Eleve.Promo) ; 
}

