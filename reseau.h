#ifndef PROJET_LO21_RESEAU_H
#define PROJET_LO21_RESEAU_H

#include "couche.h"
#include "Neurone.h"
#include "liste.h"

///// LISTE RESEAU /////

typedef struct res{
    c couche;
    struct res * next;
} Reseau;

typedef Reseau *r;

////////////////////////

r creerr();
void afficherr(r reseau);
r ajouter_queue_reseau(r reseau, c couche);

r CreerResNeur(int nb_couche, l nb_neur);

#endif //PROJET_LO21_RESEAU_H
