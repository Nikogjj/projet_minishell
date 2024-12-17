#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){

    char commande[255];memset(commande,0,255);
    fgets(commande,255,stdin);
    commande[strlen(commande)-1]=0;

    my_strtok(commande,"&&");

    return 0;
}