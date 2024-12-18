#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int cd(char** mon_argv,int nombre_de_mot){
    // if (nombre_de_mot>2)
    // {
    //     printf("Erreur cd: trop d'arguments\n");
    //     return -1;
    // }
    
    if (chdir(mon_argv[1])==-1)
    {
        printf("Erreur cd: %s: Aucun fichier ou dossier de ce nom\n",mon_argv[1]);
        return -1;
    }  
}