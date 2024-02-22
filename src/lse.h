#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct
{
	int j;
	int m ;
	int a ;
}date ;
typedef struct
{
    char id[20];
    char nom[20];
    char orientation[30];
    char nomCT[30];
    char cinT[20];
    char nomC1[30];
    char cinC1[20];
    char nomC2[30];
    char cinC2[20];
    char nomC3[30];
    char cinC3[20];
    int nbrVote ;
    date d ;
}lse;



void ajouter(lse el);
void supprimer(char id[]);
void modifier_lse(lse el);
void afficher_lse(GtkWidget *liste,char *fname);
void afficher_lseVote(GtkWidget *liste);

int rechercher_lse(char id[]);

lse recherche_lse(char id[]);

int trierLE(GtkWidget *liste,char *fname);
