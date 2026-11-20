#include <stdio.h>
#include <stdlib.h>
#include "couche.h"
#include "Neurone.h"
#include "liste.h"

/////////////  fonctions liste couche  ////////////

c creerc() {
    c new = (Couche*)malloc(sizeof(Couche));
    if(!new){
        perror("Erreur lors de la creation de la couche");
    }
    else{
        new->neur = NULL;
        new->next = NULL;
    }
    return new;
}

void afficherc(c couche){
    int i=1;
    if (couche->neur == NULL){
        printf("couche vide\n");
    }
    else{
        c copy = couche;
        while(copy != NULL){
            printf("neurone %d :     seuil : %d     poids : ",i,copy->neur->seuil);
            afficherl(copy->neur->poids);
            printf("\n");
            i++;
            copy = copy->next;
        }
        printf("\n");
    }
}


c ajouter_queue_couche(c couche, struct neurone * n){
    c new = (Couche*) malloc(sizeof(Couche));
    if (!new) {
        perror("Erreur d'allocation mémoire pour la couche");
        exit(1);
    }
    new->neur = n;
    new->next = NULL;
    if (couche->neur == NULL){
        return new;
    }
    else{
        c temp = couche;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
    return couche;
}

////////////////////////////////////



c InitCouche(int nb_neurone, int nb_entree){
    c couche = creerc();
    l poids = creerl();
    for (int j = 0; j < nb_entree; j++) {
        ajouter_queue(poids, 0);
        // initialisation a 0 pour chaque poids
    }
    for(int i=0;i<nb_neurone;i++){
        ajouter_queue_couche(couche, InitNeur(poids,0));
        // initialisation a 0 pour chaque seuils
    }
    return couche;
}

l OutCouche(c couche, l entree){
    l sortie = creerl();
    c temp = couche;
    while(temp->neur != NULL){
        ajouter_queue(sortie,Outneurone(temp->neur,entree));
        temp = temp->next;
    }
    return sortie;
}
