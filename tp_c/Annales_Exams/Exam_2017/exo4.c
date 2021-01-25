#include <stdio.h>
#include <stdlib.h>

struct Noeud
{
    int Valeur ; 
    int Nb_Fils ; 
    struct Noeud * Gauche ; 
    struct Noeud * Droite ; 
}; 

void Inserer_Elem_Rec(int Element, struct Noeud ** Arbre)
{
    if (*Arbre == NULL)
    {
        struct Noeud * New_Noeud = malloc(sizeof(struct Noeud)); 
        New_Noeud->Valeur = Element ; 
        New_Noeud->Nb_Fils = 0 ; 
        New_Noeud->Droite = NULL ; 
        New_Noeud->Gauche = NULL ;
        *Arbre = New_Noeud ; 
    }
    else 
    {
        struct Noeud * Aux = *Arbre ;
        if (Element < Aux->Valeur)
        {
            Inserer_Elem_Rec(Element, &(Aux->Gauche)) ; 
            (Aux->Nb_Fils)++ ;
        }
        else if (Element > Aux->Valeur)
        {
            Inserer_Elem_Rec(Element, &(Aux->Droite)) ; 
            (Aux->Nb_Fils)++ ;
        }
    }
}

void Afficher_Arbre(struct Noeud * Arbre)
{
    struct Noeud * Aux = Arbre ; 
    if (Aux != NULL) return ; 
        printf("%d \n", Aux->Valeur) ; 
    if (Aux->Gauche != NULL)
        Afficher_Arbre(Aux->Gauche);
    if (Aux->Droite != NULL)
        Afficher_Arbre(Aux->Droite) ; 
}

int main()
{
    struct Noeud * Arbre = NULL ; 

    Inserer_Elem_Rec(5,&Arbre) ;
    Inserer_Elem_Rec(1,&Arbre) ; 
    Inserer_Elem_Rec(6,&Arbre) ;
    Inserer_Elem_Rec(2,&Arbre) ;  
    Afficher_Arbre(Arbre) ; 

    return 0 ; 
}