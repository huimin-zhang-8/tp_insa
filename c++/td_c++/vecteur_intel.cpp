#include <iostream>
#include "vecteur_intel.h"
using namespace std ; 

/*vecteur_intel & vecteur_intel::operator = (const vecteur_intel & un_vecteur_intel)
{
    vecteur_intel * v ; 
    for (int i = 0 ; i < un_vecteur_intel.dim ; i++)
        elements[i] = un_vecteur_intel.elements[i] ; 
    return (*this) ;
} */

int main()
{
    vecteur_intel v1(5) ; 
    v1.afficher() ; 

    return 0 ; 
}