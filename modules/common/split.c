#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "remplir_mon_tab.c"
#include "get_nombre_de_mot.c"
#include "remplir_mon_tab.c"
#include "affichage_tab.c"
#include "check_commande.c"

int split(char* commande,char* delimiteur){

    int index=0;
    char* new_commande;
    for (int i = 0; i < strlen(commande); i++)
    {
        if (commande[i]==delimiteur[0])
        {
            int compteur;
            int j =i;
            for (compteur = 0; compteur < strlen(delimiteur); compteur++)
            {
                if (commande[j]!=delimiteur[compteur])
                {
                    break;
                }
                j++;      
                int nombre_de_mot = get_nombre_de_mot(commande,strlen(commande));
                char* mon_argv[nombre_de_mot+1];
                remplir_mon_tab(commande,mon_argv,nombre_de_mot);
                check_commande(mon_argv,nombre_de_mot);
            }      
            if (compteur==strlen(delimiteur))
            {
                for (j; j!=i; j--)
                {
                    commande[j]=0;
                }
                
                new_commande=&commande[index];
                int nombre_de_mot = get_nombre_de_mot(commande,strlen(commande));
                char* mon_argv[nombre_de_mot+1];
                remplir_mon_tab(commande,mon_argv,nombre_de_mot);
                check_commande(mon_argv,nombre_de_mot);
                index=i+compteur+1;
            }
            

        }      
    }
}