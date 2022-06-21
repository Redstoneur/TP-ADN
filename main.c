#include <stdio.h>
#include "Arbre.h"

/**
 * @description: main function of the program
 * @return : 0 if everything is ok
 */
int main() {
    // sequence de travail
    char seq[301] = "TCGACCAAGCTGGTTTTTCCGTCCTGCCTTTTCCGATAGAGCGATCCTTTGACTGACTAAGGAGCCGGTAGCGATATACCTAGTATTGCGCGCGTCTCGGAGGGCGAGGCTAGATTTAAACGGGTCCGATTTCGGCCAGCTAAGGATTTGATTAAAAAATGTTTCCCGATCCCAACCATAGGGACTTGGTCTTCCAAAACTAATGACACATGTGAATACAAGATGGATGGAGTGATCCCCATTCGAGCGACGCTGATAGCCTAAGCTGCTCCTGATGCGCCGTTTACTTTGAACTAAGGT";

    // construction de l'arbre
    Arbre arbre = constructionArbre(seq);

    // affichage de l'arbre
    afficherArbre(&arbre);

    // recherche d'un mot dans l'arbre
    char mot[5];
    printf("Entrez le mot de 5 lettres à rechercher : ");
    scanf("%s", mot);

    // resultat de la recherche
    int resultat = searchNoeud(&arbre, mot);

    // affichage du resultat pour l'utilisateur
    if (resultat == 1) {
        printf("Le mot %s est dans l'arbre\n", mot);
    } else if (resultat == 0) {
        printf("Le mot %s n'est pas dans l'arbre\n", mot);
    } else if (resultat == -1) {
        printf("Le mot %s n'est pas une séquence ADN de 5 lettres\n", mot);
    } else if (resultat == -2) {
        printf("L'arbre est vide\n");
    } else{
        printf("Erreur\n");
    }

    // liberation de l'arbre
    liberationArbre(&arbre);

    // fin du programme
    return 0;
}

