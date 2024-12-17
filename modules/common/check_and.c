#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "my_strtok.c"
#include "get_nombre_de_mot.c"
#include "remplir_mon_tab.c"
#include "affichage_tab.c"
#include "check_commande.c"


int check_and(char* commande){

    int nombre_de_mot = get_nombre_de_mot(commande,strlen(commande));
    
    char* mon_argv[nombre_de_mot+1];
    remplir_mon_tab(commande,mon_argv,nombre_de_mot);
    my_strtok(commande,"&&");


    // affichage_tab(mon_argv,nombre_de_mot);

    check_commande(mon_argv,nombre_de_mot);
    
}