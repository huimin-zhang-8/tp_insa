#ifndef VECTEUR_H
#define VECTEUR_H

class vecteur{
    protected : 
        int dim ; 
        float * elements ; 
    public : 
        // Constructeurs
        vecteur(int d=0) ;
        vecteur(int d, float * tab) ;
        vecteur(const vecteur & un_vecteur) ;
        // Destructeur
        ~vecteur() ;
        // Fonctions annexes
        void afficher() const ;
        void saisie() ;
        // Surcharge des opérateurs
        float & operator [] (const int indice) ; 
        vecteur & operator = (const vecteur & un_vecteur) ; 
        vecteur & operator += (const vecteur & un_vecteur) ; 
        // Accesseurs
        int get_dim() {return dim ;}
        float * get_elements() {return elements ;}
};

vecteur operator + (const vecteur & v1, const vecteur & v2) ;

#endif 