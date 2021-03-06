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
        virtual vecteur & operator = (const vecteur & un_vecteur) ; 
        virtual vecteur & operator += (const vecteur & un_vecteur) ; 
        // Accesseurs
        int get_dim() {return dim ;}
        // Ami
        friend vecteur multiplication (float f, vecteur & v) ; 

};

vecteur operator + (const vecteur & v1, const vecteur & v2) ;
vecteur multiplication (float f, vecteur & v) ;

#endif 