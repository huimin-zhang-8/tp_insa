#include <iostream>
#include <string.h>
using namespace std ; 

class Coloriable
{
    protected :
        string couleur;
    public :
        Coloriable(string coul) {couleur=coul;}
        string getCouleur(){return couleur;}
        void setCouleur(string coul){couleur=coul;}
};

class Figure {
    public : 
        virtual float perimetre()=0 ;
        virtual void afficherCaracteristiques()=0 ; 
        static int cpt ; 
        Figure() ;
};

class Polygone : public Figure {
    private : 
        int nbCotes ; 
    public : 
        Polygone(int n) ;
        virtual void afficherCaracteristiques() ;
        // Inutile de définir le calcul du périmètre pour l'instant car on ne connait pas encore la longueur d'un côté
};

class Rectangle : public Polygone {
    protected : 
        float longueur ; 
        float largeur ; 
    public : 
        Rectangle(float L, float l) ;
        float getLongueur() ; 
        float getLargeur() ; 
        void setCotes(float L, float l) ; 
        virtual float perimetre() ; 
        virtual void afficherCaracteristiques() ; 
};

class Carre : public Rectangle {
    public : 
        Carre(float L) ; 
        void setCote(float L) ; 
        virtual void afficherCaracteristiques() ; 
};

class TriangleEquilateral : public Polygone {
    protected : 
        float cote ; 
    public : 
        TriangleEquilateral(float L) ; 
        float getCote() ; 
        void setCote(float L) ; 
        virtual float perimetre() ; 
        virtual void afficherCaracteristiques() ; 
};

class Cercle : public Figure, public Coloriable {
    private : 
        float rayon ; 
    public : 
        Cercle(float R, string coul) ; 
        float getRayon() ; 
        void setRayon(float R) ; 
        virtual float perimetre() ; 
        virtual void afficherCaracteristiques() ; 
}; 
