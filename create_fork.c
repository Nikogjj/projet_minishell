#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void create_fork(int i,int pid, char** mon_argv){
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
}