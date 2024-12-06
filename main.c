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

int get_nombre_de_mot(int nombre,char * commande, int taille_de_commande){
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

void remplir_mon_tab(char * commande,char*mon_argv[],int nombre_de_mot){
    mon_argv[0]=strtok(commande," ");
        int i=1;
        do
        {
            mon_argv[i]=strtok(NULL," ");
            i++;
        } while (i<=nombre_de_mot);
        
        mon_argv[nombre_de_mot+1]=0;
        return ;
}

void affichage_tab(char** mon_argv,int nombre_de_mot){
    for (int i = 0; i <= nombre_de_mot; i++)
        {
            printf("argv[%d] = %s\n",i,mon_argv[i]);
        }
}

int main(){
    // int firstWhileCompteur = 0;
    while (1)
    {
        // printf("1st while compteur : %d\n",firstWhileCompteur);
        // firstWhileCompteur++;
        char commande[255];memset(commande,0,255);
        get_commande(commande);

        int nombre_de_mot=0;
        nombre_de_mot = get_nombre_de_mot(nombre_de_mot,commande,strlen(commande));
        
        printf("nombre de mot dans mon fgets : %d\n",nombre_de_mot);

        char* mon_argv[nombre_de_mot+1];
        remplir_mon_tab(commande,mon_argv,nombre_de_mot);

        affichage_tab(mon_argv,nombre_de_mot);

        int i=0;
        int pid;
        
        while (i!=1)
        {
            switch (pid=fork())
            {
            case -1:
                printf("error\n");
                break;
            case 0:
                printf("Le PID de l'enfant %d\n",getpid());
                int check_error = execvp(mon_argv[0],mon_argv);perror("execvp() de l'enfant");
                if (check_error==-1){
                    printf("error du execvp\n");
                    exit(EXIT_FAILURE);
                    break;
                }

                
                break;
            
            default:
                // j++;
                waitpid(pid,NULL,0);// si j'enleve ce wait le ls de l'enfant va s'afficher dans mon terminal apres la fin de mon programme
                printf("Le PID du parent %d et celui de l'enfant %d\n",getpid(),pid);
                // i++;
                printf("i = %d\n",i);
                // execvp(mon_argv[j],mon_argv);perror("execvp");
                break;
            }
            i++;
        }
        
    }
}