#ifndef VECTEUR_GEN_H
#define VECTEUR_GEN_H

#include <iostream>
using namespace std ; 

template <typename T> class vecteur_gen{
    protected : 
        int dim ; 
        T * elements ; 
    public : 
        // Constructeurs
        vecteur_gen(int d) ;
        vecteur_gen(int d, T * tab) ;
        vecteur_gen(const vecteur_gen & un_vecteur) ;
        // Destructeur
        ~vecteur_gen() ;
        // Surcharge des opérateurs
        T & operator [] (const int indice) ; 
        vecteur_gen & operator = (const vecteur_gen & un_vecteur) ; 
        vecteur_gen & operator += (const vecteur_gen & un_vecteur) ; 
        // Accesseurs
        int get_dim() {return dim ;}
};


template <typename T> vecteur_gen <T> operator + (const vecteur_gen <T> & v1, const vecteur_gen <T> & v2) ;

template <typename T> ostream & operator << (ostream & os, const vecteur_gen <T> vecteur) ; 
template <typename T> istream & operator >> (istream & is, vecteur_gen <T> vecteur) ;

#endif