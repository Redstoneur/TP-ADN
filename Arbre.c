#include <stdio.h>
#include <malloc.h>
#include "Arbre.h"

/**
 * @description: convertir les lettres A, T, C, G en leur numéro correspondant (0, 1, 2, 3)
 * @param c : la lettre à convertir
 * @return : le numéro correspondant à la lettre
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
 * @param i numéro de la lettre
 * @return lettre correspondante
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
 * @param sequence : la séquence à construire
 * @return : l'arbre construit
 */
Arbre constructionArbre(char sequence[301]) {
    Arbre *noeudOrigine = malloc(sizeof(Arbre));
    char seq[5];
    int posSeq[5];
    Noeud *noeud, *oldNoeud;
    for (int i = 0; i < 301-5; i++) {
        printf("i = %d\n", i);
        for(int n = i; n < i+5; n ++) {
            printf("n = %d\n", n);
            printf("seq = %c\n", sequence[n]);
            seq[n % 5] = sequence[n];
            posSeq[n % 5] = n;
        }
        noeud = noeudOrigine->noeuds[numATCG(seq[0])];
        noeud = constructionNoeud(seq, posSeq, 0);
        for (int j = 0; j < 5; j++) {
            if (noeud == NULL) {
                oldNoeud->subnoeuds[j] = noeud;
                break;
            } else {
                oldNoeud = noeud;
                noeud = noeud->subnoeuds[numATCG(seq[j + 1])];
            }
        }
    }
    return *noeudOrigine;
}

/**
 * @description: construire un noeud à partir d'une séquence
 * @param sequence : séquence à partir de laquelle construire le noeud
 * @param i : indice du noeud
 * @return : le noeud construit
 */
Noeud *constructionNoeud(char sequence[5], int positions[5], int i) {
    Noeud *noeud = malloc(sizeof(Noeud));
    noeud->numATCG = numATCG(sequence[i]);
    noeud->ATCG = sequence[i];
    if (i == 4) {
        noeud->term = 1;
    } else {
        noeud->term = 0;
        noeud->subnoeuds[numATCG(sequence[i + 1])] = constructionNoeud(sequence, positions, i + 1);
    }
    return noeud;

}

void afficherNoeud(Noeud *noeud) {
    printf("%c", numATCG_char(noeud->numATCG));
    if (noeud->term) {
        printf("\n");
    } else {
        for (int i = 0; i < 4; i++) {
            afficherNoeud(noeud->subnoeuds[i]);
        }
    }
}

/**
 * @description: afficher l'arbre
 * @param arbre : arbre à afficher
 */
void afficherArbre(Arbre *arbre) {
    for (int i = 0; i < 4; i++) {
        if (arbre->noeuds[i] != NULL) {
            printf("%c : ", numATCG_char(i));
            afficherNoeud(arbre->noeuds[i]);
        }
    }
}

/**
 * @description: rechercher un mot dans l'arbre
 * @param noeudOrigine : noeud d'origine de l'arbre
 * @param mot : mot à rechercher (séquence) dans l'arbre (arbre) (char[5])
 * @return 1 si le mot est dans l'arbre, 0 sinon
 * @return -1 si le mot n'est pas une séquence ADN de 5 lettres
 * @return -2 si l'arbre est vide
 */
int searchNoeud(Arbre *noeudOrigine, char mot[5]) {
    Noeud *noeud = NULL;
    if (isAdnWord(mot) != 1) {
        return -1;
    }
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            noeud = noeudOrigine->noeuds[numATCG(mot[i])];
        }
        printf("i = %d\n", i);
        printf("num = %d\n", noeud->numATCG);
        if (mot[i + 1] == '\0' && noeud->subnoeuds[numATCG(mot[i + 1])] == NULL) {
            return noeud->term;
        } else {
            noeud = noeud->subnoeuds[numATCG(mot[i + 1])];
        }
    }
    if (noeud == NULL) {
        return -2;
    } else {
        return noeud->term;
    }
}

/**
 * @description: libérer un noeud de l'arbre
 * @param noeud : noeud à libérer
 */
void liberationNoeud(Noeud *noeud) {
    if (noeud->term) {
        free(noeud);
    } else {
        for (int i = 0; i < 4; i++) {
            liberationNoeud(noeud->subnoeuds[i]);
        }
        free(noeud);
    }
}

/**
 * @description: libérer l'arbre
 * @param arbre : arbre à libérer
 */
void liberationArbre(Arbre *arbre) {
    for (int i = 0; i < 4; i++) {
        if (arbre->noeuds[i] != NULL) {
            liberationNoeud(arbre->noeuds[i]);
        }
    }
    free(arbre);
}


/**
 * @description: vérification que la séquence est bien une séquence ADN de 5 lettres
 * @param mot : séquence à vérifier
 * @return 1 si la séquence est une séquence ADN de 5 lettres, 0 sinon
 */
int isAdnWord(char mot[]) {
    for (int i = 0; i < 5; i++) {
        if (mot[i] != 'A' && mot[i] != 'T' && mot[i] != 'C' && mot[i] != 'G') {
            return 0;
        }
    }
    return mot[5] == '\0';
}
