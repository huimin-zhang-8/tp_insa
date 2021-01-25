#include <stdio.h>

struct Structure
{
    unsigned short perm : 4 ; 
    unsigned short user : 1 ;
    unsigned short ring : 3 ;
    unsigned short irq : 4 ;
    unsigned short flag : 4 ;
};

void Afficher(struct Structure S)
{
    printf("perm : %d\n user : %d\n ring : %d\n irq %d\n flag %d\n\n", S.perm, S.user, S.ring, S.irq, S.flag) ; 
}

int main()
{
    // Affectation champs à champs
    struct Structure S1 ;

    S1.perm = 0b1100 ; 
    S1.user = 0b1 ; 
    S1.ring = 0b111 ; 
    S1.irq = 0b1011 ; 
    S1.flag = 0b0011 ; 
    Afficher(S1) ; 

    // Affectation globale
    struct Structure S2 = {12, 1, 7, 11, 3};
    Afficher(S2) ; 

    return 0 ;
}