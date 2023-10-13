# include "infoT.h"

typedef struct {
    Info tab[100];
    int n;
} Pile;

// Initialisation d'un pile vide
Pile initPile(void) {
    Pile p;

    p.n = 0;

    return p;
}

// Verifie si une pile est vide
int pileVide(Pile p) {
    return (p.n == 0);
}

// Access au sommet de la pile
Info sommet(Pile p) {
    if (!pileVide(p)) return p.tab[p.n - 1];
}

// Empiler un element sur une pile
Pile empiler(Pile p, Info e) {
    if (p.n < 100) {
        p.tab[p.n] = e;
        p.n += 1;
    }

    return p;
}

// Depiler un element d'une pile
Info depile(Pile p) {
    Info e;

    if (!pileVide(p)) {
        e = sommet(p);
        p.n -= 1;
    }

    return e;
}
