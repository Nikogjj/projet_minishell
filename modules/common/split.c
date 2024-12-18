#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#include "get_nombre_de_mot.c"
#include "remplir_mon_tab.c"
#include "affichage_tab.c"
#include "check_commande.c"

int split(char* commande,char* delimiteur){
    // commande[strlen(commande)-1]=0;
    // int taille_commande=strlen(commandee);
    
    char copy_commande[255];memset(copy_commande,0,255);
    strcpy(copy_commande,commande);
    int index=0;
    char* new_commande;

    for (int i = 0; i < strlen(copy_commande); i++)
    {
        // printf("debut\n");
        // printf("delimiteur[0] %c\n",delimiteur[0]);
        // printf("fin\n");
        if (copy_commande[i]==delimiteur[0])
        {
            int compteur;
            int j =i;
            for (compteur = 0; compteur < strlen(delimiteur); compteur++)
            {
                if (copy_commande[j]!=delimiteur[compteur])
                {
                    break;
                }
                j++;      
            }      
            if (compteur==strlen(delimiteur))
            {
                for (j; j!=i-1; j--)
                {
                    commande[j]=0;
                }
                new_commande=&commande[index];
                int nombre_de_mot = get_nombre_de_mot(new_commande,strlen(new_commande));
                char* mon_argv[nombre_de_mot+1];
                remplir_mon_tab(new_commande,mon_argv,nombre_de_mot);
                check_commande(mon_argv,nombre_de_mot);
                index=i+compteur+1;
            }
        } 
    }

    new_commande=&commande[index];
    int nombre_de_mot = get_nombre_de_mot(new_commande,strlen(new_commande));
    char* mon_argv[nombre_de_mot+1];
    remplir_mon_tab(new_commande,mon_argv,nombre_de_mot);
    check_commande(mon_argv,nombre_de_mot);

}