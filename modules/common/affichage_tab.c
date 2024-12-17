#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void affichage_tab(char** mon_argv,int nombre_de_mot){
    for (int i = 0; i <= nombre_de_mot; i++)
        {
            printf("argv[%d] = %s\n",i,mon_argv[i]);
        }
}