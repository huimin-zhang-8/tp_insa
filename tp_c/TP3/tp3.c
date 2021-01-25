#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Cellule
{
  int Entier ;
  struct Cellule * Suivant ;
};

struct Pile_Entiers
{
  struct Cellule * Premier ;
  int Taille ;
};

typedef struct Programme
{
  char **tokens;
  int taille;
} Programme;

struct Etat
{
  struct Pile_Entiers * Une_Pile ;
  struct Programme * Un_Programme ; 
};

int numberOfDelimiters(char* string)
{
  int count = 0;
  for (int i=0;i<strlen(string);i++)
    {
      if (string[i] == ' ') count++;
    }
  return count;
}

Programme* lexer(char* chaine)
{
  char *token,*str;
  str = strdup(chaine);
  int i=0;
  char** programme = (char**) malloc(sizeof(char*) * (numberOfDelimiters(str)+1));
  token = strtok(&(*str), " ") ;
  while ( (token != NULL) )
    {
      programme[i] = token;
      i++;
      token = strtok(NULL, " ") ;
    }
  Programme *retour = (Programme*)malloc(sizeof(Programme));
  retour->tokens = programme;
  retour->taille = i;
  return retour;
}

struct Pile_Entiers * Creer_Pile()
{
  struct Pile_Entiers * Pile_Vide = malloc(sizeof(struct Pile_Entiers));
  Pile_Vide->Premier = NULL ;
  Pile_Vide->Taille = 0 ; 
  return(Pile_Vide) ;
}

int Est_Vide (struct Pile_Entiers Une_Pile)
{
  return(Une_Pile.Premier==NULL) ;
}

void Afficher(struct Pile_Entiers Une_Pile)
{
  if (Est_Vide(Une_Pile))
    printf("La pile est vide ! \n") ;
  else
    {
      printf("Pile : ") ;
      while (Une_Pile.Premier != NULL)
	{
	  printf("%d ", Une_Pile.Premier->Entier) ;
	  Une_Pile.Premier = Une_Pile.Premier->Suivant ;
	}
      printf("\n") ;
    }
}

void Empiler(int Entier, struct Pile_Entiers * Une_Pile)
{
  struct Cellule * New_Cellule ;
  New_Cellule = malloc(sizeof(struct Cellule)) ;
  New_Cellule->Entier = Entier ;
  New_Cellule->Suivant = Une_Pile->Premier ; 
  
  Une_Pile->Premier = New_Cellule ;
  Une_Pile->Taille++; 
}

int Depiler(struct Pile_Entiers * Une_Pile)
{
  int valeur ; 
  struct Cellule * Ancien;
  if (Est_Vide(*Une_Pile))
    printf("La file est vide !") ;
  else
    {
      Ancien = Une_Pile->Premier ;
      Une_Pile->Premier = Une_Pile->Premier->Suivant ;
      Une_Pile->Taille-- ;
      valeur = Ancien->Entier ; 
      free(Ancien) ;
    }
  return(valeur) ; 
}

void Executer(struct Etat * Un_Etat)
{
  int val1, val2, resultat ; 

  for (int i = 0 ; i < Un_Etat->Un_Programme->taille ; i++)
  {
    // Si le token est un opérateur arithmétique
    if (ispunct(Un_Etat->Un_Programme->tokens[i][0]))
    {
      // S'il y a au moins 2 nombres dans la pile
      if (Un_Etat->Une_Pile->Taille >= 2)
      {
        val1 = Depiler(Un_Etat->Une_Pile) ; 
        val2 = Depiler(Un_Etat->Une_Pile) ; 
        if (strcmp(Un_Etat->Un_Programme->tokens[i],"+") == 0)
        {
          resultat = val1 + val2 ; 
        }
        else if (strcmp(Un_Etat->Un_Programme->tokens[i],"-") == 0)
        {
          resultat = val2 - val1 ; 
        }
        else if (strcmp(Un_Etat->Un_Programme->tokens[i],"*") == 0)
        {
          resultat = val1 * val2 ; 
        }
        else if (strcmp(Un_Etat->Un_Programme->tokens[i],"/") == 0)
        {
          if (val1 != 0)
          {
            resultat = val2 / val1 ; 
          }
          else 
          {
            printf("ERROR : Division par 0") ; 
            break ; 
          }
        }
        else // L'opérateur n'est pas +, -, * ou /
        {
          printf("ERROR : Operateur inconnu\n") ; 
          break ; 
        }
      }
      else // S'il y a moins de 2 nombres dans la pile
      {
       printf("ERROR : Pas assez de nombres pour faire une operation\n") ;
       break ; 
      }
    }
    // Si le token est un nombre
    else if (isdigit(Un_Etat->Un_Programme->tokens[i][0]))
    {
      resultat = atoi(Un_Etat->Un_Programme->tokens[i]) ;  
    }
    else // Si le token n'est ni un opérateur arithmétique ni un nombre
    {
      printf("ERROR : Le token n'est ni un operateur ni un nombre\n") ; 
      break ; 
    }
    Empiler(resultat, Un_Etat->Une_Pile) ; 
  }
}

int main(int argc, char * argv[])
{
  // Test des fonctions de la pile
  /*struct Pile_Entiers Ma_Pile ;
  Ma_Pile = Creer_Pile() ;
  Afficher(Ma_Pile) ;
  Empiler(8,&Ma_Pile) ;
  Afficher(Ma_Pile) ; 
  Empiler(5,&Ma_Pile) ;
  Afficher(Ma_Pile) ;
  Depiler(&Ma_Pile) ;
  Afficher(Ma_Pile) ;
  printf("\n") ; */

  // Test d'affichage des différents tokens
  /* Programme * Mon_Programme = lexer(argv[1]) ;
  for (int i = 0 ; i < Mon_Programme->taille ; i++)
    printf("TOKEN : %s\n", Mon_Programme->tokens[i]) ; */

  struct Pile_Entiers * Ma_Pile = Creer_Pile(); 
  struct Etat Mon_Etat ; 
  Mon_Etat.Une_Pile = Ma_Pile ; 

  if (argc >= 2)
  {
    Mon_Etat.Un_Programme = lexer(argv[1]) ; 
    for (int i = 0 ; i < Mon_Etat.Un_Programme->taille ; i++)
      printf("TOKEN : %s\n", Mon_Etat.Un_Programme->tokens[i]) ;
    Executer(&Mon_Etat) ; 
    printf("SORTIE : %d\n", Ma_Pile->Premier->Entier) ; // A modifier selon les différents cas 
  }
  
  return 0;
}
