#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void cd(char** mon_argv,int nombre_de_mot,int i){
    chdir(mon_argv[i]);

}