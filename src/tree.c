#include "tree.h"
#include<stdio.h>
	
void afficher_Rec (GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


 

char id_obs[50];
char type_recl[50];
char Description[50];
char urgent[50];
int num_electoral;

store=NULL;

FILE *f ;


store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ID_observateur",renderer,"text",Ido,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Type de reclamation",renderer,"text",Tprec,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Description",renderer,"text",Descrec,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Urgent",renderer,"text",Uregrec,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Num_electoral",renderer,"text",numrec,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             

	     
}


	    store =gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_INT );



            f=fopen("Reclamation.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %d \n",id_obs,type_recl,Description,urgent,&num_electoral)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,Ido,id_obs,Tprec,type_recl,Descrec,Description,Uregrec,urgent,numrec,num_electoral,-1);
		}
		
		fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}
int supprimerR(char *id)
{
agents p;
    FILE * f=fopen("Reclamation.txt", "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %s %d\n",p.id_obs,p.type_recl,p.Description,p.urgent,&p.num_electoral)!=EOF)
{
if(strcmp(p.id_obs,id)!=0)
        fprintf(f2,"%s %s %s %s %d\n",p.id_obs,p.type_recl,p.Description,p.urgent,p.num_electoral);

}
        fclose(f);
        fclose(f2);
remove("Reclamation.txt");
rename("aux.txt", "Reclamation.txt");
        return 1;
    }
}

void rechercherReclamation(GtkWidget* liste,char*type)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


 

char id_obs[50];
char type_recl[50];
char Description[50];
char urgent[50];
int num_electoral;

store=NULL;

FILE *f ;


store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ID_observateur",renderer,"text",Ido,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Type de reclamation",renderer,"text",Tprec,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Description",renderer,"text",Descrec,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Urgent",renderer,"text",Uregrec,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Num_electoral",renderer,"text",numrec,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             

	     
}


	    store =gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_INT );



            f=fopen("Reclamation.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %d \n",id_obs,type_recl,Description,urgent,&num_electoral)!=EOF) {
		if(strcmp(type,id_obs)==0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,Ido,id_obs,Tprec,type_recl,Descrec,Description,Uregrec,urgent,numrec,num_electoral,-1);
		}
		}
		fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);

}
void ajouterR(agents p )
{
    FILE * f=fopen("Reclamation.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s  %d \n",p.id_obs,p.type_recl,p.Description,p.urgent,p.num_electoral);
        fclose(f);
        
    }
}
int modifier(char *id, agents nouv)
{
agents p;
    FILE * f=fopen("Reclamation.txt", "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %s %d\n",p.id_obs,p.type_recl,p.Description,p.urgent,&p.num_electoral)!=EOF)
{
if(strcmp(p.id_obs,id)!=0)
{
        fprintf(f2,"%s %s %s %s %d\n",p.id_obs,p.type_recl,p.Description,p.urgent,p.num_electoral);
}
else
{
  fprintf(f2,"%s %s %s %s %d\n",nouv.id_obs,nouv.type_recl,nouv.Description,nouv.urgent,nouv.num_electoral);
}
}
        fclose(f);
        fclose(f2);
remove("Reclamation.txt");
rename("aux.txt", "Reclamation.txt");
        return 1;
    }
  
}

