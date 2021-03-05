#include <iostream>
#include "vecteur_gen.h"
using namespace std ; 

// Définition des constructeurs
template <typename T> vecteur_gen<T>::vecteur_gen(int d) : dim(d)
{
    if (d < 0) throw 1 ; 
    elements = new T[dim] ;
    for (int i=0 ; i < dim ; i++)
        elements[i] = 0 ; 
}

template <typename T> vecteur_gen<T>::vecteur_gen(int d, T * tab) : dim(d)
{
    if (d < 0) throw 1 ; 
    elements = new T[dim] ; 
    memcpy(elements, tab, dim*sizeof(T)) ; 
}

template <typename T> vecteur_gen<T>::vecteur_gen(const vecteur_gen & un_vecteur) : dim(un_vecteur.dim)
{
    elements = new T[dim] ;
    memcpy(elements, un_vecteur.elements, dim*sizeof(T)) ;
}

// Définition du destructeur
template <typename T> vecteur_gen<T>::~vecteur_gen() 
{
    if (dim > 0)
        delete [] elements ;
}

// Définition des surcharges des opérations 
template <typename T> T & vecteur_gen <T>::operator [] (const int indice) 
{
    if (indice < 0 || indice > dim) throw 2 ; 
    return elements[indice] ;
}

template <typename T> vecteur_gen <T> & vecteur_gen <T>::operator = (const vecteur_gen & un_vecteur)
{
    if (un_vecteur.dim != dim) throw 3 ; 
    memcpy(elements, un_vecteur.elements, dim*sizeof(T)) ;
    return (*this) ; 
}

template <typename T> vecteur_gen <T> & vecteur_gen <T>::operator += (const vecteur_gen & un_vecteur)
{
    if (un_vecteur.dim != dim) throw 3 ; 
    for (int i = 0 ; i < dim ; i++)
         elements[i] += un_vecteur.elements[i] ; 
    return (*this) ; 
}

template <typename T> vecteur_gen <T> operator + (const vecteur_gen <T> & v1, const vecteur_gen <T> & v2)
{
    vecteur_gen <T> aux(v1) ; 
    return (aux+=v2) ; 
}

template <typename T> ostream & operator << (ostream & os, const vecteur_gen <T> vecteur)
{
    os << "(" ; 
    for (int i=0 ; i < vecteur.dim ; i++)
        os << vecteur.elements[i] ; 
    os << ")" << endl ; 
    return (os) ; 
}

template <typename T> istream & operator >> (istream & is, vecteur_gen <T> vecteur)
{
    for (int i=0 ; i < vecteur.dim ; i++)
        is >> vecteur.elements[i] ; 
    return (is) ; 
}