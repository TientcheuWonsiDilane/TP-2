#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule {
    int val;
    struct Cellule* suiv;
} Cellule;

Cellule* creerCellule(int valeur) {
    Cellule* nouvelleCellule = (Cellule*)malloc(sizeof(Cellule));
    nouvelleCellule->val = valeur;
    nouvelleCellule->suiv = NULL;
    return nouvelleCellule;
}

void insertionTrier(Cellule** tete, int valeur) {
    Cellule* nouvelleCellule = creerCellule(valeur);

    if (*tete == NULL || valeur < (*tete)->val) {
        nouvelleCellule->suiv = *tete;
        *tete = nouvelleCellule;
        return;
    }

    Cellule* current = *tete;
    while (current->suiv != NULL && current->suiv->val < valeur) {
        current = current->suiv;
    }

    nouvelleCellule->suiv = current->suiv;
    current->suiv = nouvelleCellule;
}


void Afficher(Cellule* tete) {
    while (tete != NULL) {
        printf("%d -> ", tete->val);
        tete = tete->suiv;
    }
    printf("NULL\n");
}

int main() {
    Cellule* tete = NULL;
    int n, valeur, val;

    printf("Combien d'elements dans la liste ? ");
    scanf("%d", &n);

    printf("Entrez les elements :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &valeur);
        insertionTrier(&tete, valeur);
    }

    printf("Liste initiale : ");
    Afficher(tete);

    printf("Entrez la valeur a ajouter: ");
    scanf("%d", &val);

    insertionTrier(&tete, val);

    printf("Liste apres insertion: ");
    Afficher(tete);

    return 0;
}

