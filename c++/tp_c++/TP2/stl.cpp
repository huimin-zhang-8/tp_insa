#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std ; 

int main() 
{
    // Exo 1 
    float tab[10] ; 
    for (int i=0 ; i<10 ; i++)
        tab[i] = 0.1*i ; 
    vector <float> v1(tab, tab+10) ; 
    vector <float> v2(v1) ; 
    vector <float>::iterator it, aux ; 
    cout << "Test sur vecteur : " << endl ; 
    cout << "Avant : " ; 
    for (size_t i=0 ; i<v2.size() ; i++)
        cout << v2[i] << " " ; 
    cout << endl ; 
    it = v2.begin() ;
    for (size_t i=0 ; i<v2.size()/2-1 ; i++)
        it++ ; 
    while (true)
    {
        aux = it;
        aux++;
        if (aux == v2.end())
            break;
        v2.erase(aux);
    } 
    //v2.erase(v2.begin()+v2.size()/2, v2.end()) ;
    cout << "Apres : " ; 
    for (size_t i=0 ; i<v2.size() ; i++)
        cout << v2[i] << " " ; 
    cout << endl ; 
    cout << endl ; 

    // Exo 2 
    char ch[] = {'a','b','c','d','e','f','g','h','i','j' } ; 
    list <char> l1(ch,ch+sizeof(ch)/sizeof(char)) ; 
    list <char> l2(l1) ; 
    list <char>::iterator lit1, lit2 ; 
    cout << "Test sur liste : " << endl ; 
    cout << "Avant : " ;
    for (lit1=l2.begin() ; lit1 !=l2.end() ; lit1++)
        cout << *lit1 << " " ; 
    cout << endl ; 
    lit2 = l2.begin() ; 
    for (size_t i=0 ; i<l2.size()/2 ; i++)
        lit2++ ; 
    l2.erase(l2.begin(), lit2) ;
    cout << "Apres : " ;
    for (lit1=l2.begin() ; lit1 !=l2.end() ; lit1++)
        cout << *lit1 << " " ; 
    cout << endl << endl ; 

    // Exo 3 
    string tab_eleves[] = {"Huimin", "Nghi", "Nicolas", "Chloe", "Yasmine", "Lea"} ; 
    set <string> eleves(tab_eleves, tab_eleves+6) ;
    set <string>::iterator sit ; 
    cout << "Test sur set : " << endl ; 
    cout << "Avant : " ; 
    for (sit=eleves.begin() ; sit!=eleves.end() ; sit++)
        cout << *sit << " " ;
    cout << endl ;  
    eleves.erase(eleves.begin()) ; 
    eleves.erase(eleves.begin()) ; 
    cout << "Apres : " ; 
    for (sit=eleves.begin() ; sit!=eleves.end() ; sit++)
        cout << *sit << " " ;
    cout << endl << endl ;  

    // Exo 4 
    map <string,int> annuaire ; 
    map <string,int>::iterator mit ; 
    annuaire["Eloise"] = 654845231 ; 
    annuaire["Maeva"] = 744546421 ; 
    annuaire["Loic"] = 621258457 ; 
    cout << "Test sur map : " << endl ; 
    for (mit=annuaire.begin() ; mit!=annuaire.end() ; mit++)
        cout << "Numero de " << mit->first << ": 0" << mit->second << endl ; 
    cout << endl ; 

    // Exo 5 
    string maTab[] = {"bonjour", "hello", "ciao", "goodbye", "sayonara"} ; 
    vector <string> v(maTab,maTab+5) ; 
    cout << "Test sur algos : " << endl ; 
    cout << "Avant : " ; 
    for (size_t i=0 ; i<v.size() ; i++)
        cout << v[i] << " " ; 
    cout << endl ; 
    sort(v.begin(), v.end()) ; 
    cout << "Apres : " ; 
    for (size_t i=0 ; i<v.size() ; i++)
        cout << v[i] << " " ; 
    cout << endl << endl ; 

    // Exo 6 
    string str[] = {"il", "fait", "beau"} ; 
    list <string> maListe(str, str+3) ; 
    list <string>::iterator lit3 ; 
    lit3 = find(maListe.begin(), maListe.end(), "beau") ; 
    maListe.insert(lit3--, "tres") ; 
    for (lit3=maListe.begin() ; lit3!=maListe.end() ; lit3++)
        cout << *lit3 << " " ; 
    cout << endl ; 
}
