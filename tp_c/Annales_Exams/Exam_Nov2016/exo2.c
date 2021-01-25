#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct eleve {
    char mon_nom[24] ; 
    struct eleve * suivant ; 
    struct groupe * mon_groupe ; 
};

struct groupe 
{
    char nom ; 
} ; 

// Insère un élève dans une pile d'élèves 
void F1(struct eleve ** p, struct groupe * les_groupes, int mon_groupe, char * nom)
{
    struct eleve * un_eleve ; 
    un_eleve = malloc(sizeof(struct eleve)) ; 
    strcpy(un_eleve->mon_nom, nom) ; 
    un_eleve->mon_groupe = &les_groupes[mon_groupe] ; 
    un_eleve->suivant = *p ; 
    *p = un_eleve ; 
}

// Renvoie l'élève actuel pointé par le pointeur *p qui pointe ensuite sur l'élève suivant
// Dépile le premier élève
 struct eleve * F2(struct eleve ** p)
{
    struct eleve * un_eleve = NULL ; 
    if (*p != NULL)
    {
        un_eleve = *p ; 
        *p = (*p)->suivant ; 
    }
    return un_eleve ; 
}

// Compter le nombre d'élèves
int Nombre(struct eleve * des_eleves)
{
    int nb = 0 ; 
    struct eleve * aux = des_eleves ; 
    while (aux != NULL) 
    {
        nb++ ;
        aux = aux->suivant ; 
    } 
    return nb ; 
}

void Effacer(struct eleve ** des_eleves)
{
    struct eleve * aux = *des_eleves ;
    struct eleve * Ancien ;  
    while (aux->suivant->suivant != NULL)
    {
        aux = aux->suivant ; 
    }
    Ancien = aux->suivant ; 
    aux->suivant = NULL ; 
    free(Ancien) ; 
}

int main(void)
{
    struct eleve * les_eleves = NULL ; 
    struct groupe les_groupes[4] ; 
    struct eleve * e ; 
    int i ; 
    
    // les_groupes[0] = a, les_groupes[1] = b, ...
    for (i=0 ; i<4 ; i++)
        les_groupes[i].nom = 'a'+i ; 

    F1(&les_eleves, les_groupes, 0, "n1") ; 
    F1(&les_eleves, les_groupes, 0, "n2") ; 
    F1(&les_eleves, les_groupes, 0, "n3") ; 
    e = F2(&les_eleves) ; 
    F1(&les_eleves, les_groupes, 1, "n4") ; 
    F1(&les_eleves, les_groupes, 2, "n5") ; 
    F1(&les_eleves, les_groupes, 3, "n6") ; 
    F1(&les_eleves, les_groupes, 2, "n7") ;

    printf("Nb d'eleves : %d\n", Nombre(les_eleves)) ; 
    Effacer(&les_eleves) ; 
    printf("Nb d'eleves : %d\n", Nombre(les_eleves)) ; 

    struct eleve * aux = les_eleves ; 
    char nom_fich_ecrit[50] ; 
    printf("Nom du ficher d'ecriture : ") ; 
    scanf("%s", nom_fich_ecrit) ; 
    FILE * fich_ecrit = fopen(nom_fich_ecrit, "w"); 
    while (aux->suivant != NULL)
    {
        fprintf(fich_ecrit, "%s-%c;", aux->mon_nom, *(aux->mon_groupe)) ; 
        aux = aux->suivant ; 
    }
    
    return 0 ;  
}