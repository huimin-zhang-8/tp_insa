#include <iostream>
#include "figure.h"
using namespace std ; 
const double PI = 3.141592653589793238463;

// Compter les instances de Figure
int Figure::cpt=0 ; 
Figure::Figure() {cpt++ ;}

// Définitions des fonctions de la classe Polygone
Polygone::Polygone(int n) : nbCotes(n) {} 

void Polygone::afficherCaracteristiques() {cout << "Nombre de cote du polygone : " << nbCotes << endl ;}

// Défnitions des fonctions de la classe Rectangle
Rectangle::Rectangle(float L, float l) : Polygone(4) {longueur = max(L,l) ; largeur = min(L,l) ;}

float Rectangle::getLongueur() {return longueur ;}

float Rectangle::getLargeur() {return largeur ;}

void Rectangle::setCotes(float L, float l) {longueur = max(L,l) ; largeur = min(L,l) ;}

float Rectangle::perimetre() {return 2*longueur+2*largeur ;}

void Rectangle::afficherCaracteristiques() {
    Polygone::afficherCaracteristiques() ;
    cout << "Longueur : " << longueur << endl ;
    cout << "Largeur : " << largeur << endl ; 
}

// Définition du constructeur de la classe Carre 
Carre::Carre(float L) : Rectangle(L,L) {}

void Carre::setCote(float L) {longueur = L ; largeur = L ;}

void Carre::afficherCaracteristiques() {
    Polygone::afficherCaracteristiques() ;
    cout << "Longueur : " << longueur << endl ;
}

// Définition des fonctions de la classe TriangleEquilateral
TriangleEquilateral::TriangleEquilateral(float L) : Polygone(3) {cote = L ;}

float TriangleEquilateral::getCote() {return cote ;}

void TriangleEquilateral::setCote(float L) {cote = L ;}

float TriangleEquilateral::perimetre() {return 3*cote ;}

void TriangleEquilateral::afficherCaracteristiques() {
    Polygone::afficherCaracteristiques() ;
    cout << "Longueur du cote : " << cote << endl ;
}

// Definition des fonctions de la classe Cercle
Cercle::Cercle(float R, string coul) : Figure(), Coloriable(coul) {rayon = R ;}

float Cercle::getRayon() {return rayon ;}

void Cercle::setRayon(float R) {rayon = R ;}

float Cercle::perimetre() {return 2*PI*rayon ;}

void Cercle::afficherCaracteristiques() {
    cout << "Rayon du cercle : " << rayon << endl ; 
}

void Cercle::afficherCouleur() {
    cout << "Couleur : " << getCouleur() << endl ; 
}