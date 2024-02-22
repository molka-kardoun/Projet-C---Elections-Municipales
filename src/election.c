#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "election.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	ID,
	HABITANTS,
	MUNICIPALITE,
	DATE,
	CONSEILLERS,
	COLUMNS
};


void ajouter_election(election u, char *fname){
GtkWidget *pQuestion;
FILE *f;
int b=0;
gpointer user_data;
election e;
f=fopen(fname,"a+");
if(f!=NULL)
{	
	while(fscanf(f,"%d %d %s %d %d %d %d\n",&(e.id),&(e.habitants),e.municipalite,&(e.conseillers),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
	{	
		if(u.id==e.id)
		b=1;
	}
	if(b==0){
	fprintf(f,"%d %d %s %d %d %d %d\n",u.id,u.habitants,u.municipalite,u.conseillers,u.d.j,u.d.m,u.d.a);
	}
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,b==0?GTK_MESSAGE_INFO:GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,b==0?"Election ajoutée avec succès !":"Election déja existante !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	fclose(f);
}
}

void modifier_election(election u, char *fname){
election e;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%d %d %s %d %d %d %d\n",&(e.id),&(e.habitants),e.municipalite,&(e.conseillers),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
	{
		if(e.id!=u.id)
			fprintf(g,"%d %d %s %d %d %d %d\n",e.id,e.habitants,e.municipalite,e.conseillers,e.d.j,e.d.m,e.d.a);
		else
			fprintf(g,"%d %d %s %d %d %d %d\n",e.id,u.habitants,u.municipalite,u.conseillers,u.d.j,u.d.m,u.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Election modifiée avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void afficher_election(GtkWidget *liste, char *fname, char *id, char *municipalite, char *date)
{
election e;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date_election[50], habitants[20];
FILE *f;

store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Habitants", renderer,"text",HABITANTS, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Municipalite", renderer,"text",MUNICIPALITE, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_resizable(column,TRUE);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Date", renderer,"text",DATE, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Conseillers", renderer,"text",CONSEILLERS, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);



store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
if (strcmp(id,"")==0&&strcmp(municipalite,"")==0&&strcmp(date,"")==0){
f=fopen(fname,"a+");
if(f!=NULL)
{
		while(fscanf(f,"%d %d %s %d %d %d %d\n",&(e.id),&(e.habitants),e.municipalite,&(e.conseillers),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
	{
sprintf(date_election,"%d/%d/%d",e.d.j,e.d.m,e.d.a);
sprintf(habitants,e.habitants==0?"-5000":e.habitants==1?"5001 - 10000":e.habitants==2?"10001 - 25000":e.habitants==3?"25001 - 50000":e.habitants==4?"50001 - 100000":e.habitants==5?"100001 - 500000":"500000+");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,e.id,HABITANTS,habitants,MUNICIPALITE,e.municipalite,DATE,date_election,CONSEILLERS,e.conseillers,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
else{
f = fopen(fname,"a+");
if(f!=NULL){
		while(fscanf(f,"%d %d %s %d %d %d %d\n",&(e.id),&(e.habitants),e.municipalite,&(e.conseillers),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
	{
sprintf(date_election,"%d/%d/%d",e.d.j,e.d.m,e.d.a);
if(e.id==atoi(id)||strcmp(e.municipalite,municipalite)==0||strcmp(date_election,date)==0){
sprintf(habitants,e.habitants==0?"-5000":e.habitants==1?"5001 - 10000":e.habitants==2?"10001 - 25000":e.habitants==3?"25001 - 50000":e.habitants==4?"50001 - 100000":e.habitants==5?"100001 - 500000":"500000+");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,e.id,HABITANTS,habitants,MUNICIPALITE,e.municipalite,DATE,date_election,CONSEILLERS,e.conseillers,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_reorderable(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_search_column(GTK_TREE_VIEW(liste),0);
gtk_tree_view_set_enable_tree_lines(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(liste),GTK_TREE_VIEW_GRID_LINES_BOTH);
}

void supprimer_election(int id, char *fname)
{
election e;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%d %d %s %d %d %d %d\n",&(e.id),&(e.habitants),e.municipalite,&(e.conseillers),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
	{
		if(e.id!=id)
			fprintf(g,"%d %d %s %d %d %d %d\n",e.id,e.habitants,e.municipalite,e.conseillers,e.d.j,e.d.m,e.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Election supprimée avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

election chercher_election(int id, char *fname){
FILE *f;
election u, e={id:-1};
f=fopen(fname,"r");
if(f!=NULL)
{
	while(fscanf(f,"%d %d %s %d %d %d %d\n",&(u.id),&(u.habitants),u.municipalite,&(u.conseillers),&(u.d.j),&(u.d.m),&(u.d.a))!=EOF)
	{
	if(u.id==id)
            return u;
	}
	fclose(f);
}
    return e;

}

char* taux_obs(char *fname){
FILE *f=fopen(fname,"r");
obs o;
int c=0, n=0;
if(f!=NULL){ 
while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(o.id),o.nom,o.prenom,o.nat,&(o.sexe),&(o.d.j),&(o.d.m),&(o.d.a),o.app)!=EOF)
   {
	c++;
   if(strcmp(o.nat,"Tunisienne")==0)
     n++;
  }
fclose(f);
}
float x = (float)n/c, y = (float)(c-n)/c;
char *ch = malloc(500);
sprintf(ch, "Tunisiens : %.2f\nEtrangers : %.2f", x*100, y*100);
return ch; 
} 

char* nb_obs(char *fname){
FILE *f=fopen(fname,"r");
obs o;
int c=0;
if(f!=NULL){ 
while(fscanf(f,"%d %s %s %s %d %d %d %d %s\n",&(o.id),o.nom,o.prenom,o.nat,&(o.sexe),&(o.d.j),&(o.d.m),&(o.d.a),o.app)!=EOF)
   {
	c++;
  }
fclose(f);
}
char *ch = malloc(500);
sprintf(ch, "Nombre total d'observateurs : %d", c);
return ch; 
} 
