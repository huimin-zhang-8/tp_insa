#include <iostream>
#include "vecteur_intel.h"
using namespace std ; 

vecteur_intel::~vecteur_intel() 
{
    if (dim > 0)
        delete [] elements ;
}

vecteur_intel & vecteur_intel::operator = (const vecteur_intel & un_vecteur_intel)
{
    if (dim != un_vecteur_intel.dim)
    {
        dim = un_vecteur_intel.dim ; 
        delete [] elements ; 
        elements = new float[dim] ;
    }
    
    memcpy(elements, un_vecteur_intel.elements, dim*sizeof(float)) ;  
    
    return (*this) ;
} 

vecteur_intel & vecteur_intel::operator += (const vecteur_intel & un_vecteur_intel) 
{
    if (dim < un_vecteur_intel.dim)
    {
        float * tab ; 
        tab = new float[un_vecteur_intel.dim] ; 
        for (int i=0 ; i < dim ; i++)
            tab[i] = elements[i] + un_vecteur_intel.elements[i] ; 
        for (int j=dim ; j < un_vecteur_intel.dim ; j++)
            tab[j] = un_vecteur_intel.elements[j] ; 
        delete [] elements ;
        dim = un_vecteur_intel.dim ; 
        elements = tab ; 
    } 
    else 
    {
        for (int i=0 ; i < dim ; i++)
            elements[i] += un_vecteur_intel.elements[i] ; 
    }
    
    return (*this) ; 
}

vecteur_intel operator + (const vecteur_intel & v1, const vecteur_intel & v2)
{
    vecteur_intel aux(v1) ; 
    return (aux+=v2) ; 
}