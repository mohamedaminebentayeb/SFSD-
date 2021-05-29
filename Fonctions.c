#include "Fonctions.h"
///==================== Machine abstraite Index=================================================================
void fermer_Index(Index *F)
{
    rewind(F->fichier);
    fwrite(&(F->entete),sizeof(Entete_Index),1,F->fichier);//sauvgarder l'entete
    rewind(F->fichier);
    fclose(F->fichier);
}
void Aff_Entete_Index(Index *F,int i,int val)
{
    switch(i)
    {
    case 1://modifier la tete
        F->entete.nb_bloc=val;
        break;
    case 2://modifier le nombre de caracteres inserer
        F->entete.dernier_pos=val;
        break;

    }
}
void affichage_entete_index(Index F)
{
    printf(" \nle nombre de bloc : %d\n ",entete_Index(F,1));
    printf(" \nderniere position : %d\n ",entete_Index(F,2));
}

int entete_Index(Index F,int i)
{
    switch(i)
    {
    case 1://retourner le nombre de bloc
        return F.entete.nb_bloc;
        break;
    case 2://retourner la derniere position
        return F.entete.dernier_pos;
        break;
    }
}
void Ecrire_Dir_Index(Index *F,int i,Index_Bloc buf)
{

    fseek(F->fichier,sizeof(Entete_Index)+sizeof(Index_Bloc)*(i-1),SEEK_SET);//positionné sur le i eme bloc
    fwrite(&buf,sizeof(Index_Bloc),1,F->fichier);//ecriture

}

void Lire_Dir_Index(Index F,int i,Index_Bloc *buf)
{
    {
        fseek(F.fichier,sizeof(Entete_Index)+sizeof(Index_Bloc)*(i-1),SEEK_SET);////positionné sur le i eme bloc
        fread(buf,sizeof(Index_Bloc),1,F.fichier);//lecture
    }
}
void ouvrire_Index(Index *F,char nom[20],char mode)
{

    if (mode =='A' || mode =='a')
    {
        F->fichier=fopen(nom,"rb+");
        fread(&(F->entete),sizeof(Entete_Index),1,F->fichier);//lecture de l'entete
    }
    else if (mode =='N' || mode =='n')
    {
        F->fichier=fopen(nom,"wb+");
        TOF_Bloc buf;
        //initialisation de l'entete
        Aff_Entete_Index(F,1,0);
        Aff_Entete_Index(F,2,0);
        //ecriture d'entete
        fwrite(&(F->entete),sizeof(Entete_Index),1,F->fichier);
        //nitialisation du Buffer_liste
        // sprintf(buf.chaine,"");
        // Ecrire_Dir_TOVC(F,1,buf);
    }
    else
        printf("\nErreur dans le mode d'ouverture!\n");
}

void Alloc_bloc_Index(Index *F )
{
    Aff_Entete_Index(F,1,entete_Index(*F,1)+1);
}
///==================== Machine abstraite TOF=================================================================
void fermer_TOF(TOF *F)
{
    rewind(F->fichier);
    fwrite(&(F->entete),sizeof(Entete_TOF),1,F->fichier);//sauvgarder l'entete
    rewind(F->fichier);
    fclose(F->fichier);


}
void Aff_Entete_TOF(TOF *F,int i,int val)
{
    switch(i)
    {
    case 1://modifier la tete
        F->entete.nb_bloc=val;
        break;
    case 2://modifier le nombre de caracteres inserer
        F->entete.dernier_pos=val;
        break;

    }
}

int entete_TOF(TOF F,int i)
{
    switch(i)
    {
    case 1://retourner le nombre de bloc
        return F.entete.nb_bloc;
        break;
    case 2://retourner la derniere position
        return F.entete.dernier_pos;
        break;
    }
}
void Ecrire_Dir_TOF(TOF *F,int i,TOF_Bloc buf)
{

    fseek(F->fichier,sizeof(Entete_TOF)+sizeof(TOF_Bloc)*(i-1),SEEK_SET);//positionné sur le i eme bloc
    fwrite(&buf,sizeof(TOF_Bloc),1,F->fichier);//ecriture

}

void Lire_Dir_TOF(TOF F,int i,TOF_Bloc *buf)
{
    {
        fseek(F.fichier,sizeof(Entete_TOF)+sizeof(TOF_Bloc)*(i-1),SEEK_SET);////positionné sur le i eme bloc
        fread(buf,sizeof(TOF_Bloc),1,F.fichier);//lecture
    }
}
void ouvrire_TOF(TOF *F,char nom[20],char mode)
{

    if (mode =='A' || mode =='a')
    {
        F->fichier=fopen(nom,"rb+");
        fread(&(F->entete),sizeof(Entete_TOF),1,F->fichier);//lecture de l'entete
    }
    else if (mode =='N' || mode =='n')
    {
        F->fichier=fopen(nom,"wb+");
        TOF_Bloc buf;
        //initialisation de l'entete
        Aff_Entete_TOF(F,1,0);
        Aff_Entete_TOF(F,2,0);
        //ecriture d'entete
        fwrite(&(F->entete),sizeof(Entete_TOF),1,F->fichier);
        //nitialisation du Buffer_liste
        // sprintf(buf.chaine,"");
        // Ecrire_Dir_TOVC(F,1,buf);
    }
    else
        printf("\nErreur dans le mode d'ouverture!\n");
}

void Alloc_bloc_TOF(TOF *F )
{
    Aff_Entete_TOF(F,1,entete_TOF(*F,1)+1);
}
///===================================================LOVC================================================================
void Aff_Entete_LOVC(LOVC *F,int i,int val)
{
    switch(i)
    {
    case 1://modifier la tete
        F->entete.tete=val;
        break;
    case 2://modifier le nombre de caracteres inserer
        F->entete.nbInsert=val;
        break;
    case 3://modifier le nombre de caracteres supprimer
        F->entete.nbSupp=val;
        break;
    case 4:
        F->entete.nb_bloc=val;
        break;
    }
}
void affichage_entete_LOVC(LOVC F)
{

    printf("\n la tete %d\n",entete_LOVC(F,1));
    printf(" le nombre de caracteres inserer %d\n",entete_LOVC(F,2));
    printf(" le nombre de caracteres supprimer %d\n",entete_LOVC(F,3));
    printf(" Le nombre de bloc est : %d\n",entete_LOVC(F,4));


}
void affichage_entete_TOVC(TOVC F)
{

    printf(" \nle nombre de bloc : %d\n ",entete_TOVC(F,1));
    printf(" \nderniere position : %d\n ",entete_TOVC(F,2));
}
void affichage_entete_TOF(TOF F)
{

    printf(" \nle nombre de bloc : %d\n ",entete_TOF(F,1));
    printf(" \nderniere position : %d\n ",entete_TOF(F,2));
}

int entete_LOVC(LOVC F,int i)
{
    switch(i)
    {
    case 1://retourner la tete
        return F.entete.tete;
        break;
    case 2://retourner le nombre de caracteres inserer
        return F.entete.nbInsert;
        break;
    case 3://retourner le nombre de caracteres supprimer
        return F.entete.nbSupp;
        break;
    case 4:
        return F.entete.nb_bloc;
        break;

    }
}
void Ecrire_Dir_LOVC(LOVC *F,int i,Buffer_LOVC buf)
{
    fseek(F->file,sizeof(Entete_LOVC)+sizeof(Buffer_LOVC)*(i-1),SEEK_SET);//positionné sur le i eme bloc
    fwrite(&buf,sizeof(Buffer_LOVC),1,F->file);//ecriture

}

void Lire_Dir_LOVC(LOVC F,int i,Buffer_LOVC *buf)
{
    {
        fseek(F.file,sizeof(Entete_LOVC)+sizeof(Buffer_LOVC)*(i-1),SEEK_SET);////positionné sur le i eme bloc
        fread(buf,sizeof(Buffer_LOVC),1,F.file);//lecture
    }
}


void ouvrire_LOVC(LOVC *F,char nom[20],char mode)
{

    if (mode =='A' || mode =='a')
    {
        F->file=fopen(nom,"rb+");
        fread(&(F->entete),sizeof(Entete_LOVC),1,F->file);//lecture de l'entete
    }
    else if (mode =='N' || mode =='n')
    {
        F->file=fopen(nom,"wb+");
        Buffer_LOVC buf;
        //initialisation de l'entete
        Aff_Entete_LOVC(F,1,0);
        Aff_Entete_LOVC(F,2,0);
        Aff_Entete_LOVC(F,3,0);
        Aff_Entete_LOVC(F,4,0);
        //ecriture d'entete
        fwrite(&(F->entete),sizeof(Entete_LOVC),1,F->file);
        //nitialisation du Buffer_liste
        sprintf(buf.tab,"");
        buf.suiv=NULL;
        Ecrire_Dir_LOVC(F,1,buf);
    }
    else
        printf("\nErreur dans le mode d'ouverture!\n");


}

void Fermer_LOVC(LOVC *F)
{
    rewind(F->file);
    fwrite(&(F->entete),sizeof(Entete_LOVC),1,F->file);//sauvgarder l'entete
    rewind(F->file);
    fclose(F->file);
}
void Alloc_Bloc_LOVC(LOVC *F,int dernier_Bloc) //en ajoute un bloc vide a la derniere position
{
    Buffer_LOVC buf;
    //Lire_Dir_LOVC(*F,dernier_Bloc,&buf);//lecture du dernier bloc
    //modification du dernier bloc et l'entete
    Aff_Entete_LOVC(F,4,dernier_Bloc);
    //sauvgarde le bloc
    buf.suiv=dernier_Bloc+1;
    sprintf(buf.tab,"%s","");
    //sauvgarde du nouveau bloc
    Ecrire_Dir_LOVC(F,dernier_Bloc,buf);
    //initalisation du nouveau bloc
}



void affichage_Memoire(LOVC F)  /// afficher le fichier memoire
{
    int i=entete_LOVC(F,1);
    LOVCbloc buf;
    char taille_char[5];
    char ouvrage[b1];
    int taille;
    int pos=0,bloc=entete_LOVC(F,1);
    if(F.file!=NULL)
    {
        if(i!=NULL)
        {
            Lire_Dir_LOVC(F,1,&buf);
        }

        printf("\n************************************DEBUT AFFICHAGE MEMOIRE************************************************\n");
        while(bloc!=NULL)
        {
            recuperer_chaine_LOVC(&F,4,&bloc,&pos,taille_char,&buf); //ecuperer la taille de l'article
            taille_char[4]='\0';
            taille=atoi(taille_char);
            recuperer_chaine_LOVC(&F,taille,&bloc,&pos,ouvrage,&buf); // recuperer l'article
            if(bloc!=NULL)
                affichage_article_liv(ouvrage, taille);
        }
        printf("\n************************************FIN AFFICHAGE MEMOIRE************************************************\n");

    }
    else
    {
        printf(" \n le fichier n'existe pas \n");
    }
}

///------------------------------------------------------------------------------------------------------------
//=========Machine Abstraite LOV\C============================================================================


void Aff_Entete(LOVbarC *F,int i,int val)
{
    switch(i)
    {
    case 1://modifier la tete
        F->entete.tete=val;
        break;
    case 2://modifier le nombre de caracteres inserer
        F->entete.nbInsert=val;
        break;
    case 3://modifier le nombre de caracteres supprimer
        F->entete.nbSupp=val;
        break;
    case 4:
        F->entete.nb_bloc=val;
        break;
    }
}

int entete(LOVbarC F,int i)
{
    switch(i)
    {
    case 1://retourner la tete
        return F.entete.tete;
        break;
    case 2://retourner le nombre de caracteres inserer
        return F.entete.nbInsert;
        break;
    case 3://retourner le nombre de caracteres supprimer
        return F.entete.nbSupp;
        break;
    case 4:
        return F.entete.nb_bloc;
        break;

    }
}

void Ecrire_Dir_LOVbarC(LOVbarC *F,int i,Buffer_liste buf)
{
    fseek(F->file,sizeof(Entete)+sizeof(Buffer_liste)*(i-1),SEEK_SET);//positionné sur le i eme bloc
    fwrite(&buf,sizeof(Buffer_liste),1,F->file);//ecriture

}

void Lire_Dir_LOVbarC(LOVbarC F,int i,Buffer_liste *buf)
{
    {
        fseek(F.file,sizeof(Entete)+sizeof(Buffer_liste)*(i-1),SEEK_SET);////positionné sur le i eme bloc
        fread(buf,sizeof(Buffer_liste),1,F.file);//lecture
    }
}
void ouvrire_LOVbarC(LOVbarC *F,char nom[20],char mode)
{

    if (mode =='A' || mode =='a')
    {
        F->file=fopen(nom,"rb+");
        fread(&(F->entete),sizeof(Entete),1,F->file);//lecture de l'entete
    }
    else if (mode =='N' || mode =='n')
    {
        F->file=fopen(nom,"wb+");
        Buffer_liste buf;
        //initialisation de l'entete
        Aff_Entete(F,1,0);
        Aff_Entete(F,2,0);
        Aff_Entete(F,3,0);
        Aff_Entete(F,4,0);
        //ecriture d'entete
        fwrite(&(F->entete),sizeof(Entete),1,F->file);
        //nitialisation du Buffer_liste
        sprintf(buf.tab,"");
        buf.suiv=NULL;
        Ecrire_Dir_LOVbarC(F,1,buf);
    }
    else
        printf("\nErreur dans le mode d'ouverture!\n");


}

void Fermer_LOVbarC(LOVbarC *F)
{
    rewind(F->file);
    fwrite(&(F->entete),sizeof(Entete),1,F->file);//sauvgarder l'entete
    rewind(F->file);
    fclose(F->file);
}

void Alloc_Bloc(LOVbarC *F,int dernier_Bloc ) //en ajoute un bloc vide a la derniere position
{
    Buffer_liste buf;

    Lire_Dir_LOVbarC(*F,dernier_Bloc,&buf);//lecture du dernier bloc
    //modification du dernier bloc et l'entete
    buf.suiv=dernier_Bloc+1;
    Aff_Entete(F,4,dernier_Bloc);
    //sauvgarde le bloc
    // Ecrire_Dir_LOVbarC(F,dernier_Bloc,buf);

    //initalisation du nouveau bloc
    buf.suiv=NULL;
    sprintf(buf.tab,"%s","");
    //sauvgarde du nouveau bloc
    Ecrire_Dir_LOVbarC(F,dernier_Bloc,buf);


}
///=============Macihne abstraite TOVC======================================
void Aff_Entete_TOVC( TOVC *F,int i,int val)
{
    switch(i)
    {
    case 1://le dernier bloc
        F->entete.nb_bloc=val;
        break;
    case 2://la derniere position dans le dernier bloc
        F->entete.dernier_pos=val;
        break;

    }
}

int entete_TOVC(TOVC F,int i)
{
    switch(i)
    {
    case 1://retourner la tete
        return F.entete.nb_bloc;
        break;
    case 2://retourner la derniere position dans le ddernier bloc
        return F.entete.dernier_pos;
        break;


    }
}
void Ecrire_Dir_TOVC(TOVC *F,int i,Buffer *buf)
{
    fseek(F->fichier,sizeof(Entete_TOVC)+sizeof(Tbloc)*(i-1),SEEK_SET);//positionné sur le i eme bloc
    fwrite(buf,sizeof(Tbloc),1,F->fichier);//ecriture

}

void Lire_Dir_TOVC(TOVC F,int i,Buffer *buf)
{
    {
        fseek(F.fichier,sizeof(Entete_TOVC)+sizeof(Tbloc)*(i-1),SEEK_SET);////positionné sur le i eme bloc
        fread(buf,sizeof(Tbloc),1,F.fichier);//lecture
    }

}
void ouvrire_TOVC(TOVC *F,char nom[20],char mode)
{

    if (mode =='A' || mode =='a')
    {
        F->fichier=fopen(nom,"rb+");
        fread(&(F->entete),sizeof(Entete_TOVC),1,F->fichier);//lecture de l'entete
    }
    else if (mode =='N' || mode =='n')
    {
        F->fichier=fopen(nom,"wb+");
        Buffer buf;
        //initialisation de l'entete
        Aff_Entete_TOVC(F,1,0);
        Aff_Entete_TOVC(F,2,0);
        //ecriture d'entete
        fwrite(&(F->entete),sizeof(Entete_TOVC),1,F->fichier);
        //nitialisation du Buffer_liste
        sprintf(buf.chaine,"");
        Ecrire_Dir_TOVC(F,1,&buf);
    }
    else
        printf("\nErreur dans le mode d'ouverture!\n");


}

void Fermer_TOVC(TOVC *F)
{
    rewind(F->fichier);
    fwrite(&(F->entete),sizeof(Entete_TOVC),1,F->fichier);//sauvgarder l'entete
    rewind(F->fichier);
    fclose(F->fichier);
}


void Alloc_Bloc_TOVC(TOVC *F)
{
    Aff_Entete_TOVC(F,1,entete_TOVC(*F,1)+1);
}

///=========================Fonctions du TP========================================
void del_type(char ouvrage[b1]) //fonction qui supprime le type
{
    int j=0,i=0;//j pour ouvrage i pour temp
    char temp[b1];//variable temporaire
    strcpy(temp,"");
    for(j=0; j<strlen(ouvrage); j++)
    {

        if (j!=2*(t1-1)+8 && j!=2*(t1-1)+9)
        {
            sprintf(temp,"%s%c",temp,ouvrage[j]);
        }
    }
    sprintf(ouvrage,"%s",temp);
    //modfication du champ taille

    int taille_int=strlen(ouvrage)-4;
    char nouvelle_taille[5];
    int_to_char(taille_int,nouvelle_taille);
    for(int i=0; i<4; i++)
    {
        ouvrage[i]=nouvelle_taille[i];
    }

}



void majuscule(char nom[20])
{
    int i=0;
    while(nom[i])
    {
        nom[i]=toupper(nom[i]);
        i++;
    }
}



//========debugging stuff=======================
void affichage_entete(LOVbarC F)
{
    printf("\n la tete %d\n",entete(F,1));
    printf(" le nombre de caracteres inserer %d\n",entete(F,2));
    printf(" le nombre de caracteres supprimer %d\n",entete(F,3));
    printf(" Le nombre de bloc est : %d\n",entete(F,4));
}

void affichage_article(char chaine[b1],int taille) //affichier l'article separer la cle le titre...
{

    int indice=0,cpt=1, i=0;
    char chaine2[t1];
    strcpy(chaine2,"");


    printf(" \n louvrage %d est :\n",cpt);
    for(i=0; i!=4; i++) /// recuperer la clee
    {
        chaine2[i]=chaine[indice];
        indice++;
    }
    chaine2[4]='\0';
    printf(" la clee est : %s\n",chaine2);
    for(i=0; i!=t1-1; i++) /// recuperer le titre
    {
        chaine2[i]=chaine[indice];
        indice++;
    }
    chaine2[t1-1]='\0';
    printf(" la titre est  est : %s\n",chaine2);
    for(i=0; i!=t1-1; i++) /// recuperer les auteurs
    {
        chaine2[i]=chaine[indice];
        indice++;
    }

    chaine2[t1-1]='\0';
    printf(" les auteurs sont : %s\n",chaine2);

    for(i=0; i!=4; i++) /// recuperer l'anne de pub
    {
        chaine2[i]=chaine[indice];
        indice++;
    }
    chaine2[4]='\0';
    printf(" l'anne de publication est : %s\n",chaine2);
    if(chaine[indice]=='1')
    {
        printf(" oui il est disponible \n");   /// verefier si il est disponible ou non
    }
    else
    {
        printf(" desolee il n'est pas disponible \n");
    }
    indice++;


    printf(" le resume : "); /// afficher le resume
    while(indice != taille)
    {
        printf("%c",chaine[indice]);
        indice++;
    }
    printf("\n/////////////////////////////////////////////////////////////////////////////////////////////////\n");



}

void affichage_article_liv(char chaine[b1],int taille) //affichier un seul article du fichier livres
{

    int indice=0,cpt=1, i=0;
    char chaine2[t1];
    strcpy(chaine2,"");


    printf(" \n louvrage %d est :\n",cpt);
    for(i=0; i!=4; i++) /// recuperer la clee
    {
        chaine2[i]=chaine[indice];
        indice++;
    }
    chaine2[4]='\0';
    printf(" la clee est : %s\n",chaine2);
    for(i=0; i!=t1-1; i++) /// recuperer le titre
    {
        chaine2[i]=chaine[indice];
        indice++;
    }
    chaine2[t1-1]='\0';
    printf(" la titre est  est : %s\n",chaine2);
    for(i=0; i!=t1-1; i++) /// recuperer les auteurs
    {
        chaine2[i]=chaine[indice];
        indice++;
    }

    chaine2[t1-1]='\0';
    printf(" les auteurs sont : %s\n",chaine2);


    for(i=0; i!=4; i++) /// recuperer l'annne de publication
    {
        chaine2[i]=chaine[indice];
        indice++;
    }
    chaine2[4]='\0';
    printf(" l'anne de publication est : %s\n",chaine2);
    if(chaine[indice]=='1')
    {
        printf(" oui il est disponible \n");   /// verefier si il est disponible
    }
    else
    {
        printf(" desolee il n'est pas disponible \n");
    }
    indice++;
    for(i=0; i!=4; i++) /// recuperer la cote
    {
        chaine2[i]=chaine[indice];
        indice++;
    }
    chaine2[4]='\0';
    printf(" la cote  est : %s\n",chaine2);

    printf(" le resume : ");  /// recuperation et affichage duresume
    while(indice != taille)
    {
        printf("%c",chaine[indice]);
        indice++;
    }
    printf("\n/////////////////////////////////////////////////////////////////////////////////////////////////\n");



}
void affichage_bloc(char ouvrage[], int taille)  /// affichage d'un article du fichier ouvrages
{
    int indice=0,cpt=1, i=0;
    char chaine2[t1];
    strcpy(chaine2,"");


    printf(" \n louvrage %d est :\n",cpt); /// recup la clle
    for(i=0; i!=4; i++)
    {
        chaine2[i]=ouvrage[indice];
        indice++;
    }
    chaine2[4]='\0';
    printf(" la clee est : %s\n",chaine2);
    for(i=0; i!=t1-1; i++) /// recup le titre
    {
        chaine2[i]=ouvrage[indice];
        indice++;
    }
    chaine2[t1-1]='\0';
    printf(" la titre est  est : %s\n",chaine2);
    for(i=0; i!=t1-1; i++) ///  recup les auteurs
    {
        chaine2[i]=ouvrage[indice];
        indice++;
    }

    chaine2[t1-1]='\0';
    printf(" les auteurs sont : %s\n",chaine2);
    for(i=0; i!=2; i++) ///  recup le type
    {
        chaine2[i]=ouvrage[indice];
        indice++;
    }

    chaine2[2]='\0';
    printf(" le type est : %s\n",chaine2);


    for(i=0; i!=4; i++) ///  recup de l'annne de pub
    {
        chaine2[i]=ouvrage[indice];
        indice++;
    }
    chaine2[4]='\0';
    printf(" l'anne de publication est : %s\n",chaine2);
    if(ouvrage[indice]=='1')
    {
        printf(" oui il est disponible \n");   /// verefier si il est disponible
    }
    else
    {
        printf(" desolee il n'est pas disponible \n");
    }
    indice++;
    for(i=0; i!=4; i++) ///  recup la cote
    {
        chaine2[i]=ouvrage[indice];
        indice++;
    }
    chaine2[4]='\0';
    printf(" la cote  est : %s\n",chaine2);

    printf(" le resume : "); /// recuperation et affichage du resume
    while(indice != taille)
    {
        printf("%c",ouvrage[indice]);
        indice++;
    }
    printf("\n/////////////////////////////////////////////////////////////////////////////////////////////////\n");



}




void affichage_bParB(LOVbarC F) //affichage bloc par bloc
{

    int j =0;
    char ouvrage[b1];
    if(F.file!=NULL)
    {
        int taille,i=entete(F,1);
        Buffer_liste buf;
        if(i!=NULL)
        {
            Lire_Dir_LOVbarC(F,i,&buf);
        }
        printf("\n***********************************************DEBUT AFFICHAGE**********************************************\n");
        while (i!=0)
        {
            recuperer_chaine(&F,4,&i,&j,ouvrage,&buf);/// recuperer la taille de l'ouvrage
            taille=atoi(ouvrage);
            recuperer_chaine(&F,taille,&i,&j,ouvrage,&buf);/// recuperer l'ouvrage
            if(i!=NULL)
            {
                affichage_bloc( ouvrage, taille);   ///affichage de l'ouvrage
            }

        }
        printf("\n***********************************************FIN AFFICHAGE**********************************************\n");
    }
    else
    {
        printf(" \n le fichier n'existe pas \n");
    }
}



void ecrire_chaine(LOVbarC *F,int i,char s[b1])
{
    Buffer_liste buf;
    Lire_Dir_LOVbarC(*F,i,&buf);
    sprintf(buf.tab,"%s",s);

    Aff_Entete(F,2,entete(*F,2)+strlen(s));
    Ecrire_Dir_LOVbarC(F,i,buf);
}



void aleat_chaine(char chaine[50],int taille) /// generer une chaine de taille " taille" aleatoirement
{
    char alphabet[26]="abcdefghijklmnopqrstuvwxyz";
    strcpy(chaine,"");


    for (int i=0; i<taille; i++)
    {
        chaine[i]=alphabet[rand()%26];
    }
    chaine[taille-1]='\0';

}
void aleat_resum(char chaine[50],int max, int min)  /// generer un resume aleatoirement dont la taille est entre max et min
{
    char alphabet[26]="abcdefghijklmnopqrstuvwxyz";
    strcpy(chaine,"");
    if (max > min)
    {
        int nombreDeCaracteres=rand()%(max - min)+min;
        for (int i=0; i<nombreDeCaracteres; i++)
        {
            chaine[i]=alphabet[rand()%26];
        }
        chaine[nombreDeCaracteres-1]='\0';
    }
    else
    {
        printf("\nErreur dans les arguments max ou min");
    }


}
void aleat_type(char *chaine[3]) /// genere un type du livre aleatoirement
{
    int n ;
    char type[3];
    n=rand()%4;
    switch(n)
    {
    case 0  :
        strcpy(type,"TI");// Text imprime
        break;
    case 1  :
        strcpy(type,"DE");// document electronique
        break;

    case 2  :
        strcpy(type,"AR");// Article
        break;
    case 3  :
        strcpy(type,"PR");// P
        break;
    }
    sprintf(chaine,"%s",type);
}
void aleat_anne(char chaine[5]) /// genere une anne aleatoirement
{
    int n ;
    n=rand()%72+1950;

    int_to_char(n,chaine);

}
void int_to_char(int num,char chain[5])   /// transforme un entier a une chaine de caractere
{
    char chaine[11]="0123456789";
    char chaine2[5]="0000";
    int i,n;
    for(i=3; i!=-1; i--)
    {
        n=num%10;
        if(n!=0)
        {
            chaine2[i]=chaine[n];
        }
        num=num/10;
    }
    chaine2[4]='\0';
    sprintf(chain,"%s",chaine2);
}
void aleat_disponible(char *dispo[2]) /// genere la disponibilite aleatoirement
{
    int a;
    a=(int) rand()%2;
    sprintf(dispo,"%d",a);
}



void alea_chaine(char chaine[],int max,int min)  //sup ou egale a min et strictement inf a max
{
    char alphabet[26]="abcdefghijklmnopqrstuvwxyz";
    strcpy(chaine,"");
    if (max > min)
    {
        int nombreDeCaracteres=rand()%(max - min)+min;
        for (int i=0; i<nombreDeCaracteres; i++)
        {
            chaine[i]=alphabet[rand()%26];
        }
        chaine[nombreDeCaracteres-1]='\0';
    }
    else
    {
        printf("\nErreur dans les arguments max ou min");
    }

}
void remplir_ouvrage(char ouvrage[b1],int cle)  ///remplir un ouvrage aleatoirement
{
    strcpy(ouvrage,"0000");
    //generation de la cle
    char cle_char[5];
    int_to_char(cle,cle_char);
    sprintf(ouvrage,"%s%s",ouvrage,cle_char);
    //generation du titre
    char titre[t1];//de 19 caractere
    aleat_chaine(titre,t1);//de t caractere
    sprintf(ouvrage,"%s%s",ouvrage,titre);
    //generation du auteur
    char auteur[t1];
    aleat_chaine(auteur,t1);//de t caractere
    sprintf(ouvrage,"%s%s",ouvrage,auteur);
    //generation du type
    char type[3];
    aleat_type(type);
    sprintf(ouvrage,"%s%s",ouvrage,type);
    //generation du l anne
    char anne_char[5];
    aleat_anne(anne_char);
    sprintf(ouvrage,"%s%s",ouvrage,anne_char);
    //generation du champ disponible
    char disp[2];
    aleat_disponible(disp);
    sprintf(ouvrage,"%s%s",ouvrage,disp);

    //generation du la cote (la meme que la cle)
    sprintf(ouvrage,"%s%s",ouvrage,cle_char);
    //generation du reume
    char resume[50];
    aleat_resum(resume,15,10);
    sprintf(ouvrage,"%s%s",ouvrage,resume);
    int taille=strlen(ouvrage)-4;
    char taille_char[5];
    int_to_char(taille,taille_char);
    for (int i=0; i<4; i++)
    {
        ouvrage[i]=taille_char[i];
    }
}
void Cree_Ouvrage(LOVbarC *F)  /// creer le fichier ouvrage
{
    C1=0;//initialisation la variable du cout
    ouvrire_LOVbarC(F,"ouvrages.bin",'n');
    int n=0;
    printf("\nEntrer le nombre des ouvrages: ");
    scanf("%d",&n);
    if(n>0 && n <10000)
    {
        int k;//coeficiant pour generer les clés
        k=10000/n;//10000 parce que la cle est sur 4 bits(champ)

        Buffer_liste buf;//buffer
        strcpy(buf.tab,"");
        buf.suiv=NULL;
        int j=0,bloc=1;//indice de buf.suiv
        Aff_Entete(F,1,bloc);
        Aff_Entete(F,4,bloc);
        int i;
        int ernier_bloc=1;
        int dernier_inserer=1;
        char ouvrage[b1];//variable qui va contenire l'ouvrage
        int saturation=0;//bool qui indique l'obligation d ajouter un autre bloc
        for ( i=0; i<n; i++)
        {
            remplir_ouvrage(ouvrage,i*k);

            j=strlen(ouvrage)+strlen(buf.tab);

            if (j<b1-1)
            {


                sprintf(buf.tab,"%s%s",buf.tab,ouvrage);//on ajoute l ouvrage dans le bloc
            }
            else
            {
                saturation=1;

                // if(i == n-1)  {dernier_inserer=1;}
            }

            if(saturation==1 || i==n-1)
            {
                if((saturation==0)&&(i == n-1))
                {
                    buf.suiv=NULL;
                }
                else
                {
                    buf.suiv=bloc+1;
                }
                Alloc_Bloc(F,dernier_inserer);
                dernier_inserer++;
                Ecrire_Dir_LOVbarC(F,bloc,buf);//on ecrit le bloc
                C1++;//incermentation du variable du cout
                Aff_Entete(F,2,entete(*F,2)+j);//incrementation du nombre de caractere inserer
                j=0;
                if(saturation==1)
                {
                    sprintf(buf.tab,"%s",ouvrage);
                }
                else
                {
                    strcpy(buf.tab,"");
                }
                saturation=0;
                bloc++;


            }

        }
        if(strcmp(buf.tab,"")!=0)
        {
            buf.suiv=NULL;
            Ecrire_Dir_LOVbarC(F,bloc,buf);//on ecrit le bloc
            C1++;//incermentation du variable du cout

            Aff_Entete(F,2,entete(*F,2)+strlen(buf.tab));//incrementation du nombre de caractere inserer

        }
        Aff_Entete(F,4,C1);



    }
    else if (n!=0) {
        printf("\nErreur n doit etre entre 0 et 9999!");
    }

    printf("\nLe cout de creation de %d ouvrages dans le fichier ouvrages.bin est C1 = %d .\n",n,C1);
    system("pause");

    Fermer_LOVbarC(F);
}
void recherche (LOVbarC *F,int clee, int *bloc, int *pos, int *trouv)   /// rechercher dans un fichier LOVCbar
{
    C2=0;//initialisation la variable du cout

    int i,k,j=0;
    i=entete(*F,1);
    *trouv=0;
    *pos=0;
    *bloc=1;
    int taille;
    char taille_art[5];
    Buffer_liste buf;
    int stop=0;
    int indice =0;
    char ouvrage[b1]; // on recupere l'ouvrage
    char cle2[5];// la clee recuperer de l'ouvrage
    if(F->file!=NULL)
    {
        if(i!=NULL)
        {
            Lire_Dir_LOVbarC(*F,i,&buf);
            C2++;
        }
        while (i!=NULL)
        {

            recuperer_chaine(F,4,&i,&j,taille_art,&buf); /// recuperer la taille du l'ouvrage
            taille=atoi(taille_art);
            recuperer_chaine(F,4,&i,&j,cle2,&buf); /// recupererl 'ouvrage
            cle2[5]='\0';
            if(i==NULL)
            {
                *pos=j;;
                break;
            }
            j-=8;
            *bloc=i;
            *pos=j;




            if(clee==atoi(cle2))  /// verefier si la clee est trouver
            {
                *trouv=1;

                break;
            }
            else  if(clee<atoi(cle2))  /// verefier si on a depasser la clee
            {
                break;
            }
            recuperer_chaine(&F,taille+4,&i,&j,ouvrage,&buf);

        }
        if (i==NULL){
            i=entete(*F,4);
        }
        C2=i;//incermentation du variable du cout
    }
    printf("\nLe cout de la recherche de la cle %d dans le fichier ouvrages.bin C2 = %d .\n",clee,C2);
    system("pause");


}

void modif_dispo(LOVbarC *F,int clee, char nv_etat)   // 1 pour disponible et 0 pour indisponible
{



    int pos,bloc,trouv;
    printf("\nLe cout de la recherche dans modif dispo:");
    recherche(F,clee,&bloc,&pos,&trouv);
    C4=C2;//initialisation la variable du cout
    if(trouv==1)
    {
        int i;
        Buffer_liste buf;
        Lire_Dir_LOVbarC(*F,bloc,&buf);
        C4++;//incermentation du variable du cout
        pos=pos+14+(2*(t1-1));
        buf.tab[pos]=nv_etat; /// modifier l'etat
        Ecrire_Dir_LOVbarC(F,bloc,buf);
        C4++;//incermentation du variable du cout
    }

    else
    {
        printf(" desole ce livre n'existe pas merci d'entrer une clee qui existe!\n");
    }
    printf("\nLe cout de modif dispo de la cle %d dans le fichier ouvrages.bin C4 = %d .\n",clee,C4);
    system("pause");

}

///=================================================================
void del_type_cote(char ouvrage[b1])/// supression de la cote et le type
{
    del_type(ouvrage);
    int j=0,i=0;//j pour ouvrage i pour temp
    char temp[b1];//variable temporaire
    strcpy(temp,"");

    for(j=0; j<strlen(ouvrage); j++)
    {

        if (j!=2*(t1-1)+13 && j!=2*(t1-1)+14 && j!=2*(t1-1)+15 && j!=2*(t1-1)+16)
        {

            sprintf(temp,"%s%c",temp,ouvrage[j]);
        }
    }
    sprintf(ouvrage,"%s",temp);
    //modfication du champ taille
    char taille[5];
    strncat(taille,ouvrage,4);
    taille[4]='\0';
    int taille_int;
    taille_int=strlen(ouvrage)-4;

    char nouvelle_taille[5];
    int_to_char(taille_int,nouvelle_taille);
    for(int i=0; i<4; i++)
    {
        ouvrage[i]=nouvelle_taille[i];
    }


}
int detectType(char ouvrage[b1])
{

    char type=ouvrage[2*(t1-1)+8];
    switch (type)
    {
    case 'A' :
        return 1;//1 est article
        break;
    case 'P':
        return 2;//2 est periodique
        break;
    case 'T':
        return 3;//3 est Texte imprime
        break;
    case 'D':
        return 4;//4 est Document electronique
        break;
    default:
        printf("\nType introuvale %s",type);
        break;
    }
}


void affiche_bloc_TOF(TOF F, int bloc)
{
    if(F.fichier!=NULL)
    {
        TOF_Bloc buf;
        if (bloc<=entete_TOF(F,1))
        {
            Lire_Dir_TOF(F,bloc,&buf);
            int i =buf.nb_enreg_inserer;
            for(int k =0 ; k!=i; k++)
            {
                affiche_enreg(buf.tab[k]);
            }
        }
        else
        {
            printf("\n ce bloc n'existe pas \n");
        }

    }

}

void affichage_bloc2(LOVbarC F,int *i) //affichier un seul bloc lovbarc
{
    Buffer_liste buf;
    if(F.file!=NULL)
    {
        Lire_Dir_LOVbarC(F,*i,&buf);
        printf("\nLe contenue du bloc %d :%s",*i,buf.tab);
        *i=buf.suiv;
    }
}
void affichage_bparb2(LOVbarC F)  /// afficher bloc par bloc lovbarc
{
    int i=entete(F,1);
    if(F.file!=NULL)
    {
        printf(" \n===============================================================DEBUT AFFICHAGE =============================================================\n");
        while(i!=NULL)
        {
            affichage_bloc2(F,&i);
            printf(" \n////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        }
    }
}
void affichage_bloc2_LOVC(LOVC F,int *i) //affichier un seul bloc
{
    LOVCbloc buf;
    if(F.file!=NULL)
    {
        Lire_Dir_LOVC(F,*i,&buf);
        printf("\nLe contenue du bloc %d :%s",*i,buf.tab);
        *i=buf.suiv;
    }
}

void affichage_bparb2_LOVC(LOVC F)  /// afficher bloc par bloc lovc
{
    int i=entete_LOVC(F,1);
    if(F.file!=NULL)
    {
        while(i!=NULL)
        {
            affichage_bloc2_LOVC(F,&i);
        }
    }
}
void affich_bloc_TOVC(TOVC F, int *i)  // afficher un bloc TOVC
{

    Tbloc buf;
    if(F.fichier!=NULL)
    {
        Lire_Dir_TOVC(F,*i,&buf);
        printf("\nLe contenue du bloc %d :%s",*i,buf.chaine);
        (*i)=(*i)+1;
    }

}
void affichage_bparb_TOVC(TOVC F) // affichage bloc par bloc TOVC
{
    int i=1;

    if(F.fichier!=NULL)
    {
        printf(" nb bloc = %d\n",entete_TOVC(F,1));
        while(i<=entete_TOVC(F,1))
        {
            affich_bloc_TOVC(F,&i);

        }
    }

}



void affiche_art(TOVC F)
{

    Buffer tbuf;
    int bloc=1,pos=0,taille;
    char taille_char[5];
    char chaine[b1];
    if(F.fichier!=NULL)
    {

        int nb_bloc = entete_TOVC(F,1);

        if(nb_bloc!=0)
        {
            Lire_Dir_TOVC(F,1,&tbuf);
        }
        while(bloc <=nb_bloc)
        {
            recuperer_chaine_TOVC(&F,4,&bloc,&pos,taille_char,&tbuf);
            taille_char[4]='\0';
            taille=atoi(taille_char);
            recuperer_chaine_TOVC(&F,taille,&bloc,&pos,chaine,&tbuf);
            if(bloc!=nb_bloc+1)
                affichage_article(chaine,taille);
        }
    }
    else
    {
        printf(" \n le fichier n'existe pas \n");
    }

}
void affiche_livre(TOVC F)   /// afficher le fichier livre ouvrage par ouvrage
{

    Buffer tbuf;
    int bloc=1,pos=0,taille;
    char taille_char[5];
    char chaine[b1];
    if(F.fichier!=NULL)
    {
        int nb_bloc = entete_TOVC(F,1);
        if(nb_bloc!=0)
        {
            Lire_Dir_TOVC(F,1,&tbuf);
        }
        while(bloc <=nb_bloc)
        {
            recuperer_chaine_TOVC(&F,4,&bloc,&pos,taille_char,&tbuf); ///recuperer la taille e l'ouvrage
            taille_char[4]='\0';

            taille=atoi(taille_char);
            recuperer_chaine_TOVC(&F,taille,&bloc,&pos,chaine,&tbuf); /// lire l'ouvrage
            if(bloc!=nb_bloc+1)
            {
                affichage_article_liv(chaine,taille);   ///afficher l'ouvrage
            }
        }
    }
    else
    {
        printf(" _n le fichier n'existe pas \n");
    }
}
void recuperer_chaine_TOVC(TOVC *F,int n, int *i, int *j, char chaine[],Tbloc *buf) //
{
    int k=0;
    sprintf(chaine,"%s","");

    for(k=0; k<n; k++)                  // boucle de n itérations correspondant a la longueur de la chaine
    {
        // indice de parcours de la chaine resultata et j celui du tableau
        if((*j)<=Taille_Bloc-1 && buf->chaine[(*j)]!='\0') // si le kièmem caractère de la chaine correspondant au j ime car du buffer  est toujour dans le bloc i et le bloc tjr contient des information
        {
            // le caractère 99 correspond a la fin de la chaine dans le tableau
            chaine[k]=buf->chaine[(*j)];   // recuperation du caractère dans la position k de la chaine
            (*j)++;                      // deplacement d'une position dans le buffer
        }
        else                             // si le k ièeme caractère a recuperer sort du buffer
        {
            (*i)=(*i)+1;

            if(*i>entete_TOVC(*F,1))
            {
                ;
                break;
            }
            // on passe au suivant du bloc i dans la liste
            Lire_Dir_TOVC(*F,(*i),buf);
            // lecture
            chaine[k]=buf->chaine[0];       // recuperation du premier caractère du tableau de carractère correspondant au ka ième car de la chaine
            (*j)=1;                      //positionnement eu second caractère dans le nouveau buffer
        }
    }
    chaine[k]='\0';
}
// fin de la chaine obtenue
void recuperer_chaine(LOVbarC *F,int n, int *i, int *j, char chaine[],Buffer_liste *buf) //
{

    int k=0;
    sprintf(chaine,"%s","");

    for(k=0; k<n; k++)                  // boucle de n itérations correspondant a la longueur de la chaine
    {
        // indice de parcours de la chaine resultata et j celui du tableau
        if((*j)<=b1 && buf->tab[(*j)]!='\0') // si le kièmem caractère de la chaine correspondant au j ime car du buffer  est toujour dans le bloc i et le bloc tjr contient des information
        {
            // le caractère 99 correspond a la fin de la chaine dans le tableau
            chaine[k]=buf->tab[(*j)];   // recuperation du caractère dans la position k de la chaine
            (*j)++;                      // deplacement d'une position dans le buffer
        }
        else                             // si le k ièeme caractère a recuperer sort du buffer
        {
            (*i)=buf->suiv;

            if(*i==NULL)
            {
                break;
            }
            // on passe au suivant du bloc i dans la liste
            Lire_Dir_LOVbarC(*F,(*i),buf);
            // lecture
            chaine[k]=buf->tab[0];       // recuperation du premier caractère du tableau de carractère correspondant au ka ième car de la chaine
            (*j)=1;                      //positionnement eu second caractère dans le nouveau buffer
        }
    }
    chaine[k]='\0';
    // fin de la chaine obtenue
}
void recuperer_chaine_LOVC(LOVC *F,int n, int *i, int *j, char chaine[],LOVCbloc *buf) //
{

    int k=0;
    sprintf(chaine,"%s","");

    for(k=0; k<n; k++)                  // boucle de n itérations correspondant a la longueur de la chaine
    {
        // indice de parcours de la chaine resultata et j celui du tableau
        if((*j)<=b1 && buf->tab[(*j)]!='\0') // si le kièmem caractère de la chaine correspondant au j ime car du buffer  est toujour dans le bloc i et le bloc tjr contient des information
        {
            // le caractère 99 correspond a la fin de la chaine dans le tableau
            chaine[k]=buf->tab[(*j)];   // recuperation du caractère dans la position k de la chaine
            (*j)++;                      // deplacement d'une position dans le buffer
        }
        else                             // si le k ièeme caractère a recuperer sort du buffer
        {
            (*i)=buf->suiv;

            if(*i==NULL)
            {
                break;
            }
            // on passe au suivant du bloc i dans la liste
            Lire_Dir_LOVC(*F,(*i),buf);
            // lecture
            chaine[k]=buf->tab[0];       // recuperation du premier caractère du tableau de carractère correspondant au ka ième car de la chaine
            (*j)=1;                      //positionnement eu second caractère dans le nouveau buffer
        }
    }
    chaine[k]='\0';
    // fin de la chaine obtenue
}
void remplir_livre(TOVC *F, int *bloc, int *pos, char ouvrage[],Buffer * buf )     /// remplir le fichier livres
{

    for(int i =0 ; i<strlen(ouvrage); i++)  /// verefier si le buffer est plein et le metre dans le fichier
    {

        if(Taille_Bloc-1==*pos)
        {
            buf->chaine[*pos]='\0';
            Alloc_Bloc_TOVC(F);
            Aff_Entete_TOVC(F,2,*pos);
            Ecrire_Dir_TOVC(F,*bloc,buf);
            C51++;
            (*bloc)++;
            *pos=0;
        }



        buf->chaine[*pos]=ouvrage[i];

        (*pos)++;
    }
    buf->chaine[*pos]='\0';
}
void remplir_memoire(LOVC *F,char ouvragee[b1],int * bloc,int *pos, Buffer_LOVC *buf )      /// remplir le fichier memoire
{
    int i ;
    for(i =0 ; i != strlen(ouvragee); i++)
    {
        if(b1-1==*pos) /// verefier si le buffer est plein et le metre dans le fichier
        {
            Alloc_Bloc_LOVC(F,*bloc);
            buf->suiv=(*bloc)+1;

            Aff_Entete_LOVC(F,2,entete_LOVC(*F,2)+(*pos));
            buf->suiv=(*bloc)+1;

            buf->tab[*pos]='\0';
            Ecrire_Dir_LOVC(F,*bloc,*buf);
            C52++;
            (*bloc)++;
            (*pos)=0;
        }
        buf->tab[*pos]=ouvragee[i];
        (*pos)++;

    }
    buf->tab[*pos]='\0';
}

void remplir_articl(TOVC *F, int *bloc, int * pos, char ouvrage[], Tbloc *buf )      // remplir le fichier article
{
    for(int i =0 ; i<strlen(ouvrage); i++)
    {
        //printf(" i = %d\n",i);
        if(Taille_Bloc-1==*pos)  /// verefier si le buffer est plein est le metre dans le fichier
        {
            //printf(" ecriture \n");
            Alloc_Bloc_TOVC(F);
            buf->chaine[*pos]='\0';
            Aff_Entete_TOVC(F,2,*pos);
            Ecrire_Dir_TOVC(F,*bloc,buf);
            C53++;
            (*bloc)++;
            *pos=0;
        }



        buf->chaine[*pos]=ouvrage[i];// remplir le buffer
        (*pos)++;
    }
    buf->chaine[*pos]='\0';

}


void remplir_periodique(TOF *F, int *bloc,int *pos,TOF_Bloc *buf,enregistrement enrg)     /// remplir le fichier periodique
{
    if((*pos)== Taille_Bloc_TOF)   // verefier si le buffer est plein et le metre dans le ficher
    {
        Alloc_bloc_TOF(F);
        Aff_Entete_TOF(F,2,*pos);
        buf->nb_enreg_inserer=*pos;
        Ecrire_Dir_TOF(F,*bloc,*buf);
        C54++;
        (*bloc)++;
        (*pos)=0;
    }

    buf->tab[(*pos)]=enrg; /// remplir le buffer

    *pos=*pos+1;

}


void cree_fichier(LOVbarC F)
{
    Buffer_liste buf;
    TOVC F_art,F_liv;//F1 article ,F3 livre
    Buffer buf_art,buf_liv;
    LOVC F_mem;//F2 memoires
    Buffer_LOVC buf_mem;
    TOF F_per;//F4 periodique
    TOF_Bloc buf_per;
    Aff_Entete_TOVC(&F_liv,2,0);
    Aff_Entete_TOVC(&F_liv,1,0);
    //Aff_Entete_LOVC(&F_mem,1,0):
   // Aff_Entete_LOVC(&F_mem,2,0):
    ouvrire_TOF(&F_per,"periodiques.bin",'n');
    ouvrire_LOVC(&F_mem,"memoires.bin",'n');
    ouvrire_TOVC(&F_liv,"livres.bin",'n');
    ouvrire_TOVC(&F_art,"articles.bin",'n');
    int i=0,bloc=0;//indices ouvrages.bin
    int pos_mem=0,bloc_mem=1;//indices memoires.bin
    int pos_per=0,bloc_per=1;//indices periodique.bin
    int pos_liv=0,bloc_liv=1;//indices livres.bin
    int pos_art=0,bloc_art=1;//indices articles.bin0
    bloc= entete(F, 1);
    int n=0;
    //initialisation des variables de cout
    C51=0;
    C52=0;
    C53=0;
    C54=0;
    if(F.file!=NULL)
    {


        if(bloc!=NULL)
        {

            Lire_Dir_LOVbarC(F,bloc,&buf);
            //incrementation des variables de cout
            C51++;
            C52++;
            C53++;
            C54++;
        }
        enregistrement enrg;

        while(bloc!=NULL)
        {
            int temp_bloc=bloc;//variable booleen pour les variables des cout
            char taille_char[5];
            recuperer_chaine(&F,4,&bloc,&i,taille_char,&buf);
            if(bloc!=NULL){
            int delta_bloc=bloc-temp_bloc;
            //incrementation des variables de cout
            C51+=delta_bloc;
            C52+=delta_bloc;
            C53+=delta_bloc;
            C54+=delta_bloc;
            }


            temp_bloc=bloc;

            int taille = atoi(taille_char);
            char ouvrage[b1];
            i-=4;
            recuperer_chaine(&F,taille+4,&bloc,&i,ouvrage,&buf);

            if(bloc!=NULL){
            int delta_bloc=bloc-temp_bloc;
            //incrementation des variables de cout
            C51+=delta_bloc;
            C52+=delta_bloc;
            C53+=delta_bloc;
            C54+=delta_bloc;
            }
            if (bloc==NULL)
            {
                break;
            }

            switch(detectType(ouvrage)) ///10detectType(ouvrage)
            {
            case 1://cas d un article

                del_type_cote(ouvrage);
                remplir_articl(&F_art,&bloc_art,&pos_art,ouvrage,&buf_art);

                break;
            case 2://cas d un periodique

                remplir_enreg(ouvrage,&enrg);//del type est dans remplire enreg
                remplir_periodique(&F_per,&bloc_per,&pos_per,&buf_per,enrg);
                break;
            case 3://cas d un livre

                del_type(ouvrage);
                remplir_livre(&F_liv,&bloc_liv,&pos_liv,ouvrage,&buf_liv);

                break;
            case 4://cas d une memoire
                del_type(ouvrage);
                Aff_Entete_LOVC(&F_mem,1,1);

                remplir_memoire(&F_mem,ouvrage,&bloc_mem,&pos_mem,&buf_mem);
                break;

            }
        }
        if ((pos_art!=0)&&(pos_art<Taille_Bloc))  // le cas ou on est arriver au dernier bloc est il n'est pas plein alors il faur l'inserer
        {
            Alloc_Bloc_TOVC(&F_art);
            Aff_Entete_TOVC(&F_art,2,pos_art);
            Ecrire_Dir_TOVC(&F_art,bloc_art,&buf_art);
            C53++;//incrementaiton variable de cout

        }



        if ((pos_liv!=0)&&(pos_liv<Taille_Bloc)) // le cas ou on est arriver au dernier bloc est il n'est pas plein alors il faur l'inserer
        {
            Alloc_Bloc_TOVC(&F_liv);

            buf_liv.chaine[pos_liv]='\0';
            Aff_Entete_TOVC(&F_liv,2,pos_liv);

            Ecrire_Dir_TOVC(&F_liv,bloc_liv,&buf_liv);
            C51++;//incrementaiton variable de cout

        }

        if ((pos_mem!=0)&&(pos_mem<b1)) // le cas ou on est arriver au dernier bloc est il n'est pas plein alors il faur l'inserer
        {
            Alloc_Bloc_LOVC(&F_mem,bloc_mem);

            Aff_Entete_LOVC(&F_mem,1,1);
            Aff_Entete_LOVC(&F_mem,2,entete_LOVC(F_mem,2)+pos_mem);
            int n ;
            buf_mem.suiv=NULL;
            Ecrire_Dir_LOVC(&F_mem,bloc_mem,buf_mem );
            C52++;//incrementaiton variable de cout

        }
        if(pos_mem==0)
        {
            Lire_Dir_LOVC(F_mem,bloc_mem-1,&buf_mem);
            C52++;//incrementaiton variable de cout

            buf_mem.suiv=NULL;
            Ecrire_Dir_LOVC(&F_mem,bloc_mem-1,buf_mem);
            C52++;//incrementaiton variable de cout

        }

        if(pos_per!=0) // le cas ou on est arriver au dernier bloc est il n'est pas plein alors il faur l'inserer
        {
            Alloc_bloc_TOF(&F_per);
            buf_per.nb_enreg_inserer=pos_per;

            Aff_Entete_TOF(&F_per,2,pos_per);

            Ecrire_Dir_TOF(&F_per,bloc_per,buf_per);
            C54++;//incrementaiton variable de cout


        }
// Fermer les fichier
        Fermer_TOVC(&F_art);

        Fermer_TOVC(&F_liv);
        fermer_TOF(&F_per);
        Fermer_LOVC(&F_mem);
        Fermer_LOVbarC(&F);
    }
    printf("\nLe cout de la creation du fichier livres.bin apartir du fichier ouvrages.bin C51 = %d .\n",C51);
    printf("\nLe cout de la creation du fichier memoires.bin apartir du fichier ouvrages.bin C52 = %d .\n",C52);
    printf("\nLe cout de la creation du fichier articles.bin apartir du fichier ouvrages.bin C53 = %d .\n",C53);
    printf("\nLe cout de la creation du fichier periodiques.bin apartir du fichier ouvrages.bin C54 = %d .\n",C54);
    system("pause");


}
void Affichage_TOF(TOF F) /// afficher le fichier TOF
{
    int nb_bloc=entete_TOF(F,1);
    TOF_Bloc buf;
    if(F.fichier!=NULL)
    {

        int dernier_pos=entete_TOF(F,2);
        for(int i =1; i!=nb_bloc+1; i++)
        {
            Lire_Dir_TOF(F,i,&buf);

            for(int ind = 0  ; ind!=buf.nb_enreg_inserer ; ind++)
            {
                //if( i==nb_bloc && ind==dernier_pos  )
                //    break;
                printf("\n////////////////////////////////////////////////////////////\n");
                affiche_enreg(buf.tab[ind]);


            }
        }
    }
    else
    {
        printf(" \n le fichier n'existe pas \n");
    }

}
void remplir_enreg(char ouvrage[b1],enregistrement *enr)  /// remplir un enregistrement a partir d'un article ou bien ouvrage
{
    del_type(ouvrage);

    int i=4,pos=0;
    char cle[5];
    for(pos=0; pos!=4; pos++) ///recuperer la clee
    {
        enr->cle[pos]=ouvrage[i];
        i++;
    }
    enr->cle[4]='\0';

    for(pos=0; pos!=t1-1; pos++) /// recuperer le titre
    {
        enr->titre[pos]=ouvrage[i];
        i++;
    }
    enr->titre[t1-1]='\0';
    for(pos=0; pos!=t1-1; pos++)
    {
        enr->auteurs[pos]=ouvrage[i];
        i++;
    }
    enr->auteurs[t1-1]='\0';
    for(pos=0; pos!=4; pos++) /// recuperer l'anne de publication
    {
        enr->anne_pub[pos]=ouvrage[i];
        i++;
    }
    enr->anne_pub[4]='\0';
    enr->dispo[0]=ouvrage[i];
    enr->dispo[1]='\0';


}


void affiche_enreg(enregistrement enr)   /// afficher un enregistrement
{
    printf("\nAffichage de enregistrement");
    printf("\nLa cle : %s",enr.cle);
    printf("\nL'auteur: %s",enr.auteurs);
    printf("\nLe titre: %s",enr.titre);
    printf("\nL'annee: %s",enr.anne_pub);
    printf("\nDisponibilite: %s",enr.dispo);
}

void insertion_Lovbarc(LOVbarC *F, int clee, char ouvrage[])  /// inserer dans un fichier LOV/C
{

    if(F->file!=NULL)
    {
        int pos,bloc,trouv;
        printf("\nCout de la recherche dans l'insertion:");
        recherche(F,clee,&bloc,&pos,&trouv);
        C3=C2;//initialisation la variable du cout
        if(trouv!=1)
        {
            Buffer_liste buf;
            Aff_Entete(F,2,strlen(ouvrage)+entete(*F,2)); // modification du nb caractere inserer
            if(bloc!=1 && pos ==0 )
            {
                Lire_Dir_LOVbarC(*F,bloc-1,&buf); /// si on est dans le cas que le bloc  i-1 n'est pas remplir au max et la recharche nus positionne sur l'indice 0 du bloc 2
                C3++;//incrementation la variable du cout
                if(strlen(buf.tab)+strlen(ouvrage)<b1-1)
                {
                    pos=strlen(buf.tab);
                    bloc--;

                }
            }
            Lire_Dir_LOVbarC(*F,bloc,&buf);
            C3++;//incrementation la variable du cout
            char reste[b1];
            char deb[b1];
            strcpy(deb,"");

            recup_reste_ouvrage(pos,buf.tab,reste); ///recuperer le reste du buffer a partir de la position pos

            strncat(deb, buf.tab,pos);   /// recuperer le debut du buf de la case 0 a la case pos


            if(strlen(buf.tab) + strlen(ouvrage)< b1-1 ) // cas ou on insere dans le meme bloc et il n'aura pas de probleme de la taille
            {


                sprintf(buf.tab,"%s%s%s",deb,ouvrage,reste);
                if(entete(*F,1)==0)
                {
                    Aff_Entete(F,1,1);
                    Aff_Entete(F,4,1);
                    buf.suiv=NULL;
                }
                Ecrire_Dir_LOVbarC(F,bloc,buf);
                C3++;//incrementation la variable du cout

            }

            else
            {
                if(strlen(deb)+strlen(ouvrage)< b1-1) // cas ou on est positioner dans la milieu du bloc et on peut ecrire l'article en plus il faut metre le reste du bloc i dans un nouveau bloc
                {


                    int bloc_ins= entete(*F,4)+1;
                    int suiv=buf.suiv;
                    buf.suiv=bloc_ins;
                    sprintf(buf.tab,"%s%s",deb,ouvrage);
                    Ecrire_Dir_LOVbarC(F,bloc,buf);
                    C3++;//incrementation la variable du cout
                    sprintf(buf.tab,"%s",reste);
                    buf.suiv=suiv;
                    Aff_Entete(F,4,bloc_ins);
                    Ecrire_Dir_LOVbarC(F,bloc_ins,buf);
                    C3++;//incrementation la variable du cout
                }
                else
                {
                    if(strlen(ouvrage)+strlen(reste)< b1-1) /// cas ou on ne peut pas inserer l'article dans le bloc a cause d'un probleme de taille et nous pouvons ecrire le reste et 'article dans unseul  nouveau bloc
                    {
                        int suiv=buf.suiv;
                        int bloc_ins= entete(*F,4)+1;
                        sprintf(buf.tab,"%s",deb);

                        buf.suiv=bloc_ins;
                        Ecrire_Dir_LOVbarC(F,bloc,buf);
                        C3++;//incrementation la variable du cout
                        sprintf(buf.tab,"%s%s",ouvrage,reste);
                        buf.suiv=suiv;

                        Ecrire_Dir_LOVbarC(F,bloc_ins,buf);
                        C3++;//incrementation la variable du cout

                        Aff_Entete(F,4,bloc_ins);
                    }
                    else   /// le cas ou il faut ne peut pas inserer le reste et l'article dans un meme nouveau bloc a cause du depassement de la  taille alors  on ecrit l'article et le reste dans deux deffirent bloc
                    {
                        int suiv=buf.suiv;
                        int bloc_ins= entete(*F,4)+1;
                        int suiv2=bloc_ins+1;
                        sprintf(buf.tab,"%s",deb);
                        buf.suiv=bloc_ins;
                        Ecrire_Dir_LOVbarC(F,bloc,buf);
                        C3++;//incrementation la variable du cout
                        sprintf(buf.tab,"%s",ouvrage);
                        buf.suiv=suiv2;
                        Ecrire_Dir_LOVbarC(F,bloc_ins,buf);
                        C3++;//incrementation la variable du cout
                        sprintf(buf.tab,"%s",reste);
                        buf.suiv=suiv;
                        Ecrire_Dir_LOVbarC(F,bloc_ins+1,buf);
                        C3++;//incrementation la variable du cout
                        Aff_Entete(F,4,bloc_ins+1);
                    }
                }
            }
        }
        else
        {
            printf("\n l'ouvrage existe deja \n");
        }

        Fermer_LOVbarC(F);

    }
    else  /// cas de fichier n'existe pas
    {
        ouvrire_LOVbarC(F,"ouvrages.bin",'n');
        Aff_Entete(F,1,1);
        Aff_Entete(F,2,strlen(ouvrage));
        Aff_Entete(F,3,0);
        Aff_Entete(F,4,1);
        Buffer_liste buf;
        sprintf(buf.tab,"%s",ouvrage);
        buf.suiv=NULL;
        Ecrire_Dir_LOVbarC(F,1,buf);
        C3++;//incrementation la variable du cout
        Fermer_LOVbarC(F);
    }

    printf("\nLe cout de l'insertion de la cle %d dans le fichier ouvrages.bin C3 = %d .\n",clee,C3);
    system("pause");
}
void recup_reste_ouvrage(int pos,char ouvrage[b1], char reste[b1]) ///pour recuperer le reste d'un bloc a partir de la position pos
{
    int i=0;
    while(ouvrage[pos]!='\0')
    {
        reste[i]=ouvrage[pos];
        pos++;
        i++;
    }
    reste[i]='\0';

}
void recherche_DICO_TOF(TOF F, int clee, int *bloc, int *pos, int *trouv)
{
    C6=0;//initialisation de la variable
    if(F.fichier!=NULL)
    {

        *trouv=0;
        int stop=0;
        TOF_Bloc buf;
        int bloc_inf=1;
        int bloc_sup=entete_TOF(F,1);
        int bloc_milieu=(bloc_sup+bloc_inf)/2;
        *bloc=bloc_milieu;
        enregistrement enr;
        int dtop=0;
        while(!(*trouv) && bloc_inf<=bloc_sup && stop!=1) //recherche dico du bloc
        {

            Lire_Dir_TOF(F,*bloc,&buf);
            C6++;//incrementation de la variable
            int indice_inf=0;
            int indice_sup=buf.nb_enreg_inserer-1;
            int indice_milieu=(indice_inf+indice_sup)/2;
            *pos=indice_milieu;
            if(clee>=atoi(buf.tab[indice_inf].cle) && clee<=atoi(buf.tab[indice_sup].cle))
            {
                while(indice_inf<=indice_sup && !(*trouv)) //recherche dico dans le buffer
                {
                    enr=buf.tab[*pos];
                    int cle_enr=atoi(enr.cle);
                    if (cle_enr==clee)
                    {
                        *trouv=1;


                    }
                    else if(clee>cle_enr)
                    {
                        indice_inf=indice_milieu+1;
                        indice_milieu=(indice_inf+indice_sup)/2;
                        *pos=indice_milieu;
                    }
                    else
                    {
                        indice_sup=indice_milieu-1;
                        indice_milieu=(indice_inf+indice_sup)/2;
                        *pos=indice_milieu;
                    }
                    if(indice_inf>indice_sup)
                    {
                        *pos=indice_inf;
                        stop=1;
                    }
                }
            }
            if (!(*trouv) && stop != 1)
            {
                if(atoi(buf.tab[0].cle)<clee)
                {
                    bloc_inf=bloc_milieu+1;
                    bloc_milieu=(bloc_inf+bloc_sup)/2;
                    *bloc=bloc_milieu;
                }
                else
                {
                    bloc_sup=bloc_milieu-1;
                    bloc_milieu=(bloc_inf+bloc_sup)/2;
                    *bloc=bloc_milieu;
                }
            }
        }
        if(bloc_inf>bloc_sup  )
        {
            *bloc=bloc_inf;
            *pos=0;
        }
    }
    else
    {
        printf("\nFichier n'existe pas");
    }
    printf("\nLe cout de la recherche dico de la cle %d dans  periodiques.bin C6 = %d .\n",clee,C6);
    system("pause");
}
void affichage_index(Index F)
{
    printf("\nAffichag dans la teble d'index: \n");

    if(F.fichier!=NULL)
    { int nb_bloc=entete_Index(F,1);
       Index_Bloc buf;
       printf(" nbbloc = %d\n",nb_bloc);
        int dernier_pos=entete_Index(F,2);
        for(int i =1; i!=nb_bloc+1; i++)
        {
            Lire_Dir_Index(F,i,&buf);

            for(int ind = 0  ; ind<buf.nb_enreg_inserer ; ind++)
            {printf("\n////////////////////////////////////////////////////////////\n");
                printf("\nLa Cle : %s .",buf.tab[ind].cle);
                printf("\nLe Bloc : %d .",buf.tab[ind].bloc);
                printf("\nLa pos : %d .",buf.tab[ind].pos);


            }
        }
    }
    else
    {
        printf(" \n le fichier n'existe pas \n");
    }


}

void recherche_index(int clee)
{
    C8=0;//initialisation de la variable du cout
    Index F;
    ouvrire_Index(&F,"Index_Periodiques.bin",'a');
    if(F.fichier!=NULL)
    {


        int stop=0,trouv=0,bloc,pos;
        Index_Bloc buf;
        int bloc_inf=1;
        int bloc_sup=entete_Index(F,1);
        int bloc_milieu=(bloc_sup+bloc_inf)/2;
        bloc=bloc_milieu;
        enregistrement enr;

        while(!(trouv) && bloc_inf<=bloc_sup && stop!=1) //recherche dico du bloc
        {

            Lire_Dir_Index(F,bloc,&buf);
            C8++;//incrementation de la variable du cout
            int indice_inf=0;
            int indice_sup=buf.nb_enreg_inserer-1;
            int indice_milieu=(indice_inf+indice_sup)/2;
            pos=indice_milieu;
            if(clee>=atoi(buf.tab[indice_inf].cle) && clee<=atoi(buf.tab[indice_sup].cle))
            {
                while(indice_inf<=indice_sup && !(trouv)) //recherche dico dans le buffer
                {

                    int cle_enr=atoi(buf.tab[pos].cle);
                    if (cle_enr==clee)
                    {
                        trouv=1;


                    }
                    else if(clee>cle_enr)
                    {
                        indice_inf=indice_milieu+1;
                        indice_milieu=(indice_inf+indice_sup)/2;
                        pos=indice_milieu;
                    }
                    else
                    {
                        indice_sup=indice_milieu-1;
                        indice_milieu=(indice_inf+indice_sup)/2;
                        pos=indice_milieu;
                    }
                    if(indice_inf>indice_sup)
                    {
                        pos=indice_inf;
                        stop=1;
                    }
                }
            }
            if (!(trouv) && stop != 1)
            {
                if(atoi(buf.tab[0].cle)<clee)
                {
                    bloc_inf=bloc_milieu+1;
                    bloc_milieu=(bloc_inf+bloc_sup)/2;
                    bloc=bloc_milieu;
                }
                else
                {
                    bloc_sup=bloc_milieu-1;
                    bloc_milieu=(bloc_inf+bloc_sup)/2;
                    bloc=bloc_milieu;
                }
            }
        }
        if(bloc_inf>bloc_sup  )
        {
            bloc=bloc_inf;
            pos=0;
        }


        TOF F_tof;
        if(trouv==1)
        {
            bloc = buf.tab[pos].bloc;
            int position = buf.tab[pos].pos;
            ouvrire_TOF(&F_tof,"periodique.bin",'a');
            if(entete_TOF(F_tof,1) >= bloc  )  /// verefier si le bloc existe
            {
                TOF_Bloc buf;
                Lire_Dir_TOF(F_tof,bloc, &buf );
                if(position <= buf.nb_enreg_inserer)
                {
                    printf(" \n affichage de l'enregistrement de la clee rechercher  : ");
                    affiche_enreg(buf.tab[position]);
                }
            }

        }
        else
        {
            printf("\nCle n'existe pas");
        }

    }
    printf("\nLe cout de la recherche de la clee %d apartir de la table d'index C8 = %d .\n",clee,C8);
    system("pause");


}
void cree_table_index(TOF F)
{
    C7=0;//initialisation de la variable de cout
    if (F.fichier!=NULL)
    {
        Index F_index;
        ouvrire_Index(&F_index,"Index_Periodiques.bin",'n');
        int nb_bloc=entete_TOF(F,1);
        int ind=0;//indice pour parcourire la table d'index
        int num_bloc=1;//indice pour parcourire les bloc d'index
        TOF_Bloc buf;
        Index_Bloc Ind_buf;
        for (int i=1; i<=nb_bloc; i++)
        {
            Lire_Dir_TOF(F,i,&buf);
            C7++;//incermentation du variable du cout
            for (int j=0; j<buf.nb_enreg_inserer;j++)
            {

                if (ind == Taille_Index){
                    Alloc_bloc_Index(&F_index);
                    Ind_buf.nb_enreg_inserer=ind;

                    Aff_Entete_Index(&F_index,2,ind-1);//modifier le dernier indice
                    Ecrire_Dir_Index(&F_index,num_bloc,Ind_buf);
                    C7++;//incermentation du variable du cout
                    ind=0;
                    num_bloc++;

                }
                sprintf(Ind_buf.tab[ind].cle,"%s",buf.tab[j].cle);
                Ind_buf.tab[ind].bloc=i;
                Ind_buf.tab[ind].pos=j;
                ind ++;


            }
        }
        if (ind!=0){//traitement du dernier bloc

            Alloc_bloc_Index(&F_index);

            Aff_Entete_Index(&F_index,2,ind-1);//modifier le dernier indice
            Ind_buf.nb_enreg_inserer=ind;
            Ecrire_Dir_Index(&F_index,num_bloc,Ind_buf);
            C7++;//incermentation du variable du cout
        }
       fermer_Index(&F_index);
    }
    else
    {
        printf("\nFichier n'existe pas!");
    }
    printf("\nLe cout de la creation de la table d'index apartir du  fichier periodiques.bin C7 = %d .\n",C7);
    system("pause");
}

