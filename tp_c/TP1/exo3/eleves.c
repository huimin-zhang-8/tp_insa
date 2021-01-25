// constante.h
#ifndef CONSTANTE_H
#define CONSTANTE_H

#define MAXNOM 100

struct Eleve
{
  char Nom[MAXNOM] ;
  int Promo ; 
};

#endif

// eleves.h
#include "constante.h"

struct Eleve Init_Eleve(char * Un_Nom, int Sa_Promo) ; 

void Affiche_Eleve(struct Eleve Un_Eleve) ; 

// eleves.c
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

// main.c
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