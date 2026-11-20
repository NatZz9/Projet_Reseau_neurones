#ifndef PROJET_LO21_RESEAU_H
#define PROJET_LO21_RESEAU_H

#include "liste.h"

typedef struct neurone{
    l poids;
    int seuil;
} neurone;


neurone* InitNeur(l p, int s);
int Outneurone(neurone* n, struct elem * liste);

#endif //PROJET_LO21_RESEAU_H