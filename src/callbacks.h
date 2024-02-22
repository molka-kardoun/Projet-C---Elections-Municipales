#include <gtk/gtk.h>


void
on_radiobuttonAG_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAC_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAD_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_ajouterLE_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

/* ---------------------------- INTERFACE Modifier/Supp ------------------------------- */

void
on_consulterLE_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonGE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonCE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonDE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_supprimerLE_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_saveChangesLE_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficherLE_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toAffLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toAddLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toModLE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toVote_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toStats_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_voter_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_refreshTreeView_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_refreshStat1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_refreshStat2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supListe_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_toSupprimerListe_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkModif_activate                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ge_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_gbv_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_user_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_brtr_espa_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_alcls_espa_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bsup_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bcls_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_brtr_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bact_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_baj_gbv_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bmod_gbv_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_br_gbv_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_rtr_espa_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bcls_gbva_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_enrg_gbva_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_banl_gbva_clicked                (GtkWidget       *button,
                                        gpointer         user_data);


void
on_al_check_gbva_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_al_radio100_gbva_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_al_radio200_gbva_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_al_radio300_gbva_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_al_bcls_gbvm_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bmod_gbvm_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_radio100_gbvm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_al_radio200_gbvm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_al_radio300_gbvm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_al_check_gbvm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_al_benrg_gbvm_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_banl_gbvs_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bsuppr_gbvs_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bcls_gbvs_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bsup_gbvs_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_banl_gbvm_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bespa_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bstat_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_alcls_esp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bagem_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_bnbe_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_al_brtr_stat_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_alcls_stat_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonRRefreche_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRReclamer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRReturn_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRSupprimer_clicked            (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRModifier_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRMReturn_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRRechercher_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_radiobuttonUrgent_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonMoyenne_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonPlustard_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonRreclamation_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonRReclamer1_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRMReclamer_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonMurgent_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonMmoyenne_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonMplus_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonMReclamation_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retour_ajout_user_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_enregister_ajout_user_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_check_ajout_droite_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_ajout_milieu_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_ajout_gauche_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_treeview_user_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_affiche_user_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajout_user_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modif_user_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_user_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_u_retour_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_enregistrer_modif_user_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_annuler_modif_user_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_check_modif_droite_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_check_modif_gauche_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_homme_modif_user_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_modif_user_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_loupe_modif_user_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_xm_clicked                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_supp_user_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_loupe_supp_user_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_supp_user_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_usercls_sup_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_xst_clicked                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_bbutton11_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_bbutton10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_bbutton9_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_bbutton8_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_usercls_stat_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_s_u_clicked                           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_g_u_clicked                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_r_g_clicked                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aj5_changed                         (GtkWidget     *objet,
                                        gpointer         user_data);

void
on_mod5_changed                        (GtkWidget     *objet,
                                        gpointer         user_data);


void
on_homme_ajout_user_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme_ajout_user_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_modif_milieu_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonMoyenne__toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonMmoyenne_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonGLES_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAok_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data);
