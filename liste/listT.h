# include <stdio.h>
# include "infoT.h"

typedef struct t_cellule {
    Info *info;
    struct t_cellule *suivant;
} Cellule, *Liste;

void sortirSurErreur(char message[]){
    printf("Erreu sur %s\n", message);
}

// Initialisation d'une liste vide
Liste initListeVide(void) {
    return NULL;
}

// Verifie si une liste est vide
int listeVide(Liste l) {
    return (l == NULL);
}

// Acces a la premiere information de la liste: tete
Cellule * tete(Liste l) {
    if (listeVide(l)) sortirSurErreur("Tete");
    return l; // (a(...))
}

// Access a la deuxieme composant de la liste: queue
Liste queue(Liste l) {
    if (listeVide(l)) sortirSurErreur("Queue");
    return l->suivant; // (a(b())) -> (b())
}

// Ajout d'un element en tete
Liste constructeur(Cellule *c, Liste l) {
    if (c != NULL) {
        c->suivant = l;
    }
    return c;
}

// Supression de l'element en tete
Liste supprimeTete(Liste l, void(*lc) (Cellule *c)) {
    Cellule *t;

    if (!listeVide(l)) {
        t = l;
        l = l->suivant;
        lc(t);
    }

    return l;
}

// Calcul de la longueur d'une liste: nombre d'element
int longueurListe(Liste l) {
    int lg;

    if (listeVide(l)) lg = 0;
    else lg = 1 + longueurListe(queue(l));

    return lg;
}

// Ajout en queue
Liste ajoutQueue(Cellule *c, Liste l) {
    Liste l2;

    if (listeVide(l)) {
        l2 = constructeur(c, l);
    } else {
        l2 = constructeur(tete(l), ajoutQueue(c, queue(l)));
    }

    return l2;
}

// Supression du dernier element
Liste supprimeQueue(Liste l, void(*lc) (Cellule *)) {
    Liste l2;

    if (!listeVide(l)) {
        if (listeVide(queue(l))) {
            l2 = supprimeTete(l, lc);
        } else {
            l2 = constructeur(tete(l), supprimeQueue(queue(l), lc));
        }
    } else {
        l2 = initListeVide();
    }

    return l2;
}

// Insertion en une position donnee
Liste ajoutPosition(Liste l, Cellule *c, int n) {
    Liste l2;

    if (n < 1) l2 = l;
    else if (n == 1)  l2 = constructeur(c, l);
    else if (!listeVide(l)) l2 = constructeur(tete(l), ajoutPosition(queue(l), c, n-1));
    else l2 = initListeVide();

    return l2;
}

// Suppression d'un element de positon donnee
Liste supprimePosition(Liste l, int n, void(*lc) (Cellule *c)) {
    Liste l2;

    if (n < 1) l2 = l;
    else if (n == 1) l2 = supprimeTete(l, lc);
    else if (!listeVide(l)) l2 = constructeur(tete(l), supprimePosition(queue(l), n-1, lc));
    else l2 = initListeVide();

    return l2;
}

// Insertion trie ou sur critere quelconque
Liste ajoutTri(Liste l, Cellule *c, int(*oc) (Cellule *, Cellule *)) {
    Liste l2;

    if (listeVide(l)) l2 = constructeur(c, l);
    else {
        if (!oc(c, tete(l))) {
            l2 = constructeur(tete(l), ajoutTri(queue(l), c, oc));
        } else {
            l2 = constructeur(c, l);
        }
    }

    return l2;
}
