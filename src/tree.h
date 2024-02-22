#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>



enum
{ Ido,
Tprec,
Descrec,
Uregrec,
numrec,
COLUMNS
};

typedef struct agents 
{
char id_obs[50];
char type_recl[50];
char Description[50];
char urgent[50];
int num_electoral;

} agents ;
void afficher_Rec (GtkWidget *liste);
int supprimerR(char *id);
void rechercherReclamation(GtkWidget* treeview1,char*type);
void ajouterR(agents p );
int modifier(char *id, agents nouv);
