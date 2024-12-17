#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void create_fork(char** mon_argv){
    int pid;
    switch (pid=fork())
            {
            case -1:
                printf("error\n");
                break;
            case 0:
                extern char **environ;

                int check_error = execvp(mon_argv[0],mon_argv);perror("execve() de l'enfant");
                if (check_error==-1){
                    printf("error du execvp\n");
                    exit(EXIT_FAILURE);
                    break;
                }

                break;
            
            default:
                waitpid(pid,NULL,0);
            break;
    }
}