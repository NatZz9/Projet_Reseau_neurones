#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reseau.h"
#include "couche.h"
#include "Neurone.h"
#include "liste.h"

typedef struct neurone{
    int seuil;
    l poids;
} neurone;

int compter_elt(const char *chaine) {
    int compteur = 0;
    char copie[256];  // Copie temporaire pour ne pas modifier la chaine d origine
    strcpy(copie, chaine);

    char * elt = strtok(copie, ";");
    while (elt != NULL) {
        compteur++;
        elt = strtok(NULL, ";");  // Passe a l element suivant
    }
    return compteur;
}


int main() {
    int nb_couche, neur;
    char seuils[256], poids[256];
    l nb_neur = creerl();
    r res;

    // Demande du nombre de couches
    printf("Nombre de couches de votre reseau : ");
    if (scanf("%d", &nb_couche) != 1 || nb_couche <= 0) {
        printf("\nErreur : veuillez entrer un entier positif.\n");
        return -1;
    }

    // Saisie des informations pour chaque couche
    for (int i = 0; i < nb_couche; i++) {
        printf("Nombre de neurones de la couche %d : ", i + 1);
        if (scanf("%d", &neur) != 1 || neur <= 0) {
            printf("Erreur : veuillez entrer un entier positif.\n");
            return -1;
        }
        ajouter_queue(nb_neur, neur);

        // Demande des seuils
        printf("Seuil de chaque neurone (format nb;nb;nb;...) : ");
        scanf("%s", seuils);

        // Demande des poids
        printf("Poids de chaque entree (format nb;nb;nb;...) : ");
        scanf("%s", poids);

        //test si il y a autant de seuil et de poids que de neurones
        int nbr_poids, nbr_seuil;
        nbr_poids = compter_elt(poids);
        nbr_seuil = compter_elt(seuils);

        if (nbr_poids != neur || nbr_seuil != neur) {
            printf("Erreur : Nombre de poids ou de seuils différent du nombre de neurones indiqué.\n");
            return -1;
        }

        //// VERIFICATION TYPE NEURONE ////

        // verif ET
        int estET = 1; // suppose ET de base
        char *tok_ET = strtok(poids, ";");
        int poids_val;
        while (tok_ET != NULL) {
            poids_val = atoi(tok_ET);
            if (poids_val != 1) {
                estET = 0; // Si un poids est différent de 1 -> pas un ET
                break;
            }
            tok_ET = strtok(NULL, ";");
        }

        // verif OU
        int estOU = 1; // suppose OU de base

        char *tok_OU_s = strtok(seuils, ";");
        int poids_val;
        while (tok_OU_s != NULL) {
            poids_val = atoi(tok_OU_s);
            if (poids_val != 1) {
                estOU = 0; // Si un seuil est différent de 1 -> pas un OU
                break;
            }
            tok_OU_s = strtok(NULL, ";");
        }

        char *tok_OU_p = strtok(poids, ";");
        int poids_val;
        while (tok_OU_p != NULL) {
            poids_val = atoi(tok_OU_p);
            if (poids_val != 1) {
                estOU = 0; // Si un poids est différent de 1 -> pas un OU
                break;
            }
            tok_OU_p = strtok(NULL, ";");
        }

    }

    // Création du réseau
    res = CreerResNeur(nb_couche, nb_neur);

    // Mise à jour des seuils et des poids
    r temp_res = res;
    char *token_s = strtok(seuils, ";");
    char *token_p = strtok(poids, ";");

    printf("Test -1\n");
    while (temp_res != NULL) {
        printf("Test 0\n");
        c temp_couche = temp_res->couche;
        while (temp_couche != NULL) {
            printf("Test 1\n");
            struct neurone* n = temp_couche->neur;
            // Affectation des seuils
            token_s = strtok(NULL, ";");
            n->seuil = atoi(token_s);

            // Affectation des poids
            l temp_poids = n->poids;
            token_p = strtok(NULL, ";");
            printf("Test 2\n");
            while (temp_poids != NULL && token_p != NULL) {
                printf("Test 3\n");
                temp_poids->val = atoi(token_p);
                temp_poids = temp_poids->next;
                token_p = strtok(NULL, ";");
                printf("Test 4\n");
            }
            temp_couche = temp_couche->next;
            printf("Test 5\n");
        }
        temp_res = temp_res->next;
        printf("Test 1,2,1,2 Test, TEEEEEESSSSTTTTT");
    }

    // Affichage pour vérifier la configuration
    printf("\nConfiguration du réseau terminée. Vérification des données :\n");
    afficherr(res);
    r reseauvide = creerr();
    return 0;
}

/// ON NE FAIT PAS DE FREE SUR LES MALLOC ?