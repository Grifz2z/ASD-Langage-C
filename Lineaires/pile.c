/*Anton Alvarez Martinez
10/2025
Implématation d'une pile en C, des primitives usuelles
en utilisant des listes chaînées
*/

#include "liste.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sPile {
  Liste *head;
} pile;

/// Initialisation de la pile
void init_pile(pile *p) {
  // AAllocation de l'espace pour la liste
  p->head = malloc(sizeof(Liste));
  init_liste(p->head);
}

/// Retourne true si la pile est vide
bool pile_est_vide(pile* p) {
  return (p->head->tete == 0);
}

/// Ajout d'un élement dans la liste
void empiler(pile *p, int val) { ajouter_tete(p->head, val); }

/// Dépile le premier élement et le retourne
int depiler(pile *p) {
  assert(p->head->tete != 0);
  int val = pop(p->head, 0);
  return val;
}

/// Retourne un entier, la taille de la pile
int taille(pile *p) {
   return p->head->taille; 
}

/// Retourne le premier elt de la pile sans changer la pile
int peek(pile* p){
  assert(p->head->tete != 0);
  int elt = depiler(p);
  empiler(p, elt);
  return elt;
}

/// Vide la pile et libère la mémoire
void vider(pile* p){
  while (!pile_est_vide(p))
  {
    free(p->head);
  }
}

char* str_pile(pile* p){
  return str_liste(p->head); 
}

/// Crée un exemple de pile
void ex_pile(pile* p){
  empiler(p, 0);
  empiler(p, 42);
  empiler(p,33);
  empiler(p, 1);
}

int main(int argc, char *argv[]){
  // Tests pour s'assurer du bon comportement de la pile.
  pile ma_pile;
  init_pile(&ma_pile);
  ex_pile(&ma_pile);
  printf(" On a la pile suivante, grâce à une liste chaînée :\n %s\n", str_pile(&ma_pile));
  
  int dernier_elt = depiler(&ma_pile);
  printf("On dépile le premier élement, donc la pile est : %s\n", str_pile(&ma_pile));
  printf("et le dernier élement est: %d\n", dernier_elt);

  empiler(&ma_pile, dernier_elt);
  printf("On le réempile, d'où :\n%s\n", str_pile(&ma_pile));

  return 0;
}
