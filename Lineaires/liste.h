#ifndef LISTE_H
#define LISTE_H

#include <stdbool.h>

// ─────────────────────────────
// Définition des structures
// ─────────────────────────────

// Maillon d’une liste chaînée
typedef struct sNode {
    int data;
    struct sNode *next;
} Node;

// Liste chaînée contenant un pointeur vers la tête et sa taille
typedef struct {
    Node *tete;
    int taille;
} Liste;

// ─────────────────────────────
// Prototypes de fonctions
// ─────────────────────────────

// Initialise une liste vide
void init_liste(Liste *lst);

// Renvoie la longueur de la liste
int len(Liste lst);

// Renvoie vrai si la liste est vide
bool est_vide(Liste lst);

// Ajoute un élément en tête de liste
void ajouter_tete(Liste *lst, int elt);

// Renvoie une chaîne représentant la liste (penser à free après usage)
char *str_liste(Liste *lst);

// Remplit la liste avec un exemple de valeurs
void exemple(Liste *lst);

#endif // LISTE_H
