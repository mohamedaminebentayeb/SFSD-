#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "Fonctions.h"
//Pour l'affichage
#define selected_color 9
#define selected_background 7
#define not_selected_color 15
#define not_selected_background 0

int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO coninfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
    return coninfo.dwCursorPosition.Y;
}
/*------------------------------------------------------------------------------------------------------------------------*/
void textcolor(unsigned int color)
{
    if (color >15 || color <=0)
    {
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hcon,15);

    }
    else
    {
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hcon,color);
    }
}
/*------------------------------------------------------------------------------------------------------------------------*/
void textbackground(int bcolor)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;


    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        wColor = (csbi.wAttributes & 0xF) | ((bcolor  << 4 ) & 0xF0);
        SetConsoleTextAttribute(hStdOut, wColor);

    }
}
/*------------------------------------------------------------------------------------------------------------------------*/
int menu(int max,...) /* Fonction pour faire les choix */
{
    int choi,a,i,b,d,y;
    char p[max];
    char **choix=NULL;
    choix=malloc(max*sizeof(p));
    va_list marker;
    va_start( marker,max );
    for (i=0; i<max; i++)
    {
        choix[i] = va_arg( marker,char*);
    }
    va_end( marker );
    d=wherey();
    y=d;
    textcolor (selected_color);
    textbackground (selected_background);
    printf("%s\n",choix[0]);
    textbackground (not_selected_background);
    textcolor(not_selected_color);
    for (i=1; i<max; i++)
    {
        printf("%s\n",choix[i]);
    }
abbbbb:
    while((a=getch())==224)
    {
        b=getch();
        if(b==80 && y<d+max-1)
        {
            gotoxy(1,y);
            textcolor(not_selected_color);
            i=y-d;
            textbackground (not_selected_background);
            printf("%s",choix[i]);
            y++;
            textcolor (selected_color);
            gotoxy(1,y);
            textbackground (selected_background);
            printf("%s",choix[i+1]);
        }
        if(b==72 && y>d)
        {
            gotoxy(1,y);
            textcolor(not_selected_color);
            i=y-d;
            textbackground (not_selected_background);
            printf("%s",choix[i]);
            y--;
            textcolor (selected_color);
            gotoxy(1,y);
            textbackground (selected_background);
            printf("%s",choix[i-1]);
        }


    }
    if (a!=13)goto abbbbb;

    choi=y-d;
    textbackground (not_selected_background);
    textcolor(not_selected_color);
    gotoxy(1,d+4);
    return choi+1;
}
/*------------------------------------------------------------------------------------------------------------------------*/
COORD coord = {0,0};    /* Fonction pour changer la position d'ecriture */
void gotoxy(int x, int y )
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
/*------------------------------------------------------------------------------------------------------------------------*/
void color(int t,int f) /* Fonction pour changer les couleurs ( Texte / Arrière plan) */
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

/*------------------------------------------------------------------------------------------------------------------------*/
void affichage()
{
    color(15,0);
    printf("\n *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   ");
    color(10,0);
    printf("              _");
    printf("                                                            \n");
    printf("              ");
    printf("|_|");
    printf("                                                           \n");
    printf("              ");
    printf("/_/");
    printf("                                                             \n");
    printf("     ");
    printf("___  ___ _");
    printf("                                                              \n");
    printf("    ");
    printf("/ _ \\/ __| |");
    printf("                                                            \n");
    printf("   ");
    printf("|  __/\\__ \\ |");
    printf("           \n");
    printf("    ");
    printf("\\___||___/_|");
    printf("             \n");
    printf("    ");
    printf("\t\t\t\t\t");
    printf("E");
    Sleep(200);
    color(15,0);
    printf("C");
    Sleep(200);
    printf("O");
    Sleep(200);
    printf("L");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf(" ");
    Sleep(200);
    color(10,0);
    printf("N");
    color(15,0);
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("T");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("O");
    Sleep(200);
    printf("N");
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("L");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf(" ");
    Sleep(200);
    color(10,0);
    printf("S");
    color(15,0);
    Sleep(200);
    printf("U");
    Sleep(200);
    printf("P");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf("R");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf("U");
    Sleep(200);
    printf("R");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf(" ");
    Sleep(200);
    color(10,0);
    printf("D");
    Sleep(200);
    printf("'");
    Sleep(200);
    printf("I");
    Sleep(200);
    color(15,0);
    printf("N");
    Sleep(200);
    printf("F");
    Sleep(200);
    printf("O");
    Sleep(200);
    printf("R");
    Sleep(200);
    printf("M");
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("T");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("Q");
    Sleep(200);
    printf("U");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf("\n\n\t\t\t\t     STRUCTURES FICHIERS ET STRUCTURES DES DONNEES DYNAMIQUES\n");
    printf("\t\t\t\t\t\t      * SFSD * \n");
    printf("\n");
    color(10,0);
    printf("\t\t\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- \n") ;
    color(15,0);
    printf("\n\t\t\t\t\t\tTravail Pratique N :1 ");
    printf("\n\t\t\t\t\t   Manipulation des fichiers  ");
    printf("\n\n");
    color(10,0);
    printf("\t\t\t\t\t\t   Realise par :");
    printf("\n\n");
    color(15,0);
    printf("\t\t\t\t Bentayeb Mohamed Amine ");
    color(10,0);
    printf(" &  ");
    color(15,0);
    printf("Bouchouareb Ahmed Yacine   ");
    printf("\n\n\t\t\t\t\t\t     Groupe : 05");
    printf("\n\n\t\t\t\t\t Encadre Par :  ");
    Sleep(400);
    color(10,0);
    printf("P");
    Sleep(200);
    printf("r");
    Sleep(200);
    printf(" ");
    Sleep(200);
    printf("E");
    color(15,0);
    Sleep(200);
    printf("L");
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("L");
    Sleep(200);
    printf("L");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("A");
    Sleep(200);
    color(15,0);
    printf(" ");
    color(10,0);
    Sleep(200);
    printf("N");
    color(15,0);
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("D");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("A");
    Sleep(200);
    printf(" ");
    Sleep(200);
    printf("\n\n\t\t\t\t\t     Annee Universitaire : 2020 / 2021 ");
    printf("\n\n");
    color(10,0);
    printf("\t\t\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- \n") ;
    printf("\n");
    color(15,0);
    printf("\n *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   ");
    printf("\n\t\t\t\t            ");
    system("pause");
}
void AuRevoir()
{
    system("cls");
    color(11,0);
    gotoxy(55,16);
    Sleep(1000) ;
    printf("G");
    Sleep(150);
    printf("o");
    Sleep(150);
    printf("o");
    Sleep(150);
    printf("d");
    Sleep(150);
    printf(" ");
    Sleep(150);
    printf("B");
    Sleep(150);
    printf("y");
    Sleep(150);
    printf("e");
    Sleep(150);
    printf("!");
    Sleep(150);
    printf("\n\n\n\n\n\n\n\n\n\n");
    exit(EXIT_FAILURE);
}
//**************************************
void menu_func()
{
    TOF F_per;
    TOVC F_art;
    TOVC F_liv;
    LOVC F_mem;
    LOVbarC F;
    Index fichier_index;
//chier_index=fopen("Index_Periodiques.bin","rb");



    int menu1,menu2,menu3,menu4,menu5,menu6,menu7,menu8,menu9,menu10,menu11,n,menu12;

    int  trouv,pos,bloc;
    affichage();
    system("cls");
    color(11,0);
    printf("\n\n\n\n\n\n\n\t\t\t\t Vous choisissez l'une des operations suivantes:");
    printf("\n\n");
    menu11=menu(2,"\t\t\t\t\t1 fichier ouvrage deja exister","\t\t\t\t\t2 fichier  ouvrage non exister deja  ?");
    switch(menu11)
    {
    case 1 :
        ouvrire_LOVbarC(&F,"ouvrages.bin",'a');
        break;
    case 2 :
        ouvrire_LOVbarC(&F,"ouvrages.bin",'n');
        Fermer_LOVbarC(&F);
        break;

    }
    color(11,0);
    printf("\n\n\n\n\n\n\n\t\t\t\t Vous choisissez l'une des operations suivantes:");
    printf("\n\n");
    menu12=menu(2,"\t\t\t\t\t1 les 4 fichiere  existent deja","\t\t\t\t\t2 les 4 fichiers n'existent pas deja  ?");
    switch(menu12)
    {
    case 1 :
        ouvrire_TOVC(&F_art,"Articles.bin",'a');
        ouvrire_LOVC(&F_mem,"memoires.bin",'a');
        ouvrire_TOVC(&F_liv,"livres.bin",'a');
        ouvrire_TOF(&F_per,"periodiques.bin",'a');
        break;
    case 2 :
        ouvrire_TOVC(&F_art,"Articles.bin",'n');
        Fermer_TOVC(&F_art);
        ouvrire_LOVC(&F_mem,"memoires.bin",'n');
        Fermer_LOVC(&F_mem);
        ouvrire_TOVC(&F_liv,"livres.bin",'n');
        Fermer_TOVC(&F_liv);
        ouvrire_TOF(&F_per,"periodiques.bin",'n');
        fermer_TOF(&F_per);
        break;

    }


    //NeigeBienvenu() ;
    do
    {
principal:
        system("cls") ;
        printf("\n\n\n\n\n");
        color(11,0);
        printf("                                                      ---------------- \n");
        color(9,0);
        printf("   -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- ");
        color(11,0);
        printf("| Menu Principal |");
        color(9,0);
        printf(" -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
        color(11,0);
        printf("                                                      ---------------- ");
        printf("\n\n");
        color(15,0);
        printf("\n\t\t\t\t\t\t\t Traiter  : ");
        printf("\n\t\t\t\t(Utilisez les touches Haut-Bas du clavier pour avoir votre choix) \n");
        menu1= menu(3,"\t\t\t\t\t\t1 -  fichier ouvrage  ", "\t\t\t\t\t\t2 - les fichier creer a partir du fichier ouvrage ", "\t\t\t\t\t\t3 -Quitter ") ;
        system("cls");
        switch (menu1)
        {
        case 1: /* Parite1 */
            system("cls");
choixpartie1:
            color(11,0);
            printf("\n\n\n\n\n\n\n\t\t\t\t Vous choisissez l'une des operations suivantes:");
            printf("\n\n");
            menu2 =menu(6,"\t\t\t\t1 - creer le fichier ouvrage ? ", "\t\t\t\t2 - rechercher dans le fichier ouvrage ? ","\t\t\t\t3 - insertion dans le fichier ouvareg ?","\t\t\t\t4 - affichage du fichier  ouvrage ? ","\t\t\t\t5 - modifier la disponibilite d'un ouvrage ? ","\t\t\t\t6 - menu principale ? ") ;
            system("cls");
            switch(menu2)
            {
            case 1 :
                color(11,0);
                Cree_Ouvrage(&F);

                goto finapartie1;
                break;
            case 2 :
                color(11,0);
                ouvrire_LOVbarC(&F,"ouvrages.bin",'a');
                printf(" entrer la cle a chercher  : \n");
                scanf("%d",&n);
                recherche(&F,n,&bloc,&pos,&trouv);
                if(trouv==1)
                {
                    printf("\n clee trouver dans le bloc : %d  position : %d\n",bloc,pos);
                }
                else
                {
                    printf("\nla clee entrer n'existe pas \n");
                }
                Fermer_LOVbarC(&F);
                goto finapartie1 ;
                break;
            case 3 :
                ouvrire_LOVbarC(&F,"ouvrages.bin",'a');
                color(11,0);
                char ouvrage[b1];
                printf(" entrer la cle a inserer  : \n");
                scanf("%d",&n);
                remplir_ouvrage(ouvrage,n);
                insertion_Lovbarc(&F,n,ouvrage);
                Fermer_LOVbarC(&F);
                goto finapartie1 ;
                break;
            case 4 :
                color(55,16);
                ouvrire_LOVbarC(&F,"ouvrages.bin",'a');
                printf("\n\n\n\n\n\n\n\t\t\t\t     Vous choisissez l'une des operations suivantes:");
                printf("\n\n");
                menu7=menu(5,"\t\t\t\t1 - affichage bloc par bloc ? ","\t\t\t\t2 - affichage ouvrage par ouvrage? ","\t\t\t\t3 - affichage d'un bloc speciale ? ","\t\t\t\t3 - affichage de l'entete ? ","\t\t\t\t5 - retourner au menu principal ?");
                system("cls");
                switch(menu7)
                {
                case 01 :

                    affichage_bparb2(F);
                    break;
                case 02 :
                    affichage_bParB(F);
                    break;
                case 03 :

                    printf(" entrer e numero di bloc a afficher \n");
                    scanf("%d",&bloc);
                    if(bloc<=entete(F,4))
                    {
                        affichage_bloc2(F,&bloc);

                    }
                    else
                    {
                        printf("\n ce bloc n'existe pas \n");
                    }
                    break;
                case 04 :
                    affichage_entete(F);
                    break;
                case 05 :
                    goto principal;
                    break;

                }
                color(15,0);
                Fermer_LOVbarC(&F);
                goto finapartie1;
                break;

            case 05 :
                ouvrire_LOVbarC(&F,"ouvrages.bin",'a');
                int dispo;

                printf(" entrer la disponibilite  : 1 pour disponible et 0 pour indisponible : ");
                scanf("%d",&dispo);

                printf(" entrer la clee de l'ouvrage a modifier: ");
                scanf("%d",&n);
                if(dispo==0) modif_dispo(&F,n,'0');
                else  modif_dispo(&F,n,'1');
                Fermer_LOVbarC(&F);
                goto finapartie1;
                break;


            case 6 :/* Retourver au menu principal */
                goto principal ;
                break;
            }
            break;
            /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
finapartie1: /*Ce champs est commun pour tous les cas de choix ci-dessus(choix de partie1) */
            color(11,0);
            printf("\n");
            printf("\t\t\t\t\t\tChoisissez !");
            printf("\n");
            menu4=menu(3,"\t\t\t\t\t1- Retourner au choix de fichier ouvrage ?","\t\t\t\t\t2- Retourner au menu principal","\t\t\t\t\t3- Quitter");
            system("cls");
            switch(menu4)
            {
            case 1:
                goto choixpartie1;
                break;
            case 2:
                goto principal;
                break;
            case 3:
                goto fin;
                break;
            }
        /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
        case 2: /*partie2 */
            system("cls");
choixpartie2:
            color(11,0);
            printf("\n\n\n\n\n\n\n\t\t\t\t     Vous choisissez l'une des operations suivantes:");
            printf("\n\n");
            menu3 =menu(11,"\t\t\t\t\t1 - creer les quatre fichier  ? ", "\t\t\t\t\t2 - afficherle fichier livres? ","\t\t\t\t\t3 - affichage du fichier memoires ?","\t\t\t\t\t4 - affichage du fichier articles ? ","\t\t\t\t\t5 - Afficher le fichier periodique?","\t\t\t\t\t6 - rechercher dans le fichier periodique ?","\t\t\t\t\t7 -  creer le fichier index ?","\t\t\t\t\t8 - afficher le fichier index ?","\t\t\t\t\t9 - rechercher dans le fichier index ? ","\t\t\t\t\t10 - comparaison de recherche dans un fichier index et le fichier TOF ? ","\t\t\t\t\t11 - Retourner au menu principal ? ") ;
            system("cls");
            switch(menu3)
            {
            case 1 :
                ouvrire_LOVbarC(&F,"ouvrages.bin",'a');
                cree_fichier(F);
                Fermer_LOVbarC(&F);
                goto finapartie2;
                break;
            case 2 :
                ouvrire_TOVC(&F_liv,"livres.bin",'a');

                color(55,16);
                printf("\n\n\n\n\n\n\n\t\t\t\t     Vous choisissez l'une des operations suivantes:");
                printf("\n\n");
                menu8=menu(5,"\t\t\t\t\t1 - Afficher bloc par bloc ?","\t\t\t\t\t2 - Afficher ouvrage par ouvrage ?","\t\t\t\t\t3 - Afficherun bloc specifier ?","\t\t\t\t\t4 - Afficherun de l'entete ?","\t\t\t\t\t5 - Retourner au menu principale ?");
                system("cls");
                switch(menu8)
                {

                case 01 :
                    affichage_bparb_TOVC(F_liv);
                    break;
                case 02 :
                    affiche_livre(F_liv);
                    break;
                case 03 :
                    printf(" entrer le numero du bloc a ffficher : ");
                    scanf("%d",&bloc);
                    if(bloc<=entete_TOVC(F_liv,1))
                    {
                        affich_bloc_TOVC(F_liv,&bloc);
                    }
                    break;
                case 04 :
                    affichage_entete_TOVC(F_liv);
                    break;
                case 05 :
                    goto principal;
                    break;
                }
                Fermer_TOVC(&F_liv);
                goto finapartie2 ;
                break;
            case 4 :
                ouvrire_TOVC(&F_art,"Articles.bin",'a');

                color(55,16);
                printf("\n\n\n\n\n\n\n\t\t\t\t     Vous choisissez l'une des operations suivantes:");
                printf("\n\n");
                menu9=menu(5,"\t\t\t\t\t1 - Afficher bloc par bloc ?","\t\t\t\t\t2 - Afficher ouvrage par ouvrage ?","\t\t\t\t\t3 - Afficherun bloc specifier ?","\t\t\t\t\t3 - Afficher entete ?","\t\t\t\t\t5 - Retourner au menu principale ?");
                system("cls");
                switch(menu9)
                {

                case 01 :
                    affichage_bparb_TOVC(F_art);
                    break;
                case 02 :
                    affiche_art(F_art);
                    break;
                case 03 :
                    printf(" entrer le numero du bloc a ffficher : ");
                    scanf("%d",&bloc);
                    if(bloc<=entete_TOVC(F_art,1))
                    {
                        affich_bloc_TOVC(F_art,&bloc);
                    }
                    break;
                case 04 :
                    affichage_entete_TOVC(F_art);
                    break;
                case 05 :
                    goto principal;
                    break;
                }
                Fermer_TOVC(&F_art);
                goto finapartie2 ;
                break;
            case 3 :

                ouvrire_LOVC(&F_mem,"memoires.bin",'a');

                color(55,16);
                printf("\n\n\n\n\n\n\n\t\t\t\t     Vous choisissez l'une des operations suivantes:");
                printf("\n\n");
                menu10=menu(5,"\t\t\t\t\t1 - Afficher bloc par bloc ?","\t\t\t\t\t2 - Afficher ouvrage par ouvrage ?","\t\t\t\t\t3 - Afficherun bloc specifier ?","\t\t\t\t\t4 - Afficher entete ?","\t\t\t\t\t5 - Retourner au menu principale ?");
                system("cls");
                switch(menu10)
                {

                case 01 :
                    affichage_bparb2_LOVC(F_mem);
                    break;
                case 02 :
                    affichage_Memoire(F_mem);
                    break;
                case 03 :
                    printf(" entrer le numero du bloc a lire : ");
                    scanf("%d",&bloc);
                    if(bloc<=entete_LOVC(F_mem,4))
                    {
                        affichage_bloc2_LOVC(F_mem,&bloc);
                    }
                    break;
                case 04 :
                    affichage_entete_LOVC(F_mem);
                    break;
                case 05 :
                    goto principal;
                    break;
                }
                Fermer_LOVC(&F_mem);
                goto finapartie2;
                break;
            case 5:
                color(15,0);
                int menu15;
                ouvrire_TOF(&F_per,"periodiques.bin",'a');
                color(55,16);
                printf("\n\n\n\n\n\n\n\t\t\t\t     Vous choisissez l'une des operations suivantes:");
                printf("\n\n");
                menu15=menu(2,"\t\t\t\t\t1affichage TOF","\t\t\t\t\t2 Affichage entete TOF" ) ;
                system("cls");

                switch(menu15)
                {
                case 01 :
                    Affichage_TOF(F_per);
                    break;
                case 02 :
                    affichage_entete_TOF(F_per);
                    break;

                }
                goto finapartie2 ;
                break;
            case 6:
                color(15,0);
                printf(" entrer la clee a chercher dans le fihier periodique : ");
                scanf("%d",&n);
                ouvrire_TOF(&F_per,"periodiques.bin",'a');
                recherche_DICO_TOF(F_per,n,&bloc,&pos,&trouv);
                if(trouv==1)
                {
                    printf(" la clee %d est trouver au bloc %d position %d \n",n,bloc,pos);
                }
                else
                {
                    printf(" la clee %d n'existe pas \n",n);
                }
                goto finapartie2 ;
                break;
            case 7:
                ouvrire_TOF(&F_per,"periodiques.bin",'a');
                ouvrire_Index(&fichier_index,"Index_Periodiques.bin",'n');
                cree_table_index(F_per);

                goto finapartie2;
                break;
            case 8:


                ouvrire_Index(&fichier_index,"Index_Periodiques.bin",'a');
                color(55,16);
                printf("\n\n\n\n\n\n\n\t\t\t\t     Vous choisissez l'une des operations suivantes:");
                printf("\n\n");
                int menu18=menu(2,"\t\t\t\t\t1affichage index","\t\t\t\t\t2 Affichage entete index" ) ;
                system("cls");

                switch(menu18)
                {
                case 01 :
                    affichage_index(fichier_index);
                    break;
                case 02 :
                    affichage_entete_index(fichier_index);
                    break;

                }

                goto finapartie2;
                break;
            case 9:
                ouvrire_Index(&fichier_index,"Index_Periodiques.bin",'a');
                color(15,0);
                printf(" entrer le numero de la clee a chercher  : ");
                scanf("%d",&n);
                recherche_index(n);
                goto finapartie2;
                break;
            case 10:
                ouvrire_Index(&fichier_index,"Index_Periodiques.bin",'a');
                color(15,0);
                printf(" entrer le numero de la clee a chercher  : ");
                scanf("%d",&n);
                  ouvrire_TOF(&F_per,"periodiques.bin",'a');
                recherche_DICO_TOF(F_per,n,&bloc,&pos,&trouv);
                recherche_index(n);
                if(C8>C6)printf(" \n le cout de la recherche de %d dans le fichier TOF est plus que  le cout de la recherche dans le fichier index\n",n);
                else{if(C8<C6) printf(" \n le cout de la recherche de %d dans le fichier index est plus que  le cout de la recherche dans le fichier TOF\n",n);
                      else printf(" \n le cout de la recherche de %d dans le fichier index est le meme que  le cout de la recherche dans le fichier TOF\n",n);
                     }
               goto finapartie2;
                break;
            case 11 :/* Retourver au menu principal */
                goto principal ;
                break;
            }
            break;
            /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
finapartie2: /*Ce champs est commun pour tous les cas de choix ci-dessus(choix de partie2) */
            color(11,0);
            printf("\n");
            printf("\t\t\t\t\t\tChoisissez !");
            printf("\n");
            menu5=menu(3,"\t\t\t\t\t1- Retourner au choix de partie2 ?","\t\t\t\t\t2- Retourner au menu principal","\t\t\t\t\t3- Quitter");
            system("cls");
            switch(menu5)
            {
            case 1:
                goto choixpartie2;
                break;
            case 2:
                goto principal;
                break;
            case 3:
                goto fin;
                break;
            }
            /*----------------------------------------------------------------------------------------------------------------------------*/

fin:
        case 3: /* Quitter */
            AuRevoir();
            break;
        }

    }
    while ((menu1 <1) || (menu1 >3));
}






int main()
{
    menu_func();



    return 0;
}
