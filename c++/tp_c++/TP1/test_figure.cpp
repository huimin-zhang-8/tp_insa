#include <iostream>
#include <list>
#include <typeinfo>
#include "figure.h"
using namespace std ; 

int main()
{
    /* // Test de la classe Rectangle
    Rectangle R(3,2) ;
    cout << "Longueur de R : " << R.getLongueur() << endl ; 
    cout << "Largeur de R : " << R.getLargeur() << endl ;
    cout << "Perimetre de R : " << R.perimetre() << endl ; 
    R.setCotes(4,2) ; 
    R.afficherCaracteristiques() ; 
    cout << endl ; 

    // Test de la classe Carre 
    Carre C(4) ; 
    cout << "Longueur de C : " << C.getLongueur() << endl ; 
    cout << "Perimetre de C : " << C.perimetre() << endl ; 
    C.setCote(3) ; 
    C.afficherCaracteristiques() ; 
    cout << endl ; 

    // Test de la classe TriangleEquilateral 
    TriangleEquilateral T(3) ; 
    cout << "Longueur d'un cote de T : " << T.getCote() << endl ; 
    cout << "Perimetre de T : " << T.perimetre() << endl ; 
    T.setCote(4) ; 
    T.afficherCaracteristiques() ; 
    cout << endl ; 

    // Test de la classe Cercle 
    Cercle O(2) ; 
    cout << "Rayon de O : " << O.getRayon() << endl ; 
    cout << "Perimetre de O : " << O.perimetre() << endl ; 
    O.setRayon(4) ; 
    O.afficherCaracteristiques() ; 
    cout << endl ; */ 

    /*// Test sur un tableau de figures
    Figure * Tab[3] ; 
    Tab[0] = new Carre(4) ; 
    Tab[1] = new Cercle(2, "rouge") ; 
    Tab[2] = new TriangleEquilateral(3) ; 
    
    for (int i=0 ; i<3 ; i++)
    {
        cout << "Perimetre : " << Tab[i]->perimetre()  << endl ; 
        Tab[i]->afficherCaracteristiques() ;
        cout << endl ; 
    }
    cout << "cpt = " << Figure::cpt << endl ; */

    list <Figure*> mesFigures ;
    list <Figure*>::iterator it ;
    mesFigures.push_back(new Carre(2)) ; 
    mesFigures.push_back(new Cercle(3, "bleu")) ; 
    mesFigures.push_back(new TriangleEquilateral(2)) ; 
    mesFigures.push_back(new Rectangle(2,3)) ; 
    mesFigures.pop_back() ; 
    cout << "La liste est-elle vide ? " << mesFigures.empty() << endl ; 
    for (it=mesFigures.begin() ; it!=mesFigures.end() ; it++) 
    {
        cout << "Perimetre : " << (*(*it)).perimetre()  << endl ; 
        (*it)->afficherCaracteristiques() ; 
        if (typeid((*(*it)))==typeid(Cercle))
            (*it)->afficherCouleur() ; // dynamic_cast <Cercle*> (*it)->getCouleur() ; 
        cout << endl ; 
    }    
    if (it==mesFigures.end()) 
        cout << "L'iterateur est arrive a la fin de la liste" << endl ; 
    else 
        cout << "L'iterateur n'est pas arrive a la fin de la liste" << endl ; 
}