#include <stdio.h>
#include <stdlib.h>

// matrice est un tableau de pointeurs
// Chaque élément de matrice correspond à une ligne de la matrice (tableau d'entiers)

// 3. 
void Saisie2(int nb_lignes, int nb_colonnes, int ** matrice)
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
        {
            printf("Element %d, %d : ", L, C) ;
            scanf("%d", &matrice[L][C]) ;
        }
    }
}

// 4. Saisie avec artihmétique des pointeurs
void Saisie2p(int nb_lignes, int nb_colonnes, int ** matrice)
{
    int L, C ;
    for (L=0 ; L<nb_lignes ; L++)
    {
        for (C=0 ; C<nb_colonnes ; C++)
        {
            printf("Element %d, %d : ", L, C) ;
            scanf("%d", *(matrice+L)+C) ; // ou M[L]+C
        }
    }
}

// 5. Affichage de la matrice
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

// 7. Initialiser la matrice 
void Init(int * nb_lignes, int * nb_colonnes, int *** M)
{
    int L ;

    printf("Veuillez saisir le nombre de ligne : ") ;
    scanf("%d", nb_lignes) ;

    printf("Veuillez saisir le nombre de colonnes : ") ;
    scanf("%d", nb_colonnes) ;

    printf("Veuillez saisir les elements : ") ; 

    *M = malloc(sizeof(int *) * *nb_lignes) ;
    for (L=0 ; L<*nb_lignes ; L++)
        M[L] = malloc(sizeof(int)* *nb_colonnes) ;
}

int main()
{
    int nb_lignes, nb_colonnes ;
    int ** M ;

    /* 2. Allocation de mémoire d'une matrice 2x3
    int ** M = malloc(sizeof(int *)* NB_LIGNES) ;
    for (int L=0 ; L<NB_LIGNES ; L++)
        M[L] = malloc(sizeof(int)*NB_COLONNES) ; 
    */

    Init(&nb_lignes, &nb_colonnes, &M) ;
    Saisie2p(nb_lignes,nb_colonnes,M) ;
    Affiche2(nb_lignes,nb_colonnes,M) ;

    return 0;
}
