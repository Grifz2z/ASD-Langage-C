#include <stdio.h>
#include "liste.h"
#include <stdbool.h>
#include <assert.h>

typedef struct sPile {
    Liste* head;
} pile;

/// Initialisation de la pile
void init_pile(pile* p) {
    Liste lst;
    init_liste(&lst);
}

/// Ajout d'un élement dans la liste
void empiler(pile* p, int val){
    ajouter_tete(p->head, val);
}

/// @brief Dépile le premier élement et le retourne
/// @param p une pile
/// @return La valeur du premier élement
int depiler(pile* p){
    assert(p->taille != 0);
    int val = pop(p->head, 0);
    return val;
}

int taille(pile* p){
    return p->taille;
}
