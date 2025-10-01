#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int v;
    struct cellule* suiv;
} cellule;

cellule* creerCellule(int valeur) {
    cellule* NouvelleCellule = (cellule*)malloc(sizeof(cellule));
    NouvelleCellule->v = valeur;
    NouvelleCellule->suiv = NULL;
    return NouvelleCellule;
}

void insertionFin(cellule** tete, int valeur) {
    cellule* NouvelleCellule = creerCellule(valeur);
    if (*tete == NULL) {
        *tete = NouvelleCellule;
        return;
    }
    cellule* temp = *tete;
    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }
    temp->suiv = NouvelleCellule;
}

void SupprimeOccurance(cellule** tete, int val) {
    cellule* temp = *tete;
    cellule* prec = NULL;

    while (temp != NULL) {
        if (temp->v == val) {
            if (prec == NULL) {
                *tete = temp->suiv;
                free(temp);
                temp = *tete;
            } else {
                prec->suiv = temp->suiv;
                free(temp);
                temp = prec->suiv;
            }
        } else {
            prec = temp;
            temp = temp->suiv;
        }
    }
}

void Afficher(cellule* tete) {
    cellule* temp = tete;
    while (temp != NULL) {
        printf("%d -> ", temp->v);
        temp = temp->suiv;
    }
    printf("NULL\n");
}

int main() {
    cellule* tete = NULL;
    int n, valeur, val;

    printf("Combien d'elements dans la liste ? ");
    scanf("%d", &n);

    printf("Entrez les elements :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &valeur);
        insertionFin(&tete, valeur);
    }

    printf("Liste initiale : ");
    Afficher(tete);

    printf("Entrez la valeur a supprimer : ");
    scanf("%d", &val);

    SupprimeOccurance(&tete, val);

    printf("Liste apres suppression : ");
    Afficher(tete);

    return 0;
}
