#include <iostream>
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
    cout << "cpt = " << Figure::cpt << endl ; 
}