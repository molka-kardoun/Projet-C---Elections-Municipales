#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct date
{
    int j;
    int m;
    int a;
}dateelec;

typedef struct obs
  {
     int id;
     char nom[50];
     char prenom[50];
     char nat[40];
     int sexe;
     dateelec d;
     char app[50];
  }obs;

typedef struct election
{
int id;
int habitants;
char municipalite[50];
int conseillers;
dateelec d;
}election;

void ajouter_election(election u, char *fname);
void supprimer_election(int id, char *fname);
void modifier_election(election u, char *fname);
void afficher_election(GtkWidget *liste, char *fname, char *id, char *municipalite, char *date);
election chercher_election(int id, char *fname);
char* taux_obs(char *fname);
char* nb_obs(char *fname);

