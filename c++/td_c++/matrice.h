#ifndef MATRICE_H
#define MATRICE_H

#include "vecteur.h"
#include "vecteur_intel.h"

class matrice 
{
    public : 
        vecteur * tab[10] ; 
        void afficher() const ;    
};

#endif