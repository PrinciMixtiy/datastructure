# include "infoT.h"

typedef struct {
    Info tab[100];
    int tete;
    int fin;
} File;

File initFile(void) {
    File f;

    f.tete = 0;
    f.fin = 0;

    return f;
}

int fileVide(File f) {
    return (f.tete == f.fin);
}

// Access au tete de la file
Info tete(File f) {
    Info e;

    if (!fileVide(f)) e = f.tab[f.tete];

    return e; 
}

// Placer un elelment dans une file
File entreElement(File f, Info e) {
    if (((f.fin + 1) % 100) != f.tete) {
        f.tab[f.fin] = e;
        f.fin = (f.tete + 1) % 100;
    }

    return f;
}

// Sortir un element d'une file
File sortirElement(File f) {
    Info e;

    if (!fileVide(f)) {
        e = tete(f);
        f.tete = (f.tete + 1) % 100;    
    }

    return f;
}
