#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int get_nombre_de_mot(char * commande, int taille_de_commande){
    int nombre=0;
    for (int i = 0; i < strlen(commande); i++)
    {
        if (commande[i]==' ' || commande[i]=='\n')
        {
            nombre++;
        }
    }
    commande[strlen(commande)-1]=0;
    return nombre;
}