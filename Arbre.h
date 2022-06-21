#ifndef TP_ADN_ARBRE_H
#define TP_ADN_ARBRE_H

//struct pos {
//    int Entier;
//    struct pos * pSuivant;
//}Pos;
//
//Nouveau = (Liste*)malloc(sizeof(struct Liste));
//Nouveau->pSuivant = Tete;


typedef struct noeud {
    struct noeud *subnoeuds[4];
    int numATCG;
    char ATCG;
    int pos[301];
    int term;
} Noeud;

typedef struct arbre {
    Noeud *noeuds[4];
} Arbre;

int numATCG(char c);

char numATCG_char(int i);

Arbre constructionArbre(char sequence[301]);

Noeud *constructionNoeud(char sequence[5], int positions[5], int i);

int searchNoeud(Arbre *noeudOrigine, char mot[]);

int isAdnWord(char mot[]);

void afficherNoeud(Noeud *noeud);

void afficherArbre(Arbre *arbre);

void liberationNoeud(Noeud *noeud);

void liberationArbre(Arbre *arbre);



#endif //TP_ADN_ARBRE_H
