#include <iostream>

class vecteur{
    private : 
        int dim ; 
        float * elements ; 
    public : 
        // constructeurs
        vecteur() ;
        vecteur(int d) ;
        vecteur(int d, float * tab) ;
        vecteur(const vecteur & un_vecteur) ;
        // destructeur
        ~vecteur() ;
        // fonctions annexes
        void afficher() const ;
        void saisie() ;
};