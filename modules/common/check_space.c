#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void check_space(char* commande){

    for (int i = 0; i < strlen(commande); i++)
    {
        if (commande[i]==' ')
        {
                for (int j = 0; j < strlen(commande); j++)
                {
                    if (commande[j+1]==' ')
                    {
                        commande[j]=commande[j+1];
                    }
                }
        }
    }
    printf("%s\n",commande);
}