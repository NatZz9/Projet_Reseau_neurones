#ifndef PROJET_LO21_LISTE_H
#define PROJET_LO21_LISTE_H


//liste normal
typedef struct elem{
    int val;
    struct elem *next;
} Liste;

typedef Liste *l;

l creerl();
void afficherl(l liste);
l ajouter_queue(l liste, int e);
l supprimer_tete(l liste);

#endif //PROJET_LO21_LISTE_H