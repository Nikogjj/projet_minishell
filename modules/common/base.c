#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "get_commande.c"
#include "split.c"
#include "check_space.c"


void start_minishell(){
        while (1)
    {
        char commande[255];memset(commande,0,255);
        get_commande(commande);
        if (strcmp(commande,"\n")==0)
        {
            
        }
        
        // check_space(commande);
        // return ;
        else if (strstr(commande,"&&")!=NULL)
        {
            split(commande,"&&");
        }
        
        else
        {
            int nombre_de_mot = get_nombre_de_mot(commande,strlen(commande));
            char* mon_argv[nombre_de_mot+1];
            printf("nombre de mot = %d\n",nombre_de_mot);
            remplir_mon_tab(commande,mon_argv,nombre_de_mot);
            check_commande(mon_argv,nombre_de_mot);
        }
    }
}