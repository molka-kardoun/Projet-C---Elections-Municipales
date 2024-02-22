
#include "bureauv.h"
#include "user.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <gtk/gtk.h>


enum
{
eidb,
eida,
esalle,
ecapacite,
enbo,
edispo,
COLUMNS
};

int al_ajouter(bureauv bv , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %i %i %i\n",bv.idb,bv.ida,bv.salle,bv.capacite,bv.nbo,bv.dispo);
        fclose(f);
        return 1;
    }
    else return 0;
}

int al_modifier(char id[], bureauv nouv, char * filename)
{
bureauv bv;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %i %i %i\n",bv.idb,bv.ida,bv.salle,&bv.capacite,&bv.nbo,&bv.dispo) !=EOF)
{
if(strcmp(bv.idb,id)!=0)
        fprintf(f2,"%s %s %s %i %i %i\n",bv.idb,bv.ida,bv.salle,bv.capacite,bv.nbo,bv.dispo);
else

  fprintf(f2,"%s %s %s %i %i %i\n",nouv.idb,nouv.ida,nouv.salle,nouv.capacite,nouv.nbo,nouv.dispo);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
  
}

int al_supprimer(char id[], char * filename)
{
bureauv bv;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %i %i %i\n",bv.idb,bv.ida,bv.salle,&bv.capacite,&bv.nbo,&bv.dispo)!=EOF)
{
if(strcmp(bv.idb,id)!=0)
        fprintf(f2,"%s %s %s %i %i %i\n",bv.idb,bv.ida,bv.salle,bv.capacite,bv.nbo,bv.dispo);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

bureauv al_chercher(char id[], char * filename)
{
bureauv bv;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %i %i %i\n",bv.idb,bv.ida,bv.salle,&bv.capacite,&bv.nbo,&bv.dispo)!=EOF)
{
if(strcmp(id,bv.idb)==0)
return bv;
}
}
}


int nbe(char*fichierusers ,char* id)
{
UTILISATEUR U;
information inf ; 
int tr=0;
char c[20] = "-1" ;
int x ,y ;
int z=0;

    FILE * f=fopen(fichierusers, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %d %s %s %s", inf.nom,inf.prenom,&inf.dateu.jour,&inf.dateu.mois, &inf.dateu.annee,inf.cin, inf.sexe,inf.natio,inf.role,inf.appart,&inf.num,inf.loginu,inf.passe,inf.idbv)!=EOF && tr==0)
{
x=strcmp(inf.idbv,id);
y=strcmp(inf.role,"electeur");

if(x==0) 
{
 if(y==0)
z++;
 }

 }
tr=1;

}
if(tr==0)

z=-1;

return z;

}

float agemoyen(char*fichierusers)
{
UTILISATEUR U; 

int age=0;
int nbe=0;
int aget=0;
float agem=0;
information inf ; 
int tr=0;

    FILE * f=fopen(fichierusers, "r");
 if(f!=NULL )
  {

while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s %d %s %s %s", inf.nom,inf.prenom,&inf.dateu.jour,&inf.dateu.mois, &inf.dateu.annee,inf.cin, inf.sexe,inf.natio,inf.role,inf.appart,&inf.num,inf.loginu,inf.passe,inf.idbv)!=EOF && tr==0)
 {
 
  if (strcmp(inf.role,"electeur")==0)
   {
   
    age = 2022-inf.dateu.annee;
    aget = aget+age;
    nbe++;
   }
  }
agem=(float)aget/nbe;
//agem=18;
tr=1;
 }

if(tr==0)

agem=-1;

return agem ;

}


void Capacite (int c, int *cap)
{
//char a[50]="100";
//char b[50]="200";
//char d[50]="300";

	if(c==1)
	(*cap)=100;  

	else if (c==2)
	(*cap)=200; 

	else if(c==3)
        (*cap)=300;
}

int dispon (int choix)
{

int dis;

if (choix==1)
dis=1;
else 
dis=-1;

return dis;
}


void al_afficher(GtkWidget *liste)
{

	GtkCellRenderer *r;
	GtkTreeViewColumn *c;
	GtkTreeIter i;
	GtkListStore *store;

	char idb[50];
	char ida[50];
	char salle[50];
	int capacite;
	int nbo;
	int dispo;

	//char ccapacite[50];
	//char cnbo[50];
	//char cdispo[50];
	
	//sprintf(ccapacite, "%d" , capacite);
	//sprintf(cnbo,"%d", nbo);
	//sprintf(cdispo, "%d" , dispo);

	store=NULL;
        FILE *f;
	
	
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("idb",r,"text", eidb,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("ida",r,"text", eida,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("salle",r,"text", esalle,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("capacite",r,"text", ecapacite,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("nbo",r,"text", enbo,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("dispo",r,"text", edispo,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);	
}
		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
		f = fopen("/home/amine/Projects/projecttstf/src/bv.txt","r");
		
		if(f==NULL)
		{
		return;
		}

			else 
			{
			f=fopen("/home/amine/Projects/projecttstf/src/bv.txt","a+");
			while(fscanf(f,"%s %s %s %i %i %i\n",idb,ida,salle,&capacite,&nbo,&dispo) !=EOF)
				{
				gtk_list_store_append (store, &i);
				gtk_list_store_set (store, &i, eidb, idb, eida, ida, esalle, salle ,ecapacite ,capacite ,
enbo ,nbo ,edispo ,dispo, -1);
				}
			fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);

			}

	}


int chercher2(char id[], char * filename)
{
bureauv bv;
int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %i %i %i\n",bv.idb,bv.ida,bv.salle,&bv.capacite,&bv.nbo,&bv.dispo)!=EOF && tr==0)
{
if(strcmp(id,bv.idb)==0)
tr=1;

}
}

return tr;

}

char chercher3(char id[], char * filename)
{
bureauv bv;
char ss[50];
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %i %i %i\n",bv.idb,bv.ida,bv.salle,&bv.capacite,&bv.nbo,&bv.dispo)!=EOF)
{
if(strcmp(id,bv.ida)==0)
{
strcmp(ss,"kk");
return ss;}
}
}
}

void afficher2(GtkWidget *liste)
{

	GtkCellRenderer *r;
	GtkTreeViewColumn *c;
	GtkTreeIter i;
	GtkListStore *store;

	char idb[50];
	char ida[50];
	char salle[50];
	int capacite;
	int nbo;
	int dispo;

	store=NULL;
        FILE *f;
	
	
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("idb",r,"text", eidb,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("ida",r,"text", eida,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("salle",r,"text", esalle,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("capacite",r,"text", ecapacite,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("nbo",r,"text", enbo,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);

		r=gtk_cell_renderer_text_new();	
		c = gtk_tree_view_column_new_with_attributes("dispo",r,"text", edispo,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), c);	
}
		
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
		f = fopen("/home/amine/Projects/projecttstf/src/bv2.txt","r");
		
		if(f==NULL)
		{
		return;
		}

			else 
			{
			f=fopen("/home/amine/Projects/projecttstf/src/bv2.txt","a+");
			while(fscanf(f,"%s %s %s %i %i %i\n",idb,ida,salle,&capacite,&nbo,&dispo) !=EOF)
				{
				gtk_list_store_append (store, &i);
				gtk_list_store_set (store, &i, eidb, idb, eida, ida, esalle, salle ,ecapacite ,capacite ,
enbo ,nbo ,edispo ,dispo, -1);
				}
			fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);

			}

	}


