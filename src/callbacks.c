#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "lse.h"
#include "user.h"
#include "bureauv.h"
#include "tree.h"
#include "election.h"
#include "login.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
UTILISATEUR nou ;
float unbv;
int uaze=1;
//int uc[]={0,0,0};
int use=0;
UTILISATEUR U ;
char mcin[50];
int un,ur;
int choix2[] = {0,0,0};
int choix4[] = {0}; 
int choix1[] = {0,0,0};
int choix3[] = {0};

int x = 1 ;
int y = 1 ; 

int check = 0 ; 

int choix=-1;
int c=1;
char idm[50];


/* ---------------------------- INTERFACE MENU ------------------------------- */

void
on_toAffLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_afficher_liste_electorale ();
  	gtk_widget_show (window1);

}


void
on_toAddLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_ajout_liste ();
  	gtk_widget_show (window1);

}


void
on_toModLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_modifier_liste ();
  	gtk_widget_show (window1);

}

void
on_toSupprimerListe_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_supprimer_liste();
  	gtk_widget_show (window1);

}

void
on_toVote_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_vote();
  	gtk_widget_show (window1);

}


void
on_toStats_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	window1 = create_stats ();
  	gtk_widget_show (window1);

}

/* ---------------------------- INTERFACE AJOUT ------------------------------- */
void
on_radiobuttonAG_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=1;
	}
}


void
on_radiobuttonAC_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=2;
	}
}


void
on_radiobuttonAD_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=3;
	}
}



void
on_ajouterLE_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *nomLE, *idLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 , *output,*j,*m,*a  ;
	
	lse e;
	char message[200];
	
	
	
	
	idLE=lookup_widget(objet,"idLE");
	nomLE=lookup_widget(objet,"nomLE");

	nomCT=lookup_widget(objet,"nomCT");
	cinCT=lookup_widget(objet,"cinT");

	nomC1=lookup_widget(objet,"nomC1");
	cinC1=lookup_widget(objet,"cinC1");

	nomC2=lookup_widget(objet,"nomC2");
	cinC2=lookup_widget(objet,"cinC2");

	nomC3=lookup_widget(objet,"nomC3");
	cinC3=lookup_widget(objet,"cinC3");

	j = lookup_widget(objet,"spinJA");
	m = lookup_widget(objet,"spinMA");
	a = lookup_widget(objet,"spinAA");

	output = lookup_widget(objet,"outputLE");



	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomLE)));

	strcpy(e.nomCT,gtk_entry_get_text(GTK_ENTRY(nomCT)));
	strcpy(e.cinT,gtk_entry_get_text(GTK_ENTRY(cinCT)));

	strcpy(e.nomC1,gtk_entry_get_text(GTK_ENTRY(nomC1)));
	strcpy(e.cinC1,gtk_entry_get_text(GTK_ENTRY(cinC1)));

	strcpy(e.nomC2,gtk_entry_get_text(GTK_ENTRY(nomC2)));
	strcpy(e.cinC2,gtk_entry_get_text(GTK_ENTRY(cinC2)));

	strcpy(e.nomC3,gtk_entry_get_text(GTK_ENTRY(nomC3)));
	strcpy(e.cinC3,gtk_entry_get_text(GTK_ENTRY(cinC3)));



	if(x==1){
		strcpy(e.orientation,"gauche");	
	}
	else if(x == 2){
		strcpy(e.orientation,"center");
	}
	else{
		strcpy(e.orientation,"droite");
	}

	

	e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
	e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
	e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

	e.nbrVote = 0 ; 
	if(rechercher_lse(e.id)){
		sprintf(message,"Verifier vos informations \n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		ajouter(e);		
		sprintf(message,"Votre ajout a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
	}

	
}

/* ---------------------------- INTERFACE Modifier ------------------------------- */

void
on_consulterLE_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
	GtkWidget *nomLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 ;
	GtkWidget *j , *m , *a ;
	
	GtkWidget *idLE , *output;
	char message[200];
	char id[20];

	idLE = lookup_widget(objet,"idLEE");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	output = lookup_widget(objet,"outputLEE");	
	

	if(!rechercher_lse(id)){
		sprintf(message,"ID NON EXISTANT\n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		lse e;

		strcpy(e.id,id);		
		strcpy(e.nom,recherche_lse(id).nom);
		strcpy(e.orientation,recherche_lse(id).orientation);

		strcpy(e.nomCT,recherche_lse(id).nomCT);
		strcpy(e.cinT,recherche_lse(id).cinT);

		strcpy(e.nomC1,recherche_lse(id).nomC1);
		strcpy(e.cinC1,recherche_lse(id).cinC1);

		strcpy(e.nomC2,recherche_lse(id).nomC2);
		strcpy(e.cinC2,recherche_lse(id).cinC2);

		strcpy(e.nomC3,recherche_lse(id).nomC3);
		strcpy(e.cinC3,recherche_lse(id).cinC3);

		


					
		sprintf(message,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		gtk_label_set_text(GTK_LABEL(output),message);	
		

		nomLE=lookup_widget(objet,"nomLEE");
    		gtk_entry_set_text(GTK_ENTRY(nomLE),e.nom);

		nomCT=lookup_widget(objet,"nomCTE");
		gtk_entry_set_text(GTK_ENTRY(nomCT),e.nomCT);

		cinCT=lookup_widget(objet,"cinTE");
		gtk_entry_set_text(GTK_ENTRY(cinCT),e.cinT);

		nomC1=lookup_widget(objet,"nomCE1");
		gtk_entry_set_text(GTK_ENTRY(nomC1),e.nomC1);

		cinC1=lookup_widget(objet,"cinCE1");
		gtk_entry_set_text(GTK_ENTRY(cinC1),e.cinC1);

		nomC2=lookup_widget(objet,"nomCE2");
		gtk_entry_set_text(GTK_ENTRY(nomC2),e.nomC2);

		cinC2=lookup_widget(objet,"cinCE2");
		gtk_entry_set_text(GTK_ENTRY(cinC2),e.cinC2);


		nomC3=lookup_widget(objet,"nomCE3");
		gtk_entry_set_text(GTK_ENTRY(nomC3),e.nomC3);

		cinC3=lookup_widget(objet,"cinCE3");
		gtk_entry_set_text(GTK_ENTRY(cinC3),e.cinC3);

		j = lookup_widget(objet,"spinJM");
		gtk_spin_button_set_value(j,recherche_lse(id).d.j);


		m = lookup_widget(objet,"spinMM");
		gtk_spin_button_set_value(m,recherche_lse(id).d.m);

		a = lookup_widget(objet,"spinAM");
		gtk_spin_button_set_value(a,recherche_lse(id).d.a);

		
	}
}





void
on_radiobuttonGE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		y=1;
	}
}


void
on_radiobuttonCE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		y=2;
	}
}


void
on_radiobuttonDE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		y=3;
	}
}


void
on_saveChangesLE_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *nomLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 ;
	GtkWidget *idLE , *output;
	char message[200];
	char id[20];
	lse e;

	idLE = lookup_widget(objet,"idLEE");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	output = lookup_widget(objet,"outputLEE");

	if(check == 0 ){
		sprintf(message,"SVP confirmer votre choix ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		if(rechercher_lse(id)){
		nomLE=lookup_widget(objet,"nomLEE");
		nomCT=lookup_widget(objet,"nomCTE");
		cinCT=lookup_widget(objet,"cinTE");

		nomC1=lookup_widget(objet,"nomCE1");
		cinC1=lookup_widget(objet,"cinCE1");

		nomC2=lookup_widget(objet,"nomCE2");
		cinC2=lookup_widget(objet,"cinCE2");

		nomC3=lookup_widget(objet,"nomCE3");
		cinC3=lookup_widget(objet,"cinCE3");

		strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idLE)));
		strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomLE)));

		strcpy(e.nomCT,gtk_entry_get_text(GTK_ENTRY(nomCT)));
		strcpy(e.cinT,gtk_entry_get_text(GTK_ENTRY(cinCT)));

		strcpy(e.nomC1,gtk_entry_get_text(GTK_ENTRY(nomC1)));
		strcpy(e.cinC1,gtk_entry_get_text(GTK_ENTRY(cinC1)));

		strcpy(e.nomC2,gtk_entry_get_text(GTK_ENTRY(nomC2)));
		strcpy(e.cinC2,gtk_entry_get_text(GTK_ENTRY(cinC2)));

		strcpy(e.nomC3,gtk_entry_get_text(GTK_ENTRY(nomC3)));
		strcpy(e.cinC3,gtk_entry_get_text(GTK_ENTRY(cinC3)));



		if(y==1){
			strcpy(e.orientation,"gauche");	
		}
		else if(y == 2){
			strcpy(e.orientation,"center");
		}
		else{
			strcpy(e.orientation,"droite");
		}


		GtkWidget *j,*m,*a; 
		j = lookup_widget(objet,"spinJM");
		m = lookup_widget(objet,"spinMM");
		a = lookup_widget(objet,"spinAM");
	

		e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
		e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
		e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

		e.nbrVote = recherche_lse(id).nbrVote ; 

		sprintf(message,"Votre modification a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		modifier_lse(e);
		
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}

	}
	
}

/* ---------------------------- INTERFACE Affichage LE ------------------------------- */

void
on_afficherLE_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewLE");
		
	afficher_lse(treeview,"lse.txt");
}


/* -------------------------- INTERFACE Suppression -------------------------- */

void
on_supListe_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *idLE , *output;
	char message[200];
	char id[20];

	idLE = lookup_widget(objet,"idSupp");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));


	output = lookup_widget(objet,"outputSupp");

	if(rechercher_lse(id)){
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
	gtk_label_set_text(GTK_LABEL(output),message);
		
	supprimer(id);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}
}


/* ---------------------------- INTERFACE Vote ------------------------------- */



void
on_voter_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *idLE , *output ; 
	char id[30];
	char message[100] ;  

	idLE = lookup_widget(objet,"idVote");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	
	output = lookup_widget(objet,"outputVote");

	if(rechercher_lse(id)){
		lse e;

		strcpy(e.id,id);		
		strcpy(e.nom,recherche_lse(id).nom);
		strcpy(e.orientation,recherche_lse(id).orientation);

		strcpy(e.nomCT,recherche_lse(id).nomCT);
		strcpy(e.cinT,recherche_lse(id).cinT);

		strcpy(e.nomC1,recherche_lse(id).nomC1);
		strcpy(e.cinC1,recherche_lse(id).cinC1);

		strcpy(e.nomC2,recherche_lse(id).nomC2);
		strcpy(e.cinC2,recherche_lse(id).cinC2);

		strcpy(e.nomC3,recherche_lse(id).nomC3);
		strcpy(e.cinC3,recherche_lse(id).cinC3);

		e.nbrVote = recherche_lse(id).nbrVote + 1 ; 
		modifier_lse(e);
		sprintf(message,"Vote ajouté avec succés  ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
}


void
on_refreshTreeView_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewVote");
		
	afficher_lse(treeview,"lse.txt");
}


void
on_refreshStat1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewStat1");
		
	afficher_lseVote(treeview);
}


void
on_refreshStat2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewStat2");
		trierLE(treeview,"lse.txt");
	/*int x = trierLE(treeview,"election.txt");
	GtkWidget *label ; 
	label = lookup_widget(objet,"label");
	char message[20];
	sprintf(message,"%d",x);
	gtk_label_set_text(GTK_LABEL(label),message);*/
}




void
on_checkModif_activate                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active (togglebutton)){
		check = 1 ;
	}
	else{
		check = 0 ;
	}
}


void
on_button_ge_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *mod;
  GtkWidget *af;
  GtkWidget *aj;
  GtkWidget *treeview;
//GtkWidget *window_espa;
af = create_af ();
  gtk_widget_show (af);
  treeview=lookup_widget(af,"treeview");
  afficher_election(treeview,"election.txt", "", "", "");
//window_espa=lookup_widget(objet_graphique,"window_espa");
//gtk_widget_hide(window_espa);

}


void
on_button_gbv_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_gbv;
GtkWidget *cls_espa;

cls_espa=lookup_widget(button,"window_espa");
gtk_widget_destroy(cls_espa);

w_gbv=lookup_widget(button,"window_gbv");
w_gbv=create_window_gbv();
gtk_widget_show(w_gbv);
}


void
on_button_user_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wst2;
GtkWidget *window_espa;
window_espa=lookup_widget(objet_graphique,"window_espa");
wst2=create_wst2();
gtk_widget_show(wst2);
gtk_widget_hide(window_espa);
}


void
on_al_brtr_espa_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_esp;
GtkWidget *cls_espa;

cls_espa=lookup_widget(button,"window_espa");
gtk_widget_destroy(cls_espa);

w_esp=lookup_widget(button,"window_esp");
w_esp=create_window_esp();
gtk_widget_show(w_esp);
}


void
on_alcls_espa_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cls_espa;

cls_espa=lookup_widget(button,"window_espa");
gtk_widget_destroy(cls_espa);
}


void
on_al_bsup_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_gbvs;
GtkWidget *cls_gbv;

cls_gbv=lookup_widget(button,"window_gbv");
gtk_widget_destroy(cls_gbv);

w_gbvs=lookup_widget(button,"window_gbvs");
w_gbvs=create_window_gbvs();
gtk_widget_show(w_gbvs);
}


void
on_al_bcls_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cls_gbv;

cls_gbv=lookup_widget(button,"window_gbv");
gtk_widget_destroy(cls_gbv);
}


void
on_al_brtr_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_espa;
GtkWidget *cls_gbv;

cls_gbv=lookup_widget(button,"window_gbv");
gtk_widget_destroy(cls_gbv);

w_espa=lookup_widget(button,"window_espa");
w_espa=create_window_espa();
gtk_widget_show(w_espa);
}


void
on_al_bact_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *w_gbv=create_window_gbv();

w_gbv=lookup_widget(button,"window_gbv");
treeview=lookup_widget(w_gbv,"altreeview");
al_afficher(treeview);
}


void
on_al_baj_gbv_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_gbva;
GtkWidget *cls_gbv;

cls_gbv=lookup_widget(button,"window_gbv");
gtk_widget_destroy(cls_gbv);

w_gbva=lookup_widget(button,"window_gbva");
w_gbva=create_window_gbva();
gtk_widget_show(w_gbva);
}


void
on_al_bmod_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_gbvm;
GtkWidget *cls_gbv;

cls_gbv=lookup_widget(button,"window_gbv");
gtk_widget_destroy(cls_gbv);

w_gbvm=lookup_widget(button,"window_gbvm");
w_gbvm=create_window_gbvm();
gtk_widget_show(w_gbvm);
}


void
on_al_br_gbv_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *combo;
GtkWidget *input;
GtkWidget *treeview;
//GtkWidget *w_gbv=create_window_gbv();

char s[50];
bureauv bv;
char cher[50];

//w_gbv=lookup_widget(button,"window_gbv");
treeview=lookup_widget(button,"altreeview");
combo=lookup_widget(button,"combo_r");
input=lookup_widget(button,"entry_r");


strcpy(s,gtk_entry_get_text(GTK_ENTRY(input)));

if (strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)),"idb")==0)
{
bv=al_chercher(s,"/home/amine/Projects/projecttstf/src/bv.txt");
al_ajouter(bv,"/home/amine/Projects/projecttstf/src/bv2.txt");
afficher2(treeview);
al_supprimer(s,"/home/amine/Projects/projecttstf/src/bv2.txt");
}
/*
else if (strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)),"ida")==0)
{
strcpy(cher,chercher3(s,"/home/amine/Projects/projecttstf/src/bv.txt"));
//strcpy(cher,"amine");
bv=chercher(cher,"/home/amine/Projects/projecttstf/src/bv.txt");
ajouter(bv,"/home/amine/Projects/projecttstf/src/bv2.txt");
afficher2(treeview);
supprimer(cher,"/home/amine/Projects/projecttstf/src/bv2.txt");
}*/
/*
else if (strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)),"salle")==0)
{
strcpy(cher,chercher3(s,"/home/amine/Projects/projecttstf/src/bv.txt"));
strcpy(cher,"amine");
bv=chercher(cher,"/home/amine/Projects/projecttstf/src/bv.txt");
ajouter(bv,"/home/amine/Projects/projecttstf/src/bv2.txt");
afficher2(treeview);
supprimer(cher,"/home/amine/Projects/projecttstf/src/bv2.txt");*/
}


void
on_rtr_espa_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_espa;
GtkWidget *cls_ls;

cls_ls=lookup_widget(button,"menu_liste_electorale");
gtk_widget_destroy(cls_ls);

w_espa=lookup_widget(button,"window_espa");
w_espa=create_window_espa();
gtk_widget_show(w_espa);
}


void
on_al_bcls_gbva_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cls_gbva;

cls_gbva=lookup_widget(button,"window_gbva");
gtk_widget_destroy(cls_gbva);
}


void
on_al_enrg_gbva_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2;
GtkWidget *w_gbv_aj;
GtkWidget *w_cls_gbv;
GtkWidget *combobox;
GtkWidget *spin;
GtkWidget *output;

bureauv bv;
char ccapacite[50];
int cap;

w_gbv_aj=lookup_widget(button,"window_gbva");
input1=lookup_widget(button,"al_idb_gbva");
input2=lookup_widget(button,"al_ida_gbva");
combobox=lookup_widget(button,"al_combobox_gbva");
spin=lookup_widget(button,"al_spin_gbva");
output=lookup_widget(button,"al_msg_gbva");

Capacite (c,&cap); 
//sprintf(ccapacite,"%d",cap);

strcpy(bv.idb,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(bv.ida,gtk_entry_get_text(GTK_ENTRY(input2)));
bv.nbo=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
bv.capacite=cap;

strcpy(bv.salle,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
//bv.capacite=100;
//bv.dispo=1;

bv.dispo=dispon (choix);

if ( chercher2(bv.idb,"/home/amine/Projects/projecttstf/src/bv.txt")==0 )
{
al_ajouter(bv,"/home/amine/Projects/projecttstf/src/bv.txt");
gtk_label_set_text(GTK_LABEL(output),"Ajout effectuée");
}
else
gtk_label_set_text(GTK_LABEL(output),"ID deja ajoutée");

}


void
on_al_banl_gbva_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_gbv;
GtkWidget *cls_gbva;

cls_gbva=lookup_widget(button,"window_gbva");
gtk_widget_destroy(cls_gbva);

w_gbv=lookup_widget(button,"window_gbv");
w_gbv=create_window_gbv();
gtk_widget_show(w_gbv);
}


void
on_al_check_gbva_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix=1;
else
choix=0;
}


void
on_al_radio100_gbva_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		c=1;
}


void
on_al_radio200_gbva_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		c=2;
}


void
on_al_radio300_gbva_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		c=3;
}


void
on_al_bcls_gbvm_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cls_gbvm;

cls_gbvm=lookup_widget(button,"window_gbvm");
gtk_widget_destroy(cls_gbvm);
}


void
on_al_bmod_gbvm_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *outputm;
GtkWidget *combobox;
GtkWidget *spin;
GtkWidget *check;
GtkWidget *radio1;
GtkWidget *radio2;
GtkWidget *radio3;
GtkWidget *input1;
GtkWidget *input2;
bureauv bv;
char s[5][10]={"Salle_1","Salle_2","Salle_3","Salle_4","Salle_5"};

int i=0;

combobox=lookup_widget(button,"al_combobox_gbvm");
input=lookup_widget(button,"al_idb_gbvm");
outputm=lookup_widget(button,"al_msg_gbvm");
spin=lookup_widget(button,"al_spin_gbvm");
check=lookup_widget(button,"al_check_gbvm");
radio1=lookup_widget(button,"al_radio100_gbvm");
radio2=lookup_widget(button,"al_radio200_gbvm");
radio3=lookup_widget(button,"al_radio300_gbvm");
input1=lookup_widget(button,"al_idb_gbvm");
input2=lookup_widget(button,"al_ida_gbvm");

/*while(r<4)
{
r++;
}*/


if (chercher2(gtk_entry_get_text(GTK_ENTRY(input)),"/home/amine/Projects/projecttstf/src/bv.txt")==1)
{
strcpy(idm,gtk_entry_get_text(GTK_ENTRY(input)));
bv=al_chercher(gtk_entry_get_text(GTK_ENTRY(input)),"/home/amine/Projects/projecttstf/src/bv.txt");
gtk_spin_button_set_value(spin,bv.nbo);
if (bv.dispo==1)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check),TRUE);
else if (bv.dispo==-1)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check),FALSE);
if (bv.capacite==100)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio1),TRUE);
else if (bv.capacite==200)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio2),TRUE);
else if (bv.capacite==300)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio3),TRUE);
gtk_entry_set_text(GTK_ENTRY(input1),bv.idb);
gtk_entry_set_text(GTK_ENTRY(input2),bv.ida);



while(i<4 && strcmp(s[i],bv.salle) !=0)
{
i++;
//strcmp(s[i],bv.salle);
}


gtk_combo_box_set_active(GTK_COMBO_BOX (combobox),i);
//gtk_label_set_text(GTK_LABEL(outputm),bv.salle);
gtk_label_set_text(GTK_LABEL(outputm),"ID entrée");
}
else 
gtk_label_set_text(GTK_LABEL(outputm),"ID non trouvée");
}



void
on_al_radio100_gbvm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		c=1;
}


void
on_al_radio200_gbvm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		c=2;
}


void
on_al_radio300_gbvm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		c=3;
}


void
on_al_check_gbvm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix=1;
else
choix=0;
}


void
on_al_benrg_gbvm_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
bureauv nouv;

GtkWidget *input1, *input2;
GtkWidget *w_gbv_aj;
GtkWidget *w_cls_gbv;
GtkWidget *combobox;
GtkWidget *spin;
GtkWidget *outputm;

bureauv bv;
int cap;

input1=lookup_widget(button,"al_idb_gbvm");
input2=lookup_widget(button,"al_ida_gbvm");
combobox=lookup_widget(button,"al_combobox_gbvm");
spin=lookup_widget(button,"al_spin_gbvm");
outputm=lookup_widget(button,"al_msg_gbvm");


strcpy(nouv.salle,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

Capacite (c,&cap); 

strcpy(nouv.idb,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nouv.ida,gtk_entry_get_text(GTK_ENTRY(input2)));
nouv.nbo=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
nouv.capacite=cap;
nouv.dispo=dispon (choix);

al_modifier(idm,nouv,"/home/amine/Projects/projecttstf/src/bv.txt");

if (chercher2(nouv.idb,"/home/amine/Projects/projecttstf/src/bv.txt")==1)
{
 if (strcmp(nouv.idb,idm)==0)
 gtk_label_set_text(GTK_LABEL(outputm),"Modification effectuée");
 else 
 gtk_label_set_text(GTK_LABEL(outputm),"Modification effectuée avec nv ID");
}
else 
 gtk_label_set_text(GTK_LABEL(outputm),"Modification echouée");
}


void
on_al_banl_gbvs_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_gbv;
GtkWidget *cls_gbvm;

cls_gbvm=lookup_widget(button,"window_gbvm");
gtk_widget_destroy(cls_gbvm);

w_gbv=lookup_widget(button,"window_gbv");
w_gbv=create_window_gbv();
gtk_widget_show(w_gbv);
}


void
on_al_bsuppr_gbvs_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *inputs;
GtkWidget *outputs;


inputs=lookup_widget(button,"al_idbs_gbvs");
outputs=lookup_widget(button,"al_msg_gbvs");


//gtk_label_set_text(GTK_LABEL(outputs),"ok");

if (chercher2(gtk_entry_get_text(GTK_ENTRY(inputs)),"/home/amine/Projects/projecttstf/src/bv.txt")==1)
{

strcpy(idm,gtk_entry_get_text(GTK_ENTRY(inputs)));
gtk_label_set_text(GTK_LABEL(outputs),"ID entrée");
}
else
gtk_label_set_text(GTK_LABEL(outputs),"ID non trouvée");
}


void
on_al_bcls_gbvs_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cls_gbvs;

cls_gbvs=lookup_widget(button,"window_gbvs");
gtk_widget_destroy(cls_gbvs);
}


void
on_al_bsup_gbvs_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
GtkWidget *inputs;
output=lookup_widget(button,"al_msg_gbvs");
inputs=lookup_widget(button,"al_idbs_gbvs");

if (strcmp(gtk_entry_get_text(GTK_ENTRY(inputs)),idm)==0)
{
al_supprimer(idm,"/home/amine/Projects/projecttstf/src/bv.txt");
gtk_label_set_text(GTK_LABEL(output),"suppression effectuée");
}
else 
gtk_label_set_text(GTK_LABEL(output),"suppression echouée");
}


void
on_al_banl_gbvm_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_gbv;
GtkWidget *cls_gbvm;

cls_gbvm=lookup_widget(button,"window_gbvm");
gtk_widget_destroy(cls_gbvm);

w_gbv=lookup_widget(button,"window_gbv");
w_gbv=create_window_gbv();
gtk_widget_show(w_gbv);
}


void
on_al_bespa_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_espa;
GtkWidget *cls_esp;

cls_esp=lookup_widget(button,"window_esp");
gtk_widget_destroy(cls_esp);

w_espa=lookup_widget(button,"window_espa");
w_espa=create_window_espa();
gtk_widget_show(w_espa);
}


void
on_al_bstat_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_stat;
GtkWidget *cls_esp;
GtkWidget *output;

/*float age;
char cage[50];
char msg[100]="l'age moyenne des participants est ";*/


cls_esp=lookup_widget(button,"window_esp");
gtk_widget_destroy(cls_esp);


w_stat=lookup_widget(button,"window_stat");
w_stat=create_window_stat();
gtk_widget_show(w_stat);

/*age = agemoyen("/home/amine/Projects/projecttstf/src/user.txt");
sprintf(cage,"%f",age);
strcat(msg,cage);

output=lookup_widget(button,"al_agem");
gtk_label_set_text(GTK_LABEL(output),"ok");*/
}


void
on_alcls_esp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cls_esp;

cls_esp=lookup_widget(button,"window_esp");
gtk_widget_destroy(cls_esp);
}


void
on_al_bagem_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
float age;
char cage[50];
char msg[100]="l'age moyenne des participants est ";

age = agemoyen("/home/amine/Projects/lse/src/user.txt");
sprintf(cage,"%f",age);
strcat(msg,cage);

output=lookup_widget(button,"al_agem");
gtk_label_set_text(GTK_LABEL(output),msg);
}


void
on_al_bnbe_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *output;
int al_x;
char cx[50];
char msg[100]="le nombre d'électeurs dans ce bureau est ";

input=lookup_widget(button,"al_id_nbe");
output=lookup_widget(button,"al_nbe");
strcpy(idm,gtk_entry_get_text(GTK_ENTRY(input)));

al_x=nbe("/home/amine/Projects/lse/src/user.txt",idm);
sprintf(cx,"%i",al_x);
strcat(msg,cx);
gtk_label_set_text(GTK_LABEL(output),msg);
}


void
on_al_brtr_stat_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *w_esp;
GtkWidget *cls_stat;

cls_stat=lookup_widget(button,"window_stat");
gtk_widget_destroy(cls_stat);

w_esp=lookup_widget(button,"window_esp");
w_esp=create_window_esp();
gtk_widget_show(w_esp);
}


void
on_alcls_stat_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cls_stat;

cls_stat=lookup_widget(button,"window_stat");
gtk_widget_destroy(cls_stat);
}


void
on_buttonRRefreche_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Reclamation_1;
GtkWidget *treeview1;
Espace_Reclamation_1=lookup_widget(objet_graphique,"Espace_Reclamation_1");
treeview1=lookup_widget(Espace_Reclamation_1,"treeview1");
afficher_Rec(treeview1);

}

void
on_buttonRReclamer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Reclamation_1;
GtkWidget *Espace_Reclamation_2;
GtkWidget *label;
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label4;

Espace_Reclamation_1=lookup_widget(objet_graphique,"Espace_Reclamation_1");
Espace_Reclamation_2 = create_Espace_Reclamation_2 ();
label=lookup_widget(Espace_Reclamation_2,"labelE");
label1=lookup_widget(Espace_Reclamation_2,"labelwrong1");
label2=lookup_widget(Espace_Reclamation_2,"labelwrong2");
label3=lookup_widget(Espace_Reclamation_2,"labelRobot1");
label4=lookup_widget(Espace_Reclamation_2,"labelobligatoire1");

gtk_widget_hide (label);
gtk_widget_hide (label1);
gtk_widget_hide (label2);
gtk_widget_hide (label3);
gtk_widget_hide (label4);
gtk_widget_show (Espace_Reclamation_2);
gtk_widget_hide(Espace_Reclamation_1);


}


void
on_buttonRReturn_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Reclamation_1;
GtkWidget *Espace_Reclamation_2;
GtkWidget *label;
GtkWidget *label1;
Espace_Reclamation_2=lookup_widget(objet_graphique,"Espace_Reclamation_2");
Espace_Reclamation_1 = create_Espace_Reclamation_1 ();

gtk_widget_show (Espace_Reclamation_1);
label=lookup_widget(Espace_Reclamation_1,"label25");
label1=lookup_widget(Espace_Reclamation_1,"label26");
gtk_widget_hide (label);
gtk_widget_hide (label1);
gtk_widget_hide(Espace_Reclamation_2);
}


void
on_buttonRSupprimer_clicked            (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
/*char id_obs[30];*/
GtkWidget *Espace_Reclamation_1;
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar*id_obs ;
	agents p1;
	Espace_Reclamation_1=lookup_widget(objet_graphique,"Espace_Reclamation_1");
        label=lookup_widget(Espace_Reclamation_1,"label25");
        p=lookup_widget(Espace_Reclamation_1,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id_obs,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView
           /*strcpy(p1.id_obs,id_obs);*/
           supprimerR(id_obs);// supprimer la ligne du fichier

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }
}


void
on_buttonRModifier_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *label;
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label4;
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
gchar*id_obs ;
gchar*type_recl ;
gchar*Description ;
gchar*urgent ;
gint num_electoral ;
int x;
GtkWidget *Espace_Reclamation_1;
GtkWidget *p;
GtkWidget *Modifier_Reclamtion;
Espace_Reclamation_1=lookup_widget(objet_graphique,"Espace_Reclamation_1");
Modifier_Reclamtion = create_Modifier_Reclamtion ();
gtk_widget_show (Modifier_Reclamtion);
gtk_widget_hide(Espace_Reclamation_1);

        /*label=lookup_widget(Espace_Reclamation_1,"label25");*/
        p=lookup_widget(Espace_Reclamation_1,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id_obs,1,&type_recl,2,&Description,3,&urgent,4,&num_electoral,-1);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_Reclamtion,"entryRMId")),id_obs);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_Reclamtion,"entryRMD")),Description);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(Modifier_Reclamtion,"spinbutton2")),num_electoral);


		if(strcmp(type_recl,"Fraude")==0) x=0;
                if(strcmp(type_recl,"Technique")==0) x=1;
		if(strcmp(type_recl,"problèmes-d-organisation")==0) x=2;
		 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(Modifier_Reclamtion,"comboboxentryRMType")),x);

}
label=lookup_widget(Modifier_Reclamtion,"labelEM");
label1=lookup_widget(Modifier_Reclamtion,"labelwrong3");
label2=lookup_widget(Modifier_Reclamtion,"labelwrong4");
label3=lookup_widget(Modifier_Reclamtion,"labelRobot2");
label4=lookup_widget(Modifier_Reclamtion,"labelobligatoire2");
gtk_widget_hide (label);
gtk_widget_hide (label1);
gtk_widget_hide (label2);
gtk_widget_hide (label3);
gtk_widget_hide (label4);

}


void
on_buttonRMReturn_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Reclamation_1;
GtkWidget *Modifier_Reclamtion;
GtkWidget *label;
GtkWidget *label1;
Modifier_Reclamtion=lookup_widget(objet_graphique,"Modifier_Reclamtion");
Espace_Reclamation_1 = create_Espace_Reclamation_1 ();
gtk_widget_show (Espace_Reclamation_1);
label=lookup_widget(Espace_Reclamation_1,"label25");
label1=lookup_widget(Espace_Reclamation_1,"label26");
gtk_widget_hide (label);
gtk_widget_hide (label1);
gtk_widget_hide(Modifier_Reclamtion);

}


void
on_buttonRRechercher_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Reclamation_1;
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelType;
GtkWidget *nbResultat;
GtkWidget *message;
char type[30];
char chnb[30];
int b=0,nb;
Espace_Reclamation_1=lookup_widget(objet_graphique,"Espace_Reclamation_1");
entry=lookup_widget(Espace_Reclamation_1,"entryRRecherche");
labelType=lookup_widget(Espace_Reclamation_1,"label26");
p1=lookup_widget(Espace_Reclamation_1,"treeview1");

strcpy(type,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(type,"")==0){
  gtk_widget_show (labelType);b=0;
}else{
b=1;
gtk_widget_hide (labelType);}

if(b==0){return;}else{

rechercherReclamation(p1,type);//type entry ecrie par lutilisateur
}

}





void
on_radiobuttonUrgent_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[0] = 1;
else
choix1[0] = 0;
}


void
on_radiobuttonMoyenne_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[1] = 1;
else
choix1[1] = 0;
}


void
on_radiobuttonPlustard_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[2] = 1;
else
choix1[2] = 0;
}


void
on_checkbuttonRreclamation_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix4[0] = 1;
else
choix4[0] = 0;

}


void
on_buttonRReclamer1_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

char str[4];
GtkWidget *Espace_Reclamation_2;
GtkWidget*id;
GtkWidget*des;
GtkWidget *combobox;
GtkWidget *label;
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label4;
label=lookup_widget(objet_graphique,"labelE");
label1=lookup_widget(objet_graphique,"labelwrong1");
label2=lookup_widget(objet_graphique,"labelwrong2");
label3=lookup_widget(objet_graphique,"labelRobot1");
label4=lookup_widget(objet_graphique,"labelobligatoire1");

agents p; 
Espace_Reclamation_2=lookup_widget(objet_graphique,"Espace_Reclamation_2");
combobox=lookup_widget(Espace_Reclamation_2,"comboboxentryRType");
strcpy(p.type_recl,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
id = lookup_widget(objet_graphique, "entryRId") ;
des = lookup_widget(objet_graphique, "entryRD") ;
strcpy(p.id_obs,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(p.Description,gtk_entry_get_text(GTK_ENTRY(des)));
if (choix1[0]==1)
strcpy(p.urgent,"Urgent");
else if (choix1[1]==1)
strcpy(p.urgent,"Moyenne");
else if (choix1[2]==1)
strcpy(p.urgent,"A-PLus-Tard");
p.num_electoral=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(Espace_Reclamation_2,"spinbutton1")));
if((strcmp(p.id_obs,"")==0)&&(strcmp(p.type_recl,"")!=0))
{
  gtk_widget_show (label1);
  gtk_widget_show (label4);
  gtk_widget_hide (label2);
}
else if ((strcmp(p.type_recl,"")==0)&&(strcmp(p.id_obs,"")!=0))
{
   gtk_widget_show (label2);
   gtk_widget_show (label4);
   gtk_widget_hide (label1);
}
else if ((strcmp(p.type_recl,"")==0)&&(strcmp(p.id_obs,"")==0))
{
gtk_widget_show (label1);
gtk_widget_show (label2);
gtk_widget_show (label4);
}
else if (choix4[0]==0)
{
gtk_widget_show (label3);
}
else 
{
ajouterR(p);
gtk_widget_show (label); 
gtk_widget_hide (label1);
gtk_widget_hide (label2);
gtk_widget_hide (label3);
gtk_widget_hide (label4);

}

}


void
on_buttonRMReclamer_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Modifier_Reclamtion;
GtkWidget*id;
GtkWidget*des;
GtkWidget *combobox;
GtkWidget *label;
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *label4;
label=lookup_widget(objet_graphique,"labelEM");
label1=lookup_widget(objet_graphique,"labelwrong3");
label2=lookup_widget(objet_graphique,"labelwrong4");
label3=lookup_widget(objet_graphique,"labelRobot2");
label4=lookup_widget(objet_graphique,"labelobligatoire2");

agents p; 
Modifier_Reclamtion=lookup_widget(objet_graphique,"Modifier_Reclamtion");
combobox=lookup_widget(Modifier_Reclamtion,"comboboxentryRMType");
strcpy(p.type_recl,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
id = lookup_widget(objet_graphique, "entryRMId") ;
des = lookup_widget(objet_graphique, "entryRMD") ;
strcpy(p.id_obs,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(p.Description,gtk_entry_get_text(GTK_ENTRY(des)));
if (choix2[0]==1)
strcpy(p.urgent,"Urgent");
else if (choix2[1]==1)
strcpy(p.urgent,"Moyenne");
else if (choix2[2]==1)
strcpy(p.urgent,"A-PLus-Tard");
p.num_electoral=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(Modifier_Reclamtion,"spinbutton2")));

if((strcmp(p.id_obs,"")==0)&&(strcmp(p.type_recl,"")!=0))
{
  gtk_widget_show (label1);
  gtk_widget_show (label4);
  gtk_widget_hide (label2);
}
else if ((strcmp(p.type_recl,"")==0)&&(strcmp(p.id_obs,"")!=0))
{
   gtk_widget_show (label2);
   gtk_widget_show (label4);
   gtk_widget_hide (label1);
}
else if ((strcmp(p.type_recl,"")==0)&&(strcmp(p.id_obs,"")==0))
{
gtk_widget_show (label1);
gtk_widget_show (label2);
gtk_widget_show (label4);
}
else if (choix3[0]==0)
{
gtk_widget_show (label3);
}
else 
{
modifier(p.id_obs, p);
gtk_widget_show (label); 
gtk_widget_hide (label1);
gtk_widget_hide (label2);
gtk_widget_hide (label3);
gtk_widget_hide (label4);

}

}


void
on_radiobuttonMurgent_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[0] = 1;
else
choix1[0] = 0;
}



void
on_radiobuttonMplus_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2[2] = 1;
else
choix2[2] = 0;
}


void
on_checkbuttonMReclamation_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix3[0] = 1;
else
choix3[0] = 0;
}

//////gestion_user/////

void
on_retour_ajout_user_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wt;
GtkWidget *wa;
wa=lookup_widget(objet_graphique,"wa");
wt=create_wt();
gtk_widget_show(wt);
gtk_widget_hide(wa);

}


void
on_enregister_ajout_user_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input0;
GtkWidget *wa;
GtkWidget *Combobox1 ;
GtkWidget *Combobox2 ;
GtkWidget *spinj;
GtkWidget *spinm;
GtkWidget *spina;

GtkWidget *output1;



wa=lookup_widget(objet_graphique,"wa");
input1=lookup_widget(objet_graphique,"nom_ajout_user");
input2=lookup_widget(objet_graphique,"prenom_ajout_user");
input3=lookup_widget(objet_graphique,"cin_ajout_user");
input4=lookup_widget(objet_graphique,"login_ajout_user"); 
input5=lookup_widget(objet_graphique,"mdp_ajout_user");
input6=lookup_widget(objet_graphique,"ajout_vote");
input0=lookup_widget(objet_graphique,"id_ajout_user");
output1=lookup_widget(objet_graphique,"lu51");




strcpy(U.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(U.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(U.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(U.loginu,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(U.passe,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(U.vote,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(U.idbv,gtk_entry_get_text(GTK_ENTRY(input0)));


	if (uaze==1)
	strcpy(U.sexe,"homme");
	else if (uaze==2)
	strcpy(U.sexe,"femme");



	if(use==1)

	strcpy(U.appart,"gauche");
	
	else if(use==2)

	strcpy(U.appart,"milieu");

	else if(use==3)

	strcpy(U.appart,"droite");

spinj=lookup_widget(objet_graphique, "jj_ajout_user");
spinm=lookup_widget(objet_graphique, "mm_ajout_user");
spina=lookup_widget(objet_graphique, "aa_ajout_user");

	

	U.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinj));
	U.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinm));
	U.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spina));
	

	
	Combobox1=lookup_widget(objet_graphique,"role_ajout_user");
	Combobox2=lookup_widget(objet_graphique,"natio_ajout_user");
	
	strcpy(U.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
	strcpy(U.natio,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));







gtk_label_set_text(GTK_LABEL(output1),"Utilisateur Enregistré");

ajouter_user(U);

}


void
on_check_ajout_droite_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))

use=3;
}


void
on_check_ajout_milieu_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
use=2;
}


void
on_check_ajout_gauche_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
use=1;

}


void
on_treeview_user_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_affiche_user_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wt;
GtkWidget *treeview_user;
wt=lookup_widget(objet_graphique,"wt");
treeview_user=lookup_widget(wt,"treeview_user");
afficher_user(treeview_user);

}


void
on_ajout_user_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wt;
GtkWidget *wa;
wt=lookup_widget(objet_graphique,"wt");
wa=create_wa();
gtk_widget_show(wa);
gtk_widget_hide(wt);
}


void
on_modif_user_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *wt;
GtkWidget *wm;
wt=lookup_widget(objet_graphique,"wt");
wm=create_wm();
gtk_widget_show(wm);
gtk_widget_hide(wt);
}


void
on_supp_user_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wt;
GtkWidget *ws;
wt=lookup_widget(objet_graphique,"wt");
ws=create_ws();
gtk_widget_show(ws);
gtk_widget_hide(wt);

}


void
on_u_retour_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wt;
GtkWidget *wst2;
wt=lookup_widget(objet_graphique,"wt");
wst2=create_wst2();
gtk_widget_show(wst2);
gtk_widget_hide(wt);
}


void
on_enregistrer_modif_user_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
UTILISATEUR U ;
UTILISATEUR nou;
GtkWidget *input0;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *wm;
GtkWidget *box1 ;
GtkWidget *box2 ;
GtkWidget *spinj;
GtkWidget *spinm;
GtkWidget *spina;

GtkWidget *output2;



output2=lookup_widget(objet_graphique,"lu50");
wm=lookup_widget(objet_graphique,"wm");
input1=lookup_widget(objet_graphique,"nom_modif_user");
input2=lookup_widget(objet_graphique,"prenom_modif_user");
input3=lookup_widget(objet_graphique,"cin_modif_user");
input4=lookup_widget(objet_graphique,"login_modif_user"); 
input5=lookup_widget(objet_graphique,"mdp_modif_user");
input6=lookup_widget(objet_graphique,"m_vote");
input0=lookup_widget(objet_graphique,"id_modif_user");
output2=lookup_widget(objet_graphique,"lu50");
strcpy(nou.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nou.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nou.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(nou.loginu,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nou.passe,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(nou.vote,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(nou.idbv,gtk_entry_get_text(GTK_ENTRY(input0)));


	if (uaze==1)
	strcpy(nou.sexe,"homme");
	else if (uaze==2)
	strcpy(nou.sexe,"femme");


	if(use==1)

	strcpy(nou.appart,"gauche");
	
	else if(use==2)

	strcpy(nou.appart,"milieu");

	else if(use==3)

	strcpy(nou.appart,"droite");

	spinj=lookup_widget(objet_graphique, "jj_modif_user");
	spinm=lookup_widget(objet_graphique, "mm_modif_user");
	spina=lookup_widget(objet_graphique, "aa_modif_user");

	

	nou.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinj));
	nou.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinm));
	nou.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spina));
	

	
	box1=lookup_widget(objet_graphique,"ucombobox2");
	box2=lookup_widget(objet_graphique,"ucombobox1");
	
	strcpy(nou.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(box1)));
	strcpy(nou.natio,gtk_combo_box_get_active_text(GTK_COMBO_BOX(box2)));


	gtk_label_set_text(GTK_LABEL(output2),"Utilisateur Modifié");
	modifier_user(mcin,nou,"users.txt");
}


void
on_annuler_modif_user_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wt;
GtkWidget *wm;
wm=lookup_widget(objet_graphique,"wm");
wt=create_wt();
gtk_widget_show(wt);
gtk_widget_hide(wm);

}


void
on_check_modif_droite_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
use=3;

}



void
on_check_modif_gauche_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
use=1;
}


void
on_homme_modif_user_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	uaze=1;
}


void
on_femme_modif_user_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	uaze=2;
}


void
on_loupe_modif_user_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	int utr=0;
	int ur,un;
	UTILISATEUR U;
	GtkWidget *wm;
	GtkWidget *input7;
	wm=lookup_widget(objet_graphique,"wm");
        GtkWidget *o10;
	input7=lookup_widget(objet_graphique,"cin_modif_user");
	o10=lookup_widget(objet_graphique,"lu54");
	strcpy(mcin,gtk_entry_get_text(GTK_ENTRY(input7)));
      



    if (chercher_user1(mcin,"users.txt")==1)
{
      U=chercher_user(mcin,"users.txt");
       gtk_label_set_text(GTK_LABEL(o10),"CIN TROUVEE"); 
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input0;

	GtkWidget *Combobox1 ;
	GtkWidget *Combobox2 ;
	GtkWidget *spj;
	GtkWidget *spm;
	GtkWidget *spa;

	GtkWidget *output1;
	GtkWidget *tog1;
	GtkWidget *tog2;
	GtkWidget *tog3;
	GtkWidget *tog4;
	GtkWidget *tog5;
	

	wm=lookup_widget(objet_graphique,"wm");
	tog1=lookup_widget(objet_graphique,"homme_modif_user");
	tog2=lookup_widget(objet_graphique,"femme_modif_user");
	tog3=lookup_widget(objet_graphique,"check_modif_droite");
	tog4=lookup_widget(objet_graphique,"check_modif_milieu");
	tog5=lookup_widget(objet_graphique,"check_modif_gauche");
	

	if (strcmp(U.sexe,"homme")==0)
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(tog1),TRUE);

	else if (strcmp(U.sexe,"femme")==0)
		
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(tog2),TRUE);


	if (strcmp(U.appart,"gauche")==0)

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(tog3),TRUE);
	
	if (strcmp(U.appart,"milieu")==0)

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(tog4),TRUE);

	if (strcmp(U.appart,"droite")==0)

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(tog5),TRUE);


	input1=lookup_widget(objet_graphique,"nom_modif_user");
	input2=lookup_widget(objet_graphique,"prenom_modif_user");
	input3=lookup_widget(objet_graphique,"cin_modif_user");
	input4=lookup_widget(objet_graphique,"login_modif_user"); 
	input5=lookup_widget(objet_graphique,"mdp_modif_user");
	input6=lookup_widget(objet_graphique,"m_vote");
	input0=lookup_widget(objet_graphique,"id_modif_user");
	output1=lookup_widget(objet_graphique,"lu51");

	gtk_entry_set_text(GTK_ENTRY(input1),U.nom);
	gtk_entry_set_text(GTK_ENTRY(input2),U.prenom);
	gtk_entry_set_text(GTK_ENTRY(input3),U.cin);
	gtk_entry_set_text(GTK_ENTRY(input4),U.loginu);
	gtk_entry_set_text(GTK_ENTRY(input5),U.passe);
	gtk_entry_set_text(GTK_ENTRY(input6),U.vote);
	gtk_entry_set_text(GTK_ENTRY(input0),U.idbv);

	spj=lookup_widget(objet_graphique, "jj_modif_user");
	spm=lookup_widget(objet_graphique, "mm_modif_user");
	spa=lookup_widget(objet_graphique, "aa_modif_user");


	gtk_spin_button_set_value(spj,U.jour);
	gtk_spin_button_set_value(spm,U.mois);
	gtk_spin_button_set_value(spa,U.annee);
	
	
	Combobox1=lookup_widget(objet_graphique,"ucombobox2");
	Combobox2=lookup_widget(objet_graphique,"ucombobox1");

	
        if (strcmp(U.natio,"TUNISIENNE")==0)

	un=0;
	
	else if (strcmp(U.natio,"ETRANGERE")==0)

	un=1;
	
	if (strcmp(U.role,"UTILISATEUR")==0)
	
	ur=0;
	
	else if (strcmp(U.role,"ELECTEUR")==0)

	ur=1;
	else if (strcmp(U.role,"OBSERVATEUR")==0)

	ur=2;
	else if (strcmp(U.role,"Agent")==0)

	ur=3;
	gtk_combo_box_set_active(GTK_COMBO_BOX(Combobox1),ur);
	gtk_combo_box_set_active(GTK_COMBO_BOX(Combobox2),un);

	}
else 
gtk_label_set_text(GTK_LABEL(o10),"CIN INTROUVABLE");
	

}


void
on_xm_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *xm;

xm=lookup_widget(objet_graphique,"wm");
gtk_widget_destroy(xm);
}


void
on_retour_supp_user_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wt;
GtkWidget *ws;
ws=lookup_widget(objet_graphique,"ws");
wt=create_wt();
gtk_widget_show(wt);
gtk_widget_hide(ws);
}


void
on_loupe_supp_user_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ws;
GtkWidget *input8;

ws=lookup_widget(objet_graphique,"c5");
input8=lookup_widget(objet_graphique,"recherche_supp_user");
strcpy(mcin,gtk_entry_get_text(GTK_ENTRY(input8)));
if (chercher_user1(mcin,"users.txt")==1)
       gtk_label_set_text(GTK_LABEL(ws),"CIN TROUVEE"); 
else 
gtk_label_set_text(GTK_LABEL(ws),"VERIFIER LE NUMERO CIN");
}


void
on_supp_supp_user_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output3;

output3=lookup_widget(objet_graphique,"s5");

supprimer_user(mcin,"users.txt");
gtk_label_set_text(GTK_LABEL(output3),"Utilisateur Supprime");
}


void
on_usercls_sup_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *usercls_sup;

usercls_sup=lookup_widget(objet_graphique,"ws");
gtk_widget_destroy(usercls_sup);
}


void
on_xst_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *xst;

xst=lookup_widget(objet_graphique,"wst");
gtk_widget_destroy(xst);
}


void
on_bbutton11_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wst2;
GtkWidget *wst;
wst=lookup_widget(objet_graphique,"wst");
wst2=create_wst2();
gtk_widget_show(wst2);
gtk_widget_hide(wst);
}


void
on_bbutton10_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *o10;
GtkWidget *in10 ;
in10=lookup_widget(objet_graphique,"bbutton10");

float uw,uz,uh;
float uy;

char uy1[50];
char umy[100]="	T =  ";
TPHF("users.txt",&uw,&uz,&uh);


uy=uz/uh*100;
sprintf(uy1,"%f",uy);
strcat(umy,uy1);
o10=lookup_widget(objet_graphique,"l64");
gtk_label_set_text(GTK_LABEL(o10),umy);
}


void
on_bbutton9_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *o9;
GtkWidget *in9 ;
in9=lookup_widget(objet_graphique,"bbutton9");

float uw,uz,uh;
float ux;
char ux1[50];
char umx[100]="	T =  ";

TPHF("users.txt",&uw,&uz,&uh);

ux=uw/uh*100;
sprintf(ux1,"%f",ux);
strcat(umx,ux1);

o9=lookup_widget(objet_graphique,"l63");
gtk_label_set_text(GTK_LABEL(o9),umx);
}


void
on_bbutton8_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *o8;
GtkWidget *in8 ;
in8=lookup_widget(objet_graphique,"bbutton8");


float uT;
char uT1[50];
char umsg[100]="	T =  ";

uT= TPE("users.txt");
sprintf(uT1,"%f",uT);
strcat(umsg,uT1);

o8=lookup_widget(objet_graphique,"l62");
gtk_label_set_text(GTK_LABEL(o8),umsg);
}


void
on_usercls_stat_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *usercls_stat;

usercls_stat=lookup_widget(objet_graphique,"wst2");
gtk_widget_destroy(usercls_stat);
}


void
on_s_u_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wst2;
GtkWidget *wst;
wst2=lookup_widget(objet_graphique,"wst2");
wst=create_wst();
gtk_widget_show(wst);
gtk_widget_hide(wst2);
}


void
on_g_u_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wst2;
GtkWidget *wt;
wst2=lookup_widget(objet_graphique,"wst2");
wt=create_wt();
gtk_widget_show(wt);
gtk_widget_hide(wst2);
}


void
on_r_g_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wst2;
GtkWidget *window_espa;
wst2=lookup_widget(objet_graphique,"wst2");
window_espa=create_window_espa();
gtk_widget_show(window_espa);
gtk_widget_hide(wst2);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-----------------------------------------------------------------OMNIA------------------------------------------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod12, *mod13, *mod14, *pInfo;
int id;
char conseillers[20];
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod12=lookup_widget(objet,"mod12");
mod13=lookup_widget(objet,"mod13");
mod14=lookup_widget(objet,"mod14");
id = atoi(gtk_entry_get_text(GTK_ENTRY(mod4)));
election e = chercher_election(id, "election.txt");
if(e.id!=-1){
sprintf(conseillers,"%d",e.conseillers);
gtk_entry_set_text(GTK_ENTRY(mod3),e.municipalite);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mod1),e.d.j);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mod2),e.d.m);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mod3),e.d.a);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod5), e.habitants);
gtk_entry_set_text(GTK_ENTRY(mod12),e.municipalite);
gtk_label_set_text(GTK_LABEL(mod13),conseillers);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Election introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod12, *mod13, *mod14, *pInfo;
election u;
char* ch = (char *) malloc(500);
strcpy(ch,"");
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod12=lookup_widget(objet,"mod12");
mod13=lookup_widget(objet,"mod13");
mod14=lookup_widget(objet,"mod14");
bool a=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(mod14));
if(strcmp(gtk_entry_get_text(GTK_ENTRY(mod12)),"")==0)
strcat(ch,"Veuillez écrire la municipalité\n");
if(!a)
strcat(ch,"Veuillez confirmer");
if(strcmp(ch,"")==0){
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod4)));
strcpy(u.municipalite,gtk_entry_get_text(GTK_ENTRY(mod12)));
u.d.j=gtk_spin_button_get_value(GTK_SPIN_BUTTON(mod1));
u.d.m=gtk_spin_button_get_value(GTK_SPIN_BUTTON(mod2));
u.d.a=gtk_spin_button_get_value(GTK_SPIN_BUTTON(mod3));
u.habitants=gtk_combo_box_get_active(GTK_COMBO_BOX(mod5));
u.conseillers=atoi(gtk_label_get_text(GTK_LABEL(mod13)));
modifier_election(u,"election.txt");
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,ch);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	guint id;
	GtkWidget *pInfo, *objet, *af;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cette élection?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer_election(id,"election.txt");
	afficher_election(treeview,"election.txt","","","");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}


void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af = lookup_widget(objet, "af");
treeview=lookup_widget(af,"treeview");
afficher_election(treeview,"election.txt", "","","");
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj12, *aj13, *aj14, *pInfo;
election u;
char *ch = (char *) malloc(500);
strcpy(ch,"");
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj12=lookup_widget(objet,"a12");
aj13=lookup_widget(objet,"aj13");
aj14=lookup_widget(objet,"aj14");
bool a=gtk_toggle_button_get_active(GTK_CHECK_BUTTON(aj14));
if(strcmp(gtk_entry_get_text(GTK_ENTRY(aj4)),"")==0)
strcat(ch,"Veuillez écrire l'id\n");
if(strcmp(gtk_entry_get_text(GTK_ENTRY(aj12)),"")==0)
strcat(ch,"Veuillez écrire la municipalité\n");
if(!a)
strcat(ch,"Veuillez confirmer");
if(strcmp(ch,"")==0){
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(aj4)));
strcpy(u.municipalite,gtk_entry_get_text(GTK_ENTRY(aj12)));
u.d.j=gtk_spin_button_get_value(GTK_SPIN_BUTTON(aj1));
u.d.m=gtk_spin_button_get_value(GTK_SPIN_BUTTON(aj2));
u.d.a=gtk_spin_button_get_value(GTK_SPIN_BUTTON(aj3));
u.habitants=gtk_combo_box_get_active(GTK_COMBO_BOX(aj5));
u.conseillers=atoi(gtk_label_get_text(GTK_LABEL(aj13)));
ajouter_election(u,"election.txt");
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,ch);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj;
aj=lookup_widget(objet,"aj");
aj=create_aj();
gtk_widget_show(aj);
}


void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj;
aj=lookup_widget(objet,"mod");
aj=create_mod();
gtk_widget_show(aj);
}


void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af, *e1, *e2, *e3;
char date[20], municipalite[20], id[10];
af=lookup_widget(objet,"af");
treeview=lookup_widget(af,"treeview");
e1=lookup_widget(objet, "entry1");
e2=lookup_widget(objet, "entry2");
e3=lookup_widget(objet, "entry3");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(e1)));
strcpy(municipalite,gtk_entry_get_text(GTK_ENTRY(e2)));
strcpy(date,gtk_entry_get_text(GTK_ENTRY(e3)));
afficher_election(treeview, "election.txt", id, municipalite, date);
}


void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo;
char *ch = taux_obs("obs.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,ch);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo;
char *ch = nb_obs("obs.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,ch);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_aj5_changed                         (GtkWidget     *objet,
                                        gpointer         user_data)
{
GtkWidget *aj5, *aj13;
char ch[50];
int a, cons;
aj13 = lookup_widget(objet, "aj13");
aj5 = lookup_widget(objet, "aj5");
a = gtk_combo_box_get_active(GTK_COMBO_BOX(aj5));
cons = a==0?10:a==1?12:a==2?16:a==3?22:a==4?30:a==5?40:60;
sprintf(ch,"%d",cons);
gtk_label_set_text(GTK_LABEL(aj13), ch);
}


void
on_mod5_changed                        (GtkWidget     *objet,
                                        gpointer         user_data)
{
GtkWidget *aj5, *aj13;
char ch[50];
int a, cons;
aj13 = lookup_widget(objet, "mod13");
aj5 = lookup_widget(objet, "mod5");
a = gtk_combo_box_get_active(GTK_COMBO_BOX(aj5));
cons = a==0?10:a==1?12:a==2?16:a==3?22:a==4?30:a==5?40:60;
sprintf(ch,"%d",cons);
gtk_label_set_text(GTK_LABEL(aj13), ch);
}

void
on_homme_ajout_user_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	uaze=1;
}


void
on_femme_ajout_user_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	uaze=2;
}


void
on_check_modif_milieu_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active((togglebutton)))
use=2;
}


void
on_radiobuttonMoyenne__toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonMmoyenne_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{ 
if (gtk_toggle_button_get_active(togglebutton))
choix2[1] = 1;
else
choix2[1] = 0;

}


void
on_buttonGLES_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menu_liste_electorale;
GtkWidget *window_espa;
menu_liste_electorale = create_menu_liste_electorale ();
 gtk_widget_show (menu_liste_electorale);
window_espa=lookup_widget(objet_graphique,"window_espa");
gtk_widget_hide(window_espa);

}


void
on_buttonAok_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Reclamation_1;  
GtkWidget *label;
GtkWidget *label1;
GtkWidget *Login;
Login=lookup_widget(objet_graphique,"Login");
GtkWidget*Role;
GtkWidget*Pass;
GtkWidget*labelAwrong;
char Role1[50];
char password1[50];
int l;
GtkWidget *window_espa;
Role = lookup_widget(Login, "entryARole") ;
Pass = lookup_widget(Login, "entryAPass") ;
strcpy(Role1,gtk_entry_get_text(GTK_ENTRY(Role)));
strcpy(password1,gtk_entry_get_text(GTK_ENTRY(Pass)));
l=verifierr(Role1,password1);
if (l==1)
{
Espace_Reclamation_1 = create_Espace_Reclamation_1 ();
  gtk_widget_show (Espace_Reclamation_1);
 label=lookup_widget(Espace_Reclamation_1,"label25");
label1=lookup_widget(Espace_Reclamation_1,"label26");
gtk_widget_hide (label);
gtk_widget_hide (label1);
}
else if (l==2)
{
 window_espa= create_window_espa ();
gtk_widget_show (window_espa);
}
else 
{
labelAwrong=lookup_widget(Login,"labelAwrong");
gtk_widget_show (labelAwrong);

}














}

