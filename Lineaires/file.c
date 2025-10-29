/*Anton Alvarez Martinez
10/2025
Implématation d'une file en C (primitives + une fonction d'affichage)
en utilisant des listes chaînées
*/

#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
#include <stdbool.h>
#include <assert.h>

typedef struct sFile{
  Liste* head;
} file;

/// Retourne vrai si la file est vide
bool file_est_vide(file* f){
  return (f->head->taille == 0);
}

/// Retourne la taille de la file
int taille_file(file* f) {
  return f->head->taille;
}

/// Initialisation de la file
void init_file(file* f) {
  // Il faut prévoir de la mémoire pour la liste chaînée
  f->head = malloc(sizeof(Liste));

  // On initialise la liste
  init_liste(f->head);
}

/// Ajout d'un élement dans la liste
void enfiler(file* f, int val){
  ajouter_tete(f->head, val);
}

/// Défile le premier élement entré dans la file
int defiler(file* f){
  assert(f->head->taille != 0);
  return pop(f->head, f->head->taille -1);
}

/// Produit l'affichage d'une file
/// Une chaine de caractères, représentant la file
char* str_file(file* f){
  return str_liste(f->head); 
}

///Exemple de file
void ex_file(file* f){
  enfiler(f, 0);
  enfiler(f, 42);
  enfiler(f,33);
  enfiler(f, 1);
}

//int main(int argc, char *argv[]){
//  // Tests pour s'assurer du bon comportement de la file.
//  file ma_file;
//  init_file(&ma_file);
//  ex_file(&ma_file);
//  printf(" On a la file suivante, grâce à une liste chaînée :\n %s\n", str_file(&ma_file));
//  
//  int dernier_elt = defiler(&ma_file);
//  printf("On défile le dernier élement, donc la file est : %s\n", str_file(&ma_file));
//  printf("et le dernier élement est: %d\n", dernier_elt);
//
//  enfiler(&ma_file, dernier_elt);
//  printf("On le réenfile, d'où :\n%s\n", str_file(&ma_file));
//
//  return 0;
//}
