#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "user.h"
#include<stdio.h>
#include<string.h>
#include<gtk/gtk.h>
#include<stdlib.h>

UTILISATEUR U;
enum
{
	ENOM,
	EPRENOM,
	EJOUR,
	EMOIS,
	EANNEE,
	ESEXE,
	ECIN,
	ENATIONALITE,
	EROLE,
	EAPPARTENANCE,
	EIDBV,
	ELOGINU,
	EPASSE,
	EVOTE,
	COLUMNS
};

void ajouter_user(UTILISATEUR U)
{
    FILE * f=fopen("users.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",U.nom,U.prenom,U.jour,U.mois,U.annee,U.sexe,U.cin,U.natio,U.role,U.appart,U.idbv,U.loginu,U.passe,U.vote);
        fclose(f);
       
    }
    
}



void afficher_user(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
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

    
	    store =NULL;

	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "NOM", renderer, "text", ENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "PRENOM", renderer, "text", EPRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "JOUR_NAI", renderer, "text", EJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "MOIS_NAI", renderer, "text", EMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "ANNEE_NAIS", renderer, "text", EANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "SEXE", renderer, "text", ESEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "CIN", renderer, "text", ECIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "NATIONALITE", renderer, "text", ENATIONALITE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "ROLE", renderer, "text", EROLE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "APPAR_POLITIQUE", renderer, "text", EAPPARTENANCE ,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "ID_BUR_VOTE", renderer, "text", EIDBV ,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "LOGIN", renderer, "text", ELOGINU,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "MOT_PASSE", renderer, "text", EPASSE ,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes( "VOTE", renderer, "text", EVOTE ,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


									   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	

	f=fopen("users.txt","r");

	if(f==NULL)
	{
			return;
	}
	else
	
	{
	f=fopen("users.txt","r");
		while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",nom,prenom,&jour,&mois,&annee,sexe,cin,natio,role,appart,idbv,loginu,passe,vote)!=EOF)
			{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store, &iter, ENOM,nom,EPRENOM,prenom,EJOUR,jour,EMOIS,mois,EANNEE,annee,ESEXE,sexe,ECIN,cin,ENATIONALITE,natio,EROLE,role,EAPPARTENANCE,appart,EIDBV,idbv,ELOGINU,loginu,EPASSE,passe,EVOTE,vote, -1);
			}
				fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
	}

}




int modifier_user(char mcin[], UTILISATEUR nou, char * users)
{
UTILISATEUR U;
    FILE * f=fopen(users, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",U.nom,U.prenom,&U.jour,&U.mois,&U.annee,U.sexe,U.cin,U.natio,U.role,U.appart,U.idbv,U.loginu,U.passe,U.vote) !=EOF)
{
if(strcmp(U.cin,mcin)!=0)
        fprintf(f2,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",U.nom,U.prenom,U.jour,U.mois,U.annee,U.sexe,U.cin,U.natio,U.role,U.appart,U.idbv,U.loginu,U.passe,U.vote);
else

  fprintf(f2,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",nou.nom,nou.prenom,nou.jour,nou.mois,nou.annee,nou.sexe,nou.cin,nou.natio,nou.role,nou.appart,nou.idbv,nou.loginu,nou.passe,nou.vote);

}
        fclose(f);
        fclose(f2);
remove(users);
rename("aux.txt", users);
        return 1;
    }
  

}
int supprimer_user(char mcin[], char * users)
{
UTILISATEUR U ;


    FILE * f=fopen(users, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",U.nom,U.prenom,&U.jour,&U.mois,&U.annee,U.sexe,U.cin,U.natio,U.role,U.appart,U.idbv,U.loginu,U.passe,U.vote)!=EOF)
{

if(strcmp(U.cin,mcin)!=0)
        fprintf(f2,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",U.nom,U.prenom,U.jour,U.mois,U.annee,U.sexe,U.cin,U.natio,U.role,U.appart,U.idbv,U.loginu,U.passe,U.vote);

}
        fclose(f);
        fclose(f2);
remove(users);
rename("aux.txt", users);
        return 1;
    }
}
UTILISATEUR chercher_user(char mcin[], char *users)
{
UTILISATEUR U ; 




    FILE * f=fopen(users, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",U.nom,U.prenom,&U.jour,&U.mois,&U.annee,U.sexe,U.cin,U.natio,U.role,U.appart,U.idbv,U.loginu,U.passe,U.vote)!=EOF)
{

if(strcmp(U.cin,mcin)==0)
//tr=1;
return U;
//tr=1;
}
}
//if(tr==0)
    //strcpy(U.cin,"-1");
//return U;
}

int chercher_user1(char mcin[], char *users)
{
UTILISATEUR U ; 
int tr=0;



    FILE * f=fopen(users, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s \n",U.nom,U.prenom,&U.jour,&U.mois,&U.annee,U.sexe,U.cin,U.natio,U.role,U.appart,U.idbv,U.loginu,U.passe,U.vote)!=EOF)
{

if(strcmp(U.cin,mcin)==0)
tr=1;

}
}
if(tr==0)
   strcpy(U.cin,"-1");
return tr;
}


float TPE(char *users)
{
	float nbv=0;
	float nbt=0;
	float T;
	UTILISATEUR U;

FILE * f=fopen(users, "r");
  
if(f!=NULL)
	{
	while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s\n",U.nom,U.prenom, &U.jour, &U.mois, &U.annee, U.sexe, U.cin,U.natio, U.role,U.appart,U.idbv,U.loginu,U.passe,U.vote)!=EOF)
	{
	if(strcmp(U.role,"ELECTEUR")==0)
	
	nbt++;

	if (strcmp(U.vote,"-1")!=0)
	nbv++;
}
	
	T=(nbv/nbt)*100;

}


	return T;

}

void TPHF( char *users, float *nf, float *nh, float *nbv)
{	

	*nbv=0;
	*nf=0;
	*nh=0;
	
	UTILISATEUR U;

	FILE * f=fopen(users, "r");
   
    	if(f!=NULL)
	
   	 {
	while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s %s\n", U.nom, U.prenom, &U.jour, &U.mois, &U.annee, U.sexe,U.cin, U.natio, U.role, U.appart, U.idbv, U.loginu, U.passe,U.vote)!=EOF)
{ 
	
	if (strcmp(U.vote,"-1")!=0)

	(*nbv)++;
	

	if((strcmp(U.sexe,"femme")==0)&&(strcmp(U.vote,"-1")!=0))
	(*nf)++;
 	
	if ((strcmp(U.sexe,"homme")==0)&&(strcmp(U.vote,"-1")!=0))
	(*nh)++;
	
}
}	


	






	//printf("le taux de participation des femmes est de %2.f pour cent \n", *nf/nbv*100);
	//printf("le taux de participation des hommes est de %2.f pour cent \n", *nh/nbv*100);

fclose(f);

	

}


