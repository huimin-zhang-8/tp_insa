#include <stdio.h>
#include <stdlib.h>

#define NB_LIGNES 2
#define NB_COLONNES 3

void Saisie2(int nb_lignes, int nb_colonnes, int ** matrice)
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
            scanf("%d", &matrice[L][C]) ;
    }
}

void Saisie2p(int nb_lignes, int nb_colonnes, int ** matrice)
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
            scanf("%d", *(matrice+L)+C) ;
    }
}

void Affiche2(int nb_lignes, int nb_colonnes, int ** matrice)
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
            printf("%d ", matrice[L][C]) ;
        printf("\n") ;
    }
}

void Init(int * nb_lignes, int * nb_colonnes, int *** M)
{
    int L ;

    printf("Veuillez saisir le nombre de ligne : ") ;
    scanf("%d", nb_lignes) ;

    printf("Veuillez saisir le nombre de colonnes : ") ;
    scanf("%d", nb_colonnes) ;

    printf("Veuillez saisir les elements : ") ; 

    *M = malloc(sizeof(int *)* *nb_lignes) ;
    for (L=0 ; L<*nb_lignes ; L++)
        M[L] = malloc(sizeof(int)* *nb_colonnes) ;
}

int main()
{
    int nb_lignes, nb_colonnes ;
    int ** M ;

    /*
    int ** M = malloc(sizeof(int *)* NB_LIGNES) ;
    for (L=0 ; L<NB_LIGNES ; L++)
        M[L] = malloc(sizeof(int)*NB_COLONNES) ;
    */

    Init(&nb_lignes, &nb_colonnes, &M) ;
    Saisie2p(NB_LIGNES,NB_COLONNES,M) ;
    Affiche2(NB_LIGNES,NB_COLONNES,M) ;

    return 0;
}
