#include <iostream>
#include "vecteur.h"
using namespace std ; 

vecteur::vecteur() {dim = 0 ; elements = NULL ;}
vecteur::vecteur(int d) {dim = d ; elements = new float[dim] ;}
vecteur::vecteur(int d, float * tab)
{
    dim = d ; 
    elements = new float[dim] ; 
    for (int i = 0 ; i < dim ; i++)
        elements[i] = tab[i] ; 
}
vecteur::vecteur(const vecteur & un_vecteur) 
{
    dim = un_vecteur.dim ; 
    elements = new float[dim] ;
    for (int i = 0 ; i < un_vecteur.dim ; i++)
        elements[i] = un_vecteur.elements[i] ; 
}

vecteur::~vecteur() 
{
    if (dim > 0)
        delete [] elements ;
}

void vecteur::afficher() const 
{
    if (elements == NULL) 
        cout << "Vecteur vide ! \n" ;
    else { 
        cout << "Contenu du vecteur : " ; 
        for (int i = 0 ; i < dim ; i++)
            cout << elements[i] << " " ; 
        cout << "\n" ; 
    }
}

void vecteur::saisie() 
{
    for (int i = 0 ; i < dim ; i++){
        cout << "Saisie de l'element " << i << " : " ; 
        cin >> elements[i] ; 
    }
}

int main(){
    vecteur v1 ; 
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
    vecteur v5(v4) ; 
    v5.saisie() ; 
    v5.afficher() ; 
    return(0) ; 
}