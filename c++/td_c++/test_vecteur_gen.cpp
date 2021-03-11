#include <iostream>
#include "vecteur_gen.h"
using namespace std ; 


int main()
{
    vecteur_gen <float> vf(3) ; 
    vecteur_gen <int> vi1(3), vi2(3) ; 
    cout << "Saisie de vf : " << endl ; 
    cin >> vf ; 
    cout << "Saisie de vi1 : " << endl ; 
    cin >> vi1 ; 
    cout << "Saisie de vi2 : " << endl ; 
    cin >> vi2 ; 
}