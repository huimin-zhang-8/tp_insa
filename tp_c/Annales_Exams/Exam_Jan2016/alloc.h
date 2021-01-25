#ifndef ALLOC_H
#define ALLOC_H

#define LIBRE 0 
#define OCCUPE 1 

// Initialisation de nb_blocs libres
void init(unsigned int nb_blocs) ; 

// Allocation d'un nouveau bloc dont la taille est donnée
// L'adresse de la mémoire associée est retournée
char * alloc(unsigned int taille) ; 

// Liberation d'un bloc de mémoire dont on connait l'adresse de la mémoire associée
unsigned int libere(char * addr) ; 

// Affiche l'état de tous les blocs de mémoire (libre ou occupé) ainsi que la taille du bloc
void etat() ; 

#endif 