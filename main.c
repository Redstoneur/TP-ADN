#include <stdio.h>
#include "Arbre.h"


int main() {
    char sequence[301];
    printf("Entrez la séquence : ");
    scanf("%s", sequence);
    Arbre arbre = constructionArbre(sequence);
    char mot[5];
    printf("Entrez le mot de 5 lettres à rechercher : ");
    scanf("%s", mot);
    printf("%d", searchNoeud(&arbre, mot));
    return 0;
}

