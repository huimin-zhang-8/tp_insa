#include <stdio.h>
#include <stdlib.h>

struct Cellule 
{
    int Entier ; 
    struct Cellule * Suivant ; 
};

struct Cellule * creer_buffer(int nb_cell)
{
    struct Cellule * Tampon = malloc(sizeof(struct Cellule)) ; 
    struct Cellule * Aux = Tampon ; 
    struct Cellule * New_Cell ; 
    for (int i=0 ; i<nb_cell ; i++)
    {
        New_Cell = malloc(sizeof(struct Cellule)) ; 
        New_Cell->Entier = -1 ;
        New_Cell->Suivant = Tampon ; 
        Aux->Suivant = New_Cell ;
    }
}

int main()
{
    return 0 ; 
}