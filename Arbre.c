#include <stdio.h>
#include <malloc.h>
#include "Arbre.h"

/**
 * @description: convertir les lettres A, T, C, G en leur numéro correspondant (0, 1, 2, 3)
 * @param c
 * @return
 */
int numATCG(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'C') return 2;
    if (c == 'G') return 3;
    return -1;
}

/**
 * @description: convertir les numéros 0, 1, 2, 3 en leur lettre correspondante (A, T, C, G)
 * @param i
 * @return
 */
char numATCG_char(int i) {
    if (i == 0) return 'A';
    if (i == 1) return 'T';
    if (i == 2) return 'C';
    if (i == 3) return 'G';
    return '\0';
}

/**
 * @description: construire l'arbre à partir d'une séquence
 * @param sequence
 * @return
 */
Arbre constructionArbre(char sequence[301]) {
    Arbre *noeudOrigine = malloc(sizeof(Arbre));
    char seq[5];
    for (int i = 0; i < 301; i++) {
        seq[i % 5] = sequence[i];
        if (i % 5 == 4) {
            noeudOrigine->noeuds[numATCG(seq[0])] = constructionNoeud(seq, 0);
        }
    }
    return *noeudOrigine;
}

/**
 * @description: construire un noeud à partir d'une séquence
 * @param sequence : séquence à partir de laquelle construire le noeud
 * @param i : indice du noeud
 * @return
 */
Noeud *constructionNoeud(char sequence[5], int i) {
    Noeud *noeud = malloc(sizeof(Noeud));
    noeud->numATCG = numATCG(sequence[i]);
    noeud->ATCG = numATCG_char(noeud->numATCG);
    if (i == 4) {
        noeud->term = 1;
    } else {
        noeud->term = 0;
        noeud->subnoeuds = constructionNoeud(sequence, i + 1);
    }
    return noeud;

}

/**
 * @description: rechercher un mot dans l'arbre
 * @param noeudOrigine : noeud d'origine de l'arbre
 * @param mot : mot à rechercher (séquence) dans l'arbre (arbre) (char[5])
 * @return
 */
int searchNoeud(Arbre *noeudOrigine, char mot[5]) {
    Noeud *noeud = NULL;
    for (int i = 0; i < 5; i++) {
        if (i == 0){
            noeud = noeudOrigine->noeuds[numATCG(mot[i])];
        } else if (numATCG(mot[i]) == -1) {
            return 0;
        } else if (noeud->subnoeuds[numATCG(mot[i])] == NULL) {
            return noeud->term;
        } else {
            noeud = noeud->subnoeuds[numATCG(mot[i])];
        }
    }
    return noeud->term;
}

