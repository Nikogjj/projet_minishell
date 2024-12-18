#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void remplir_mon_tab(char * commande,char** mon_argv,int nombre_de_mot)
{
    if (nombre_de_mot==1)
    {
        mon_argv[0]=strtok(commande," ");
        mon_argv[1]=0;
    }
    else{
        mon_argv[0]=strtok(commande," ");
        int i=1;
        do
        {
            mon_argv[i]=strtok(NULL," ");
            i++;
        } while (i<=nombre_de_mot);
        
        mon_argv[nombre_de_mot+1]=0;
    }
    
    return ;
}