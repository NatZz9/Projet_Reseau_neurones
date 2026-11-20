#include <stdio.h>
#include <stdlib.h>
#include "reseau.h"
#include "couche.h"
#include "Neurone.h"
#include "liste.h"

/////////////  fonctions liste réseau  ////////////

r creerr() {
    r new = (Reseau*)malloc(sizeof(Reseau));
    if(!new){
        perror("Erreur lors de la creation du reseau");
    }
    else{
        new->couche = NULL;
        new->next = NULL;
    }
    return new;
}

void afficherr(r reseau){
    int i=1;
    if (reseau->couche == NULL){
        printf("reseau vide\n");
    }
    else{
        r copy = reseau;
        while(copy != NULL){
            printf("\n-couche %d :\n",i);
            afficherc(copy->couche);
            i++;
            copy = copy->next;
        }
        printf("\n");
    }
}


r ajouter_queue_reseau(r reseau, c couche){
    r new = (Reseau*) malloc(sizeof(Couche));
    new->couche = couche;
    new->next = NULL;
    if (reseau->couche == NULL){
        return new;
    }
    else{
        r temp = reseau;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
    return reseau;
}

////////////////////////////////////


r CreerResNeur(int nb_couche, l nb_neur){
    printf("nb couche : %d",nb_couche);
    printf("nb_couche : ");
    afficherl(nb_neur);
    r res = creerr();
    ajouter_queue_reseau(res, InitCouche(nb_neur->val, nb_neur->val));
    for(int i=0;i<nb_couche;i++){
        ajouter_queue_reseau(res, InitCouche(nb_neur->next->val, nb_neur->val));
        nb_neur = nb_neur->next;
    }
    return res;
}