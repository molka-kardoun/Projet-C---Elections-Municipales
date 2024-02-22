#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <gtk/gtk.h>

typedef struct
{
char idb[50];
char ida[50];
char salle[50];
int capacite;
int nbo;
int dispo;
} bureauv;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char nom [30];
    char prenom [30];
    Date dateu;
    char cin [10];
    char sexe[20];
    char role [30];
    char appart [30];
    char natio [30];
    int num;
    char loginu [30];
    char passe [30];
    char idbv[50];
}information;

int al_ajouter(bureauv bv , char filename []);
int al_modifier(char id[], bureauv nouv, char * filename);
int al_supprimer(char id[], char * filename);
bureauv al_chercher(char id[], char * filename);

int nbe(char*filename , char* id);
float agemoyen(char*fichierusers);

void Capacite (int c, int *cap); 
int dispon (int choix);

void al_afficher(GtkWidget *liste);
int chercher2(char id[], char * filename);
char chercher3(char id[], char * filename);
void afficher2(GtkWidget *liste);

#endif
