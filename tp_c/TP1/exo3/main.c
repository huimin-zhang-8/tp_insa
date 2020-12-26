#include <stdio.h>
#include "eleves.h"
#include "constante.h"

int main()
{
  struct Eleve Un_Eleve ;
  Un_Eleve = Init_Eleve("Huimin", 55) ;
  Affiche_Eleve(Un_Eleve) ; 
  
  return 0 ; 
}
