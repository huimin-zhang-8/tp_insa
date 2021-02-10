#include <iostream>

class vecteur{
    private : 
        int dim ; 
        float * elements ; 
    public : 
        // Constructeurs
        vecteur() ;
        vecteur(int d) ;
        vecteur(int d, float * tab) ;
        vecteur(const vecteur & un_vecteur) ;
        // Destructeur
        ~vecteur() ;
        // Fonctions annexes
        void afficher() const ;
        void saisie() ;
        // Surcharge des opérateurs
        float & operator [] (int indice) ; 
        vecteur & operator = (const vecteur & un_vecteur) ; 
        vecteur & operator += (const vecteur & un_vecteur) ; 
};