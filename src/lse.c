#include <stdlib.h>
#include <stdbool.h>
#include "lse.h"
#include "callbacks.h"
#include <gtk/gtk.h>


enum{
	EID,
	ENOM,
	EORIENTATION,
	ENOMCT,
	ECINT,
	ENOMC1,
	ECINC1,
	ENOMC2,
	ECINC2,
	ENOMC3,
	ECINC3,
	ENBVOTES,
	EDATE,
	ECOLUMNS,
};

enum{
	EIDS,
	ENOMS,
	ENBVOTESS,
	ECOLUMNSS,
};

enum{
	EIDSS,
	ENOMSS,
	ENOMCTS,
	ECINTS,
	ENBVOTESSS,
	ECOLUMNSSS,
};


/* ----------------------------------------------------------------------------------------- */


void ajouter(lse e){
	e.nbrVote = 0 ;
    FILE *f;
    f = fopen("lse.txt","a");
    if(f!= NULL){
        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,e.nbrVote,e.d.j,e.d.m,e.d.a);
    }
    fclose(f);
}

/* ----------------------------------------------------------------------------------------- */

void supprimer(char id[])
{
lse e;
FILE *f, *g;
f=fopen("lse.txt","r");
g=fopen("temp.txt","a");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
	{
		if(strcmp(e.id,id) != 0)
			fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,e.nbrVote,e.d.j,e.d.m,e.d.a);
	}
	
	fclose(f);
	fclose(g);
	
	remove("lse.txt");
	rename("temp.txt","lse.txt");
	}
}

/* ----------------------------------------------------------------------------------------- */


void modifier_lse(lse el){
    lse e;
    FILE *f;
    FILE *g;
    f = fopen("lse.txt","r");
    g = fopen("tmp.txt","a");
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
        if(strcmp(e.id,el.id) == 0){
            fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",el.id,el.nom,el.orientation,el.nomCT,el.cinT,el.nomC1,el.cinC1,el.nomC2,el.cinC2,el.nomC3,el.cinC3,el.nbrVote,el.d.j,el.d.m,el.d.a);
        }
        else{
            fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,e.nbrVote,e.d.j,e.d.m,e.d.a);
        }
    }
    fclose(f);
    fclose(g);
    remove("lse.txt");
    rename("tmp.txt","lse.txt");
}

/* ----------------------------------------------------------------------------------------- */

int rechercher_lse(char id[]){
    lse e;
    FILE *f;
    f = fopen("lse.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
        	if(strcmp(e.id,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
    

}

/* ----------------------------------------------------------------------------------------- */

lse recherche_lse(char id[]){
    lse e;
    FILE *f;
    f = fopen("lse.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
        	if(strcmp(e.id,id) == 0){
       		     return e;
        	}
    	}
}
    fclose(f);
    return;
}

/* ----------------------------------------------------------------------------------------- */

void afficher_lseVote(GtkWidget *liste){
    
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    lse e ;
    char nb[20];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EIDS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom LE",renderer,"text",ENOMS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre Vote",renderer,"text",ENBVOTESS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    }
	store = gtk_list_store_new(ECOLUMNSS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen("lse.txt","r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
			sprintf(nb,"%d",e.nbrVote);
			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EIDS,e.id,ENOMS,e.nom,ENBVOTESS,nb,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    
}
/* ----------------------------------------------------------------------------------------- */

void afficher_lse(GtkWidget *liste,char *fname){
    
  GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    lse e ;
    char nb[20];
	char dateFormat[100];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom LE",renderer,"text",ENOM,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom C1",renderer,"text",ENOMCT,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin",renderer,"text",ECINT,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom C2",renderer,"text",ENOMC1,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin",renderer,"text",ECINC1,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom C3",renderer,"text",ENOMC2,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin",renderer,"text",ECINC2,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom C4",renderer,"text",ENOMC3,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin",renderer,"text",ECINC3,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre Vote",renderer,"text",ENBVOTES,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date",renderer,"text",EDATE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
			sprintf(nb,"%d",e.nbrVote);
			sprintf(dateFormat,"%d/%d/%d",e.d.j,e.d.m,e.d.a);
			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,e.id,ENOM,e.nom,ENOMCT,e.nomCT,ECINT,e.cinT,ENOMC1,e.nomC1,ECINC1,e.cinC1,ENOMC2,e.nomC2,ECINC2,e.cinC2,ENOMC3,e.nomC3,ECINC3,e.cinC3,ENBVOTES,nb,EDATE,dateFormat	,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    
}

/* ----------------------------------------------------------------------------------------- */

int trierLE(GtkWidget *liste,char *fname){
	lse e;
	lse data[1000];
    	FILE *f;

	int count = 0; 
   	f = fopen("lse.txt","r");

    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.nomC1,e.cinC1,e.nomC2,e.cinC2,e.nomC3,e.cinC3,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
     
	    data[count] = e ;
		count++ ; 
	
    }
    fclose(f);

	int i,j;
	lse c;
	for(i=0;i<count-1;i++){
	    for(j=i+1;j<count;j++){
		if ( data[i].nbrVote > data[j].nbrVote ) {
		    c = data[i];
		    data[i] = data[j];
		    data[j] = c;
			}
		}
	}
	 
	


	
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
 
    char nb[20];
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EIDSS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom LE",renderer,"text",ENOMSS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom Tete list",renderer,"text",ENOMCTS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin",renderer,"text",ECINTS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre Vote",renderer,"text",ENBVOTESSS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




    }
	store = gtk_list_store_new(ECOLUMNSS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    	int k = 0;
	
	while(k < count){	
		sprintf(nb,"%d",data[k].nbrVote);
		          		
		gtk_list_store_append(store,&iter);
    		gtk_list_store_set(store,&iter,EIDSS,data[k].id,ENOMSS,data[k].nom,ENOMCTS,data[k].nomCT,ECINTS,data[k].cinT,ENBVOTESSS,nb,-1);
		k++;

	}

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
        	
    	

	

	

}

/* ----------------------------------------------------------------------------------------- */




