#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pers
{
    char * nom;
    int age;
};

void affiche(struct pers p)
{
    printf("%s a %d ans\n",p.nom,p.age);
}

int main()
{
    struct pers p1,p2;
    char * nom;

    nom=malloc(20);
    strcpy(nom,"raymond");
    p1.nom=nom;
    p1.age=35;
    strcpy(nom,"albert");
    p2.nom=nom;
    p2.age=45;
    affiche(p1);
    affiche(p2);
    
    return(0);
}