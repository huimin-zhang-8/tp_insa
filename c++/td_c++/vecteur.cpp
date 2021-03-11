#include <iostream>
#include "vecteur.h"
using namespace std ; 

// Définition des constructeurs
vecteur::vecteur(int d) : dim(d)
{
    if (d < 0) throw 1 ; 
    elements = new float[dim] ;
    for (int i=0 ; i < dim ; i++)
        elements[i] = 0 ; 
}

vecteur::vecteur(int d, float * tab) : dim(d)
{
    if (d < 0) throw 1 ; 
    elements = new float[dim] ; 
    for (int i = 0 ; i < dim ; i++)
        elements[i] = tab[i] ; 
}

vecteur::vecteur(const vecteur & un_vecteur) : dim(un_vecteur.dim)
{
    elements = new float[dim] ;
    //for (int i = 0 ; i < un_vecteur.dim ; i++)
    //    elements[i] = un_vecteur.elements[i] ; 
    memcpy(elements, un_vecteur.elements, dim*sizeof(float)) ;
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
    cout << "(" ; 
    for (int i = 0 ; i < dim ; i++)
        cout << elements[i] << " " ; 
    cout << ")" << endl ; 
}

void vecteur::saisie() 
{
    for (int i = 0 ; i < dim ; i++){
        cout << "Saisie de l'element " << i << " : " ; 
        cin >> elements[i] ; 
    }
}

// Définition des surcharges des opérations 
float & vecteur::operator [] (const int indice) 
{
    if (indice < 0 || indice > dim) throw 2 ; 
    return elements[indice] ;
}

vecteur & vecteur::operator = (const vecteur & un_vecteur)
{
    if (un_vecteur.dim != dim) throw 3 ; 
    memcpy(elements, un_vecteur.elements, dim*sizeof(float)) ;
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

vecteur multiplication (float f, vecteur & v) 
{
    for (int i = 0 ; i < v.dim ; i++)
        v.elements[i] *= f ; 
    return v ; 
}