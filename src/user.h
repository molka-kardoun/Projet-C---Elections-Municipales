#ifndef Utilisateur__H_INCLUDED
#define Utilisateur_H_INCLUDED
#include<gtk/gtk.h>


typedef struct {
    char nom [30];
    char prenom [30];
    int jour;
    int mois;
    int annee;
    char sexe[10];
    char cin[20];
    char natio[30];
    char role[30];
    char appart[30];
    char idbv[30];
    char loginu [30];
    char passe [30];
    char vote [10];
}UTILISATEUR;


void ajouter_user(UTILISATEUR U);
int modifier_user(char mcin [50], UTILISATEUR nou, char *users);
int supprimer_user(char mcin[50], char * users);
UTILISATEUR chercher_user(char mcin [], char *users);
void afficher_user(GtkWidget *liste);
float TPE(char *users);
void TPHF(char *users,  float *nf, float *nh,float *nbv);
int chercher_user1(char mcin[], char *users);


#endif// Utilisateur_H_INCLUDED



