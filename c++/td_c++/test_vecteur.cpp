#include <iostream>
#include "vecteur.h"
using namespace std ; 

int main(){

    // Test des constructeurs (TD1)
    /* vecteur v1 ; 
    v1.afficher() ;
    vecteur v2(10) ;
    v2.afficher() ;
    float tab[10] ; 
    for (int i = 0 ; i < 10 ; i++)
        tab[i] = i ;    
    vecteur v3(10, tab) ; 
    v3.afficher() ; 
    vecteur v4(v3) ;
    v4.afficher() ; 
    v4.saisie() ; 
    v4.afficher() ; */ 

    // Test des exceptions des constructeurs et des opérateurs (TD2)
    try {
        vecteur v1(10) ; 
        // vecteur v2(-10) ; 
        float f ; 
        v1[0] = 3.1 ; 
        v1.afficher() ; 
        f = v1[0] ;
        cout << "f = " << f << endl ; 
        // v1[50] = 10 ; 
        float tab[10] ; 
        for (int i = 0 ; i < 10 ; i++)
            tab[i] = i ;    
        vecteur v2(10, tab) ; 
        v2.afficher() ;
        vecteur v3 = v2 ; 
        v3.afficher() ; 
        v1 = v2 + v3 ; 
        v1.afficher() ; 
    }
    catch (int erreur) {
        switch(erreur) {
            case 1 : cout << "Erreur constructeur \n" ; break ; 
            case 2 : cout << "Erreur indice \n" ; break ; 
            case 3 : cout << "Erreur dimension \n" ; break ; 
            default : cout << "Exception inconnue \n" ; 
        }
    }

    return(0) ; 
}