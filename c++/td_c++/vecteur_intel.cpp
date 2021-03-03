#include <iostream>
#include "vecteur_intel.h"
using namespace std ; 

vecteur_intel & vecteur_intel::operator = (const vecteur_intel & un_vecteur_intel)
{
    dim = un_vecteur_intel.dim ;
    // delete [] elements ; 
    elements = new float[dim] ; 
    memcpy(elements, un_vecteur_intel.elements, dim*sizeof(float)) ;
    return (*this) ;
} 

vecteur_intel & vecteur_intel::operator += (const vecteur_intel & un_vecteur_intel) 
{

    if (dim < un_vecteur_intel.dim)
    {
        vecteur_intel aux1(un_vecteur_intel.dim) ; // vecteur auxiliaire pour compléter le vecteur avec des 0
        vecteur_intel aux2(un_vecteur_intel) ;  // vecteur où on fait la somme
        for (int i=0 ; i < dim ; i++)
            aux1.elements[i] = elements[i] ; 
        for (int j=dim ; j < un_vecteur_intel.dim ; j++)
            aux1.elements[j] = 0 ; 
        for (int k=0 ; k < un_vecteur_intel.dim ; k++)
            aux2.elements[k] += aux1[k] ; 
       // delete [] elements ;
        dim = un_vecteur_intel.dim ; 
        elements = new float[un_vecteur_intel.dim] ; 
        memcpy(elements, aux2.elements, un_vecteur_intel.dim*sizeof(float)) ; 
    } 
    else if (dim > un_vecteur_intel.dim)
    {
        vecteur_intel aux1(dim) ; 
        for (int i=0 ; i < un_vecteur_intel.dim ; i++)
            aux1.elements[i] = un_vecteur_intel.elements[i] ; 
        for (int j=dim ; j < dim ; j++)
            aux1.elements[j] = 0 ; 
        for (int k=0 ; k < dim ; k++)
            elements[k] += aux1[k] ; 
    } 
    else 
    {
        for (int k = 0 ; k < dim ; k++)
            elements[k] += un_vecteur_intel.elements[k] ; 
    }
    
    return (*this) ; 
}

vecteur_intel operator + (const vecteur_intel & v1, const vecteur_intel & v2)
{
    vecteur_intel aux(v1) ; 
    return (aux+=v2) ; 
}