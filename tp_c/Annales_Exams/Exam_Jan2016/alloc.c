#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"

struct bloc 
{
    unsigned char etat ; 
    unsigned int taille ; 
    char * data ; 
} ; 

// 2. mem est une variable externe dont la portée est au moins ce fichier et le main 
// étant donné qu'l n'y a pas de définition de variable de ce type dans le fichier alloc.h
struct memoire
{
    struct bloc * les_blocs ; 
    unsigned int nb_blocs ; 
}; 

struct memoire * mem ; 

// 3. Définition des fonctions du fichier alloc.h
void init(unsigned int nb_blocs)
{
    mem = malloc(sizeof(struct memoire)) ; 
    mem->les_blocs = malloc(sizeof(struct bloc)*nb_blocs) ; 
    mem->nb_blocs = nb_blocs ; 
    
    for (int i=0 ; i<nb_blocs ; i++)
    {
        mem->les_blocs[i].etat = LIBRE ; 
        mem->les_blocs[i].taille = 0 ; 
        mem->les_blocs[i].data = NULL ; 
    }
}

c/*har * alloc(unsigned int taille)
{
    for (int i=0 ; i<mem->nb_blocs ; i++)

}*/