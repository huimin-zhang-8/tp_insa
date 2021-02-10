#include <iostream>
#include "vecteur.h"
using namespace std ; 

// Définition des constructeurs
vecteur::vecteur() 
{
    dim = 0 ; 
    elements = NULL ;
}

vecteur::vecteur(int d) 
{
    if (d < 0) throw 1 ; 
    dim = d ; 
    elements = new float[dim] ;
}

vecteur::vecteur(int d, float * tab)
{
    if (d < 0) throw 1 ; 
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

// Définition du destructeur
vecteur::~vecteur() 
{
    if (dim > 0)
        delete [] elements ;
}

// Définition des fonctions annexes
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

// Définition des surcharges des opérations 
float & vecteur::operator [] (int indice) 
{
    if (indice < 0 || indice > dim) throw 2 ; 
    return elements[indice] ;
}

vecteur & vecteur::operator = (const vecteur & un_vecteur)
{
    if (un_vecteur.dim != dim) throw 3 ; 
    for (int i = 0 ; i < un_vecteur.dim ; i++)
        elements[i] = un_vecteur.elements[i] ; 
    return (*this) ; 
}

vecteur & vecteur::operator += (const vecteur & un_vecteur)
{
    if (un_vecteur.dim != dim) throw 3 ; 
    for (int i = 0 ; i < dim ; i++)
         elements[i] += un_vecteur.elements[i] ; 
    return (*this) ; 
}

vecteur operator + (const vecteur & v1, const vecteur & v2)
{
    vecteur aux(v1) ; 
    return (aux+=v2) ; 
}

int main(){

    // Test des constructeurs
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

    // Test des exceptions des constructeurs et des opérateurs
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