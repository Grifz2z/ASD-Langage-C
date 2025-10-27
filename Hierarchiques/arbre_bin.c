#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//typedef int waza;

typedef struct sArbre {
  int val;
  struct *sArbre child;
  struct *sArbre frere;
} Arbre;


