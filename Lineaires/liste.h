/*
Anton Alvarez Martinez
10/2025
Implémentation de listes chaînées en C
*/

#ifndef LISTE_H
#define LISTE_H

#include <stdbool.h>

// ─────────────────────────────
// Structures
// ─────────────────────────────

// Maillon de la liste chaînée
typedef struct sNode {
    int data;              // Valeur du maillon
    struct sNode *next;    // Pointeur vers le prochain maillon
} Node;

// Structure représentant la liste
typedef struct {
    Node *tete;    // Premier maillon
    int taille;    // Taille de la liste
} Liste;

// ─────────────────────────────
// Fonctions de base
// ─────────────────────────────

// Initialise une liste vide
void init_liste(Liste *lst);

// Renvoie la longueur de la liste
int len(Liste lst);

// Renvoie vrai si la liste est vide
bool est_vide(Liste lst);

// Ajoute un élément en tête de liste
void ajouter_tete(Liste *lst, int elt);

// Supprime et renvoie l’élément en tête de liste
int pop_tete(Liste *lst);

// Supprime et renvoie l’élément à l’indice i (0 = tête)
int pop(Liste *lst, int i);

// Renvoie une représentation textuelle de la liste (penser à free)
char *str_liste(Liste *lst);

// Remplit la liste avec des valeurs d’exemple
void exemple(Liste *lst);

#endif // LISTE_H
