#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// On définit une première struct "Node"
typedef struct sNode{
    int data; // Valeur du maillon
    struct sNode *next; // Pointeur vers le prochain maillon
} Node ;

// Ici on a le problème original avec la structure récursive Node, donc on crée une struct "Liste" pour pouvoir manier les Node

typedef struct {
    Node* tete; // Premier maillon de la liste
    int taille; // Taille de la liste
} Liste ;

void init_liste(Liste* lst) {
    // Initialisation de la liste
    lst->tete = NULL;
    lst->taille = 0;
}

int len(Liste lst) {
    // Un entier, la longueur de la liste
    return lst.taille;
}

bool est_vide(Liste lst) {
    // Un booléen quie est vrai si la liste est vide
    return (lst.taille == 0);
}

void ajouter_tete(Liste* lst, int elt) { 
    Node* new = malloc(sizeof(Node));
    
    // On met à jour la taille de 1 
    lst->taille += 1; 
    
    //On met la valeur souhaité dans le maillon, puis on met son pointeur sur l'ancien maillon tête de la liste
    new->data = elt;
    new->next = lst->tete;
    // On met à jour la tête de la liste
    lst->tete = new;
}

int pop_tete(Liste* lst){
    assert(!est_vide(*lst));

    int tpmp = lst->tete->data; 
    lst->tete = lst->tete->next;
    lst->taille --;

    return tpmp;
}

int pop(Liste* lst, int i) {
    assert(! (len(*lst) <=1) );
    assert(i<len(*lst));

    Node* current = lst->tete;
    Node* avant= NULL;
    int tpmp;

    if (i==0) {
        return pop_tete(lst);
    }

    for (int j = 0; j<i; j++) {
        avant = current;
        current = current->next;
    }

    lst->taille --;
    tpmp = current->data;
    avant->next = current->next;
    free(current);
    return tpmp;
}

char* str_liste(Liste* lst){
    
    if (lst->tete == NULL) {
        return "_|_"; // on ne veut pas de segmentation fault
    }

    Node* waza = lst->tete; // Au lieu de Node waza = *lst->tete; car ici on aurait crée une copie de lst->tete au lieu de juste le manipuler, qui est safe dans ce cas 
    Node* current = lst->tete;
    int taille_totale = 4;

    for (int i =0;i<lst->taille;i++) {
        taille_totale = taille_totale + snprintf(NULL, 0, "%d", waza->data) + 3;
        waza = waza->next;
    }

    char* chaine = malloc(taille_totale + 1);
    chaine[0] = '\0'; // sinon kaputt

    while (current != NULL) {
        // chaine += waza.data + {'-', '>', ' '}; illégal car {'-', '>', ' '} est pour INITIALISER, de plus,
        // "+=" n'est pas possible en C car il n'y a pas d'overload pour les char* (pythonerie attention)
        // Alors, on fait plus classiquement
        // chaine = chaine + waza.data + "-> "
        // N'est tout de même pas possible car c'est du C...😽
        // On doit utiliser strcat de <string.h>, car la concaténation n'est pas imédiate.
        //
        // Pour transformer un int en char*, on utilise sprintf
        char* buf = malloc (snprintf(NULL, 0, "%d", current->data)+1);
        sprintf(buf, "%d", current->data);
        

        chaine = strcat(chaine, buf);
        chaine = strcat(chaine, "-> ");

        current = current->next;
    } 
    
    chaine = strcat(chaine, "_|_");

    return chaine;
}

void exemple(Liste* lst){
    // Exemple de liste
    ajouter_tete(lst, 42);
    ajouter_tete(lst, 33);
    ajouter_tete(lst, 1);
}

int main() {
    Liste ma_liste;
    init_liste(&ma_liste);
    printf(str_liste(&ma_liste));
    printf("\n\n");
    exemple(&ma_liste);
    printf(str_liste(&ma_liste));
    printf("\n Taille de lst : %d \n", ma_liste.taille);

    pop(&ma_liste, 0);
    printf("-------------------\n");
    printf("\n Taille de lst : %d \n", ma_liste.taille);
    int wazaa = ma_liste.tete->data;
    printf("tete: %d\n\n", wazaa);
    printf("%s", str_liste(&ma_liste));
    printf("\n");


    return 0;
}
