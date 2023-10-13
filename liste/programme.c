# include <stdio.h>
# include <stdlib.h>

# include "listP.h"

Cellule * nouvelleCellule(int v) {
    Cellule *c;

    c = (Cellule *)malloc(sizeof(Cellule));
    c->info = (Info *)malloc(sizeof(Info));
    (*(c->info)).v = v;

    return c;
}

int ordreCellule(Cellule *a, Cellule *b) {
    return ((*(a->info)).v < (*(b->info)).v);
}

void libereCellule(Cellule *c) {
    free(c->info);
    free(c);
}

void afficheListe(Liste l) {
    if (!listeVide(l)) {
        fprintf(stderr, "%d", (*(l->info)).v);
        afficheListe(queue(l));
    } else {
        fprintf(stderr, "\n");
    }
}

int main(int argc, char *argv[], char **envp) {
    Liste l;
    Cellule *c;

    l = initListeVide();
    afficheListe(l);
    c = nouvelleCellule(4);
    l = ajoutTri(l, c, ordreCellule);
    afficheListe(l);
    c = nouvelleCellule(1);
    l = ajoutTri(l, c, ordreCellule);
    afficheListe(l);
    c = nouvelleCellule(2);
    l = ajoutTri(l, c, ordreCellule);
    afficheListe(l);
    l = supprimeTete(l, libereCellule);
    afficheListe(l);
    c = nouvelleCellule(3);
    l = ajoutTri(l, c, ordreCellule);
    afficheListe(l);
    c = nouvelleCellule(5);
    l = ajoutPosition(l, c, 5);
    afficheListe(l);
}
