#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* prec;
    struct Noeud* suiv;
} Noeud;

Noeud* tete = NULL;
Noeud* fin = NULL;

Noeud* creerNoeud(int val) {
    Noeud* nouv = (Noeud*)malloc(sizeof(Noeud));
    nouv->valeur = val;
    nouv->prec = nouv->suiv = NULL;
    return nouv;
}

void insererTete(int val) {
    Noeud* nouv = creerNoeud(val);

    if (tete == NULL) { 
        tete = fin = nouv;
        tete->suiv = tete;
        tete->prec = tete;
    } else {
        nouv->suiv = tete;
        nouv->prec = fin;
        tete->prec = nouv;
        fin->suiv = nouv;
        tete = nouv;
    }
}

void insererQueue(int val) {
    Noeud* nouv = creerNoeud(val);

    if (tete == NULL) { 
        tete = fin = nouv;
        tete->suiv = tete;
        tete->prec = tete;
    } else {
        nouv->suiv = tete;
        nouv->prec = fin;
        fin->suiv = nouv;
        tete->prec = nouv;
        fin = nouv;
    }
}

void Afficher() {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }

    Noeud* temp = tete;
    do {
        printf("%d <-> ", temp->valeur);
        temp = temp->suiv;
    } while (temp != tete);
    printf("(retour a la tete)\n");
}

int main() {
    int n, m, valeur, val;
     
	insererTete(0);

    printf("Combien d'elements dans la liste en tete ? ");
    scanf("%d", &n);
    printf("Combien d'elements dans la liste en queue ? ");
    scanf("%d", &m);

    printf("Liste initiale : ");
    Afficher();

    printf("Entrez les elements a inserer en tete de liste :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &valeur);
        insererTete(valeur);
           printf("Liste apres insertion: ");
    Afficher();
    }
    printf("\n");
    printf("Entrez les elements a inserer en fin de liste :\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &valeur);
        insererQueue(valeur);
           printf("Liste apres insertion: ");
    Afficher();
    }

    return 0;
}

