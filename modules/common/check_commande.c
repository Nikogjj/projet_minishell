#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../../fonction/fonction_shell.h"
#include "create_fork.c"


void check_commande(char **mon_argv,int nombre_de_mot){

    for (int i = 0; i < nombre_de_mot; i++)
    {
        if (strcmp(mon_argv[i],"ls")==0)
        {   
            create_fork(mon_argv);
        }

        if (strcmp(mon_argv[i],"pwd")==0)
        {   
            create_fork(mon_argv);
        }

        if (strcmp(mon_argv[i],"&&")==0)
        {
            mon_argv[i]="||";
        }

    }
    if (strcmp(mon_argv[0],"cd")==0)
    {
        // mon_argv[0]="/bin/chdir";
        // create_fork(mon_argv);
        cd(mon_argv,nombre_de_mot,1);
    }
    
    for (int i = 0; i <= nombre_de_mot; i++)
    {
        // printf("mon_argv[%d] = %s\n",i,mon_argv[i]);
    }
    
}