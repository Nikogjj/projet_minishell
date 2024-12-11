#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


#include "global.h"


int main(){
    // int firstWhileCompteur = 0;
    while (1)
    {
        // printf("1st while compteur : %d\n",firstWhileCompteur);
        // firstWhileCompteur++;
        char commande[255];memset(commande,0,255);
        get_commande(commande);

        int nombre_de_mot=0;
        nombre_de_mot = get_nombre_de_mot(nombre_de_mot,commande,strlen(commande));
        
        printf("nombre de mot dans mon fgets : %d\n",nombre_de_mot);

        char* mon_argv[nombre_de_mot+1];
        remplir_mon_tab(commande,mon_argv,nombre_de_mot);

        affichage_tab(mon_argv,nombre_de_mot);

        int i=0;
        int pid;
        
        while (i!=1)
        {
            create_fork(i,pid,mon_argv);
            i++;
        }
        
    }
}

