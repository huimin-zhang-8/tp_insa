#include <iostream>
#include "matrice.h"
#include "vecteur.h" 
#include "vecteur_intel.h"
using namespace std ; 

void matrice::afficher() const 
{
    cout << "(" ; 
    for (int i=0 ; i < 10 ; i++)
        tab[i]->afficher() ; 
    cout << ")" << endl ; 
}

int main()
{
    matrice M ; 
    M.tab[0] = new vecteur(5) ; 
    M.tab[1] = new vecteur_intel(3) ;
    M.afficher() ; 
}
