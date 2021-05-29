#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   b1 400
#define t1 12//taille de l auteur et titre - 1
#define Taille_Bloc 100
#define Taille_Bloc_TOF 11
#define Taille_Index 20
///================================Variables de cout===========================
int C1;//cout de cree ouvrages.bin
int C2;//cout de la recherche d'un ouvrage
int C3;//cout de l'insertion d'un ouvrage
int C4;//cout de changement la disponibilité d'un ouvrage
int C51;//cout de cree livres.bin
int C52;//cout de cree memoires.bin
int C53;//cout de cree articles.bin
int C54;//cout de cree periodiques.bin
int C6;//cout de la recherche dans le fichier periodiques.bin
int C7;//cout de la creation de la table d'index
int C8;//cout de la recherche dans la table d'index
///========================INDEX==============================================
typedef struct INDEX_tof {
    char cle[5];
    int bloc;
    int pos;
}Index_tof;
typedef struct Index_Bloc{
Index_tof tab[Taille_Index];
int nb_enreg_inserer;
}Index_Bloc;
typedef struct Entete_Index{
int nb_bloc;
int dernier_pos;
} Entete_Index;

typedef struct Fichier_Index {
    Entete_Index entete;
    FILE *fichier;
}Index;
//==================== Machine abstraite Index ================================================================
void fermer_Index(Index *F);
void Aff_Entete_Index(Index *F,int i,int val);
int entete_Index(Index F,int i);
void Ecrire_Dir_Index(Index *F,int i,Index_Bloc buf);
void Lire_Dir_Index(Index F,int i,Index_Bloc *buf);
void ouvrire_Index(Index *F,char nom[20],char mode);
void Alloc_bloc_Index(Index *F);

//======= LOVC ==================================================================
typedef struct LOVCbloc{
    char tab[b1];//tableau de caractere
    int suiv;//numero du bloc suivant
} LOVCbloc;
typedef struct LOVCbloc Buffer_LOVC;//declaration du Buffer_liste
typedef struct Entete_LOVC{
    int tete;//adresse du premier bloc
    int nbInsert;//nombre globale des caracteres inserer
    int nbSupp;//nombre globale des caractere supprimer
    int nb_bloc;//nombre de bloc
}Entete_LOVC;
typedef struct Fichier_LOVC {
    Entete_LOVC entete;
    FILE *file;
}LOVC;
//=============TOF===============================================================
typedef struct enregistrement  {
char cle[5];
char titre[t1];
char auteurs[t1];
char anne_pub[5];
char dispo[2];
} enregistrement ;
typedef struct TOF_Bloc{
enregistrement tab[Taille_Bloc_TOF];
int nb_enreg_inserer;
}TOF_Bloc;
typedef struct Entete_TOF{
int nb_bloc;
int dernier_pos;
} Entete_TOF;

typedef struct Fichier_TOF {
    Entete_TOF entete;
    FILE *fichier;
}TOF;
///==================== Machine abstraite TOF=================================================================
void fermer_TOF(TOF *F);
void Aff_Entete_TOF(TOF *F,int i,int val);
int entete_TOF(TOF F,int i);
void Ecrire_Dir_TOF(TOF *F,int i,TOF_Bloc buf);
void Lire_Dir_TOF(TOF F,int i,TOF_Bloc *buf);
void ouvrire_TOF(TOF *F,char nom[20],char mode);
void Alloc_bloc_TOF(TOF *F );
//=======LOVbarC=================================================================
//=======Declarations des structures===========================================
typedef struct Lbloc{
    char tab[b1];//tableau de caractere
    int suiv;//numero du bloc suivant
} Lbloc;

typedef struct Lbloc Buffer_liste;//declaration du Buffer_liste

typedef struct Entete{
    int tete;//adresse du premier bloc
    int nbInsert;//nombre globale des caracteres inserer
    int nbSupp;//nombre globale des caractere supprimer
    int nb_bloc;//nombre de bloc
}Entete;


typedef struct Fichier_LOVbarC {
    Entete entete;
    FILE *file;
}LOVbarC;
//=========Machine Abstraite TOVC============================================================================
//=================les structures====================================================/
typedef struct Tbloc      //la structure de bloc
{
    char chaine[Taille_Bloc];   //il s'agit d'une chaine de caractères
} Tbloc;


typedef struct  ouvrage        //structure où on récupère aussi les différents champs d'un enregistrement
{
    char clee [4];            //le code de livre
    char titre [20] ;  //l'auteur_le titre_la maison d'édition
    char auteurs [20];
   char annee [4];
   char dispo[1];
   char code[4];
   char resume [50];
} ouvrage;

typedef struct Tbloc Buffer;  //le buffer où on récupère on bloc

typedef struct Entete_TOVC
{
    int nb_bloc;//nombre du bloc inserer
    int dernier_pos;//dernier position dans le dernier bloc

} Entete_TOVC;

typedef struct TOVC     //structure de fichier
{
    FILE * fichier;             //poiteur vers le fichier
    Entete_TOVC entete;       //l'entete de fichier
} TOVC;
//===========machine abstraite LOVbarC==============================
void Aff_Entete(LOVbarC *F,int i,int val);
void affichage_bloc(char ouvrage[] , int taille);
int entete(LOVbarC F,int i);

void Ecrire_Dir_LOVbarC(LOVbarC *F,int i,Buffer_liste buf);

void Lire_Dir_LOVbarC(LOVbarC F,int i,Buffer_liste *buf);
void ouvrire_LOVbarC(LOVbarC *F,char nom[20],char mode);

void Fermer_LOVbarC(LOVbarC *F);
void Alloc_Bloc(LOVbarC *F,int dernier_bloc);
//=============Macihne abstraite TOVC================================
void Aff_Entete_TOVC( TOVC *F,int i,int val);
int entete_TOVC(TOVC F,int i);
void Ecrire_Dir_TOVC(TOVC *F,int i,Buffer *buf);
void Lire_Dir_TOVC(TOVC F,int i,Buffer *buf);
void ouvrire_TOVC(TOVC *F,char nom[20],char mode);
void Fermer_TOVC(TOVC *F);
void Alloc_Bloc_TOVC(TOVC *F);

///===================================================LOVC================================================================
void Aff_Entete_LOVC(LOVC *F,int i,int val);
int entete_LOVC(LOVC F,int i);
void Ecrire_Dir_LOVC(LOVC *F,int i,Buffer_LOVC buf);

void Lire_Dir_LOVC(LOVC F,int i,Buffer_LOVC *buf);
void ouvrire_LOVC(LOVC *F,char nom[20],char mode);

void Fermer_LOVC(LOVC *F);
void Alloc_Bloc_LOVC(LOVC *F,int dernier_Bloc);


void affichage_Memoire(LOVC F);

//==============Fonctions du TP=======================================
void del_type(char ouvrage[b1]);//fonction qui supprime le type
void affichage_TOVC(TOVC F);
void majuscule(char nom[20]);
//========debugging stuff=======================
void affichage_entete(LOVbarC F); ///affichage de l'entete du fichier LOVC bar
void affichage_entete_LOVC(LOVC F); ///affichage de l'entete du fichier LOVC
void affichage_entete_TOF(TOF F); ///affichage de l'entete du fichier TOF
void affichage_entete_TOVC(TOVC F); ///affichage de l'entete du fichier TOVC
void affichage_article(char chaine[b1], int taille); /// chaine est le l'article
void affichage_bParB(LOVbarC F); /// affichage du fichier LOVC bar article par article
void ecrire_chaine(LOVbarC *F,int i,char s[b1]);
void aleat_chaine(char chaine[50],int taille);/// genere une chaine aleatoirement f'une taille donner
void aleat_resum(char chaine[50],int min , int max); /// generer un resume de taille entre mi et max
void aleat_type(char *chaine[24]); /// generer un type aleatoirement
void aleat_anne(char chaine[5]);/// genere une annne de pub aleatoirement
void int_to_char(int num , char chain[5]); /// transformer un entier a une chaine de caractere
void aleat_disponible(char *dispo[2]); /// generer la disponibiliter aleatoirement

int detectType(char ouvrage[b1]); /// detecter l etype d'un livre a partir du l'ouvrage

void alea_chaine(char chaine[],int max,int min); ///sup ou egale a min et strictement inf a max
void remplir_ouvrage(char ouvrage[b1],int cle); /// remplir un uvrage
void Cree_Ouvrage(LOVbarC *F); /// creer le fichier ouvrage
void recherche (LOVbarC *F ,int clee, int *bloc, int *pos , int *trouv);///rechercher un livre dans le fichier LOVCbar
void modif_dispo(LOVbarC *F ,int clee , char nv_etat);///modifier la disponibilitee d'un livre
///=================================================================
void del_type_cote(char ouvrage[b1]); /// suprimer la cote et le type de l'ouvrage
void affichage_bloc2(LOVbarC F,int *i); /// affiche un bloc du fichier LOVCbar
void affichage_bparb2(LOVbarC F); /// afficher le fichier LOVC bar bloc par bloc
void affiche_livre(TOVC F); /// afficher le fichier livre ouvrage par ouvrage
void affiche_art(TOVC F); ///afficher le fichier article ouvrage par ouvrage
void recuperer_chaine_TOVC(TOVC *F,int n, int *i, int *j, char chaine[],Tbloc *buf); /// recupereer une chaine de taille n a partir du fichier TOVC
void recuperer_chaine(LOVbarC *F,int n, int *i, int *j, char chaine[],Buffer_liste *buf); ///recupereer une chaine de taille n a partir du fichier LOVCbar
void remplir_livre(TOVC *F , int *bloc , int *pos , char ouvrage[] ,Buffer * buf ); ///remplir le fichier livre
void remplir_memoire(LOVC *F ,char ouvragee[b1] ,int * bloc ,int *pos , Buffer_LOVC *buf );///remplir le fichier memoire
void remplir_articl(TOVC *F , int *bloc , int * pos , char ouvrage[] , Tbloc *buf );///remplir le fichier article
void Affichage_TOF(TOF F); /// afficher le fichier TOF periodique
void remplir_enreg(char ouvrage[b1],enregistrement *enr); ///remplir un enregistrement a partir d'un ouvrage
void remplir_periodique(TOF *F , int *bloc ,int *pos,TOF_Bloc *buf ,enregistrement enrg); ///remplir le fichier TOF periodique
void cree_fichier(LOVbarC F); /// creer les 4 fichier a partir du fichier ouvrage (LOVC bar)
void recup_reste_ouvrage(int pos,char ouvrage[b1], char reste[b1]); /// recuperer le reste du bloc a partir de la postion pos
void insertion_Lovbarc(LOVbarC *F, int clee , char ouvrage[]);
void affiche_article_livr(char ouvrage[], int taille); /// inserer un ouvrage dans un fichier LOVCbar
void affichage_article(char chaine[b1],int taille);/// afficher un ouvrage du fichier article
void affichage_article_liv(chaine,taille); /// afficher un ouvrage du fichier livre
void recuperer_chaine_LOVC(LOVC *F,int n, int *i, int *j, char chaine[],LOVCbloc *buf); /// recuperer une chaine de taille n  du fichier LOVC
void affiche_enreg(enregistrement enr);/// afficher un enregistrement
void affichage_bloc2_LOVC(LOVC F,int *i); /// afficher un bloc du fichier LOVC
void affichage_bparb2_LOVC(LOVC F);/// afficher fichier LOVC  bloc par bloc
void affich_bloc_TOVC(TOVC F, int *i);/// afficher un bloc du fichier TOVC
void affiche_bloc_TOF(TOF F , int bloc);/// afficher un bloc du fichier TOF
void affichage_bparb_TOVC(TOVC F);/// afficher fichier TOVC  bloc par bloc
void recherche_DICO_TOF(TOF F , int clee , int *bloc, int *pos , int *trouv); /// recherche dicotomique dans un fichier TOF
void recherche_index(int clee); /// recherche dicotomique dans un fichier index
void cree_table_index(TOF F); /// creation du fichier index
void affichage_index(Index F) ; /// affichage du fichier index
void affichage_entete_index(Index F);

#endif // FONCTIONS_H_INCLUDED
