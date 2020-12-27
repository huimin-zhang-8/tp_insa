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

struct Pile_Entiers Creer_Pile()
{
  struct Pile_Entiers Pile_Vide ;
  Pile_Vide.Premier = NULL ;
  Pile_Vide.Taille = 0 ; 
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
  Une_Pile->Taille = Une_Pile->Taille++; 
}

void Depiler(struct Pile_Entiers * Une_Pile)
{
  if (Est_Vide(*Une_Pile))
    printf("La file est vide !") ;
  else
    {
      struct Cellule * Ancien ;
      Ancien = Une_Pile->Premier ;
      Une_Pile->Premier = Une_Pile->Premier->Suivant ;
      Une_Pile->Taille = Une_Pile->Taille-- ;
      free(Ancien) ;
    }
}

void Executer(struct Etat * Un_Etat)
{
  for (int i = 0 ; i < Un_Etat->Un_Programme->taille ; i++)
  {
    switch (Un_Etat->Un_Programme->tokens[i])
    {
    case isdigit :
      /* code */
      break;
    }
  }
}

int main(int argc, char * argv[])
{
  struct Pile_Entiers Ma_Pile ;
  Ma_Pile = Creer_Pile() ;
  Afficher(Ma_Pile) ;
  Empiler(8,&Ma_Pile) ;
  Afficher(Ma_Pile) ; 
  Empiler(5,&Ma_Pile) ;
  Afficher(Ma_Pile) ;
  Depiler(&Ma_Pile) ;
  Afficher(Ma_Pile) ;
  printf("\n") ; 

  Programme * Mon_Programme = lexer(argv[1]) ;
  for (int i = 0 ; i < Mon_Programme->taille ; i++)
    printf("TOKEN : %s\n", Mon_Programme->tokens[i]) ; 
  
  return 0;
}
