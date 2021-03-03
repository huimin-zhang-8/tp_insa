#include <iostream>
#include "vecteur_intel.h"
using namespace std ; 

int main()
{
    vecteur_intel v1(2), v2(4) ; 
    cout << "Saisie de v1 : " << endl ; 
    v1.saisie() ; 
    v1.afficher() ; 
    cout << "Saisie de v2 : " << endl ; 
    v2.saisie() ; 
    v2.afficher() ; 

    cout << "Copie de v1 dans v3 avec '=' : " << endl ; 
    vecteur_intel v3 ;
    v3 = v1 ; 
    v3.afficher() ; 
    cout << "Addition de v3 et v2 avec '+=' : " << endl ; 
    v3 += v2 ; 
    v3.afficher() ; 
    cout << "Addition de v3 et v1 avec '+' : " << endl ; 
    vecteur_intel v4 = v1 + v3 ; 
    v4.afficher() ; 

    return 0 ; 
}