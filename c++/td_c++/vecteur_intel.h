#ifndef VECTEUR_INTEL_H
#define VECTEUR_INTEL_H

#include "vecteur.h"

class vecteur_intel : public vecteur {
    public : 
        vecteur_intel(int d=0) : vecteur(d) {}
        vecteur_intel(int d, float * tab) : vecteur(d, tab) {}
        vecteur_intel(const vecteur_intel & v) : vecteur(v) {}
        ~vecteur_intel() ;
        virtual vecteur_intel & operator = (const vecteur_intel & un_vecteur_intel) ; 
        virtual vecteur_intel & operator += (const vecteur_intel & un_vecteur_intel) ; 
};

vecteur_intel operator + (const vecteur_intel & v1, const vecteur_intel & v2) ;

#endif