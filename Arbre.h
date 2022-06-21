#ifndef TP_ADN_ARBRE_H
#define TP_ADN_ARBRE_H

typedef struct noeud {
    struct noeud *subnoeuds[4];
    int numATCG;
    char ATCG;
    int term;
} Noeud;

typedef struct arbre {
    Noeud *noeuds[4];
} Arbre;

int numATCG(char c);

char numATCG_char(int i);

Arbre constructionArbre(char sequence[301]);

Noeud *constructionNoeud(char sequence[5], int i);

int searchNoeud(Arbre *noeudOrigine, char mot[]);

#endif //TP_ADN_ARBRE_H
