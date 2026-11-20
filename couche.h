#ifndef PROJET_LO21_COUCHE_H
#define PROJET_LO21_COUCHE_H

#include "Neurone.h"
#include "liste.h"

/// LISTE COUCHE///

typedef struct layer{
    struct neurone * neur;
    struct layer * next;
} Couche;

typedef Couche *c;

///////////////

c creerc();
void afficherc(c couche);
c ajouter_queue_couche(c couche, struct neurone * e);

c InitCouche(int nb_neur, int nb_entree);
l OutCouche(c couche, l entree);

#endif //PROJET_LO21_COUCHE_H
