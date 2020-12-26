#include <stdio.h>
#include <stdlib.h>
#define NB_LIGNES 3
#define NB_COLONNES 2

void Saisie(int nb_lignes, int nb_colonnes, int matrice[][nb_colonnes])
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
            scanf("%d", &matrice[L][C]) ;
    }

}

void Affiche(int nb_lignes, int nb_colonnes, int matrice[][nb_colonnes])
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
            printf("%d ", matrice[L][C]) ;
        printf("\n") ;
    }
}

void Saisiep(int nb_lignes, int nb_colonnes, int * matrice)
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
            scanf("%d", (matrice+L*nb_colonnes+C)) ;
    }
}

int main()
{
    int matrice[NB_LIGNES][NB_COLONNES] ;

    Saisie(NB_LIGNES,NB_COLONNES,matrice) ;
    Affiche(NB_LIGNES,NB_COLONNES,matrice) ;
    Saisiep(NB_LIGNES,NB_COLONNES,(int *) matrice) ;
    Affiche(NB_LIGNES,NB_COLONNES,matrice) ;

    return 0;
}
