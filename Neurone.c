#include <stdio.h>
#include <stdlib.h>
#include "Neurone.h"
#include "liste.h"


int f(int x,int s){
    if (x >= s){
        return 1;
    }
    else{
        return 0;
    }
}

neurone* InitNeur(l p,int s){
    neurone *New = (neurone*) malloc(sizeof(neurone));
    New->poids = p;
    New->seuil = s;
    return New;
}

int Outneurone(neurone n, l liste){
    l copy = liste;
    int x;
    while (copy->next != NULL){
        x = x + n.poids->val * copy->val;
        n.poids = n.poids->next;
        copy = copy->next;
    }
    return f(x,n.seuil);
}
