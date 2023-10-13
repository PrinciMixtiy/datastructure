# include "listT.h"

extern Liste initListeVide(void);
extern int listeVide(Liste l);
extern Liste queue(Liste l);
extern Liste constructeur(Cellule *c, Liste l);
extern Liste supprimeTete(Liste l, void(*lc) (Cellule *c));
extern int longueurListe(Liste l);
extern Liste ajoutQueue(Cellule *c, Liste l);
extern Liste supprimeQueue(Liste l, void(*lc) (Cellule *));
extern Liste ajoutPosition(Liste l, Cellule *c, int n);
extern Liste supprimePosition(Liste l, int n, void(*lc) (Cellule *c));
extern Liste ajoutTri(Liste l, Cellule *c, int(*oc) (Cellule *, Cellule *));
