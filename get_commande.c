#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void  get_commande(char * commande){
    fgets(commande,255,stdin);
    return ;
}
