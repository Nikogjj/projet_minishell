#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void  get_commande(char * commande){
    char path[255];memset(path,0,255);
    printf("\033[31m%s$\033[00m ",getcwd(path,255));
    fgets(commande,255,stdin);
    return ;
}
