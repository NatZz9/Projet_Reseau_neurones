#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/////////////  fonctions liste  ////////////

l creerl() {
    return NULL;
}

void afficherl(l liste){
    l copy = liste;
    printf("[ ");
    while(copy != NULL){
        printf("%d ",copy->val);
        copy = copy->next;
    }
    printf("]");
}


l ajouter_queue(l liste, int e){
    l new = (Liste*) malloc(sizeof(Liste));
    if (new == NULL) {
        perror("Erreur d'allocation de mémoire.\n");
        exit(1);
    }
    new->val = e;
    new->next = NULL;
    if (liste == NULL){
        return new;
    }
    else{
        l temp = liste;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
        return liste;
    }
}

l supprimer_tete(l liste){
    if (liste != NULL){
        l temp = liste;
        liste = liste->next;
        free(temp);
    }
    return liste;
}