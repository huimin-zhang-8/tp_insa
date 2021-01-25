#include <stdio.h>
#include <stdlib.h>
#define NB_LIGNES 3
#define NB_COLONNES 2

// 1. Adresse de l'élément (L,C) : matrice[0][0] + L*nb_colonnes+C
// 2. Saisie d'un tableau à deux dimensions
void Saisie(int nb_lignes, int nb_colonnes, int matrice[][nb_colonnes])
// Si on met que int matrice[][], ça va pas compiler car le compilateur ne sait pas accéder à l'élément [L][C]
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
        {
            printf("Element %d, %d : ", L, C) ; 
            scanf("%d", &(matrice[L][C])) ;
        }
           
    }
}

// 3. Afficher une matrice
void Affiche(int nb_lignes, int nb_colonnes, int matrice[][nb_colonnes])
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
            printf("%d ", matrice[L][C]) ;
        printf("\n") ;
    }
    printf("\n") ; 
}

// 4. Saisie du tableau avec passage du tableau sous forme de pointeur
void Saisiep(int nb_lignes, int nb_colonnes, int * matrice)
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
        {
            printf("Element %d, %d : ", L, C) ; 
            scanf("%d", matrice+L*nb_colonnes+C) ;
        }
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