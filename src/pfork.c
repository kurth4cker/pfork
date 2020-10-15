#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
int umask_val = 022;
extern char* logfile = "pfork.out";
extern char* infile = "pfork.in";

extern int silent=1;

extern void set_umask(int value)
{
    umask_val = value;
}

extern void skeleton_daemon()
{
    pid_t pid;

    /* Fork off the parent process */
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* On success: The child process becomes session leader */
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    /* Catch, ignore and handle signals */
    //TODO: Implement a working signal handler */
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    /* Fork off for the second time*/
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);
    if(silent)
    {
        fprintf (stderr, "Daemon started:\t[%d]\n",getpid ()+1);
        int fdin = open(infile, O_RDONLY | O_CREAT);
        int fdout = open(logfile, O_WRONLY | O_CREAT);
        int fderr = open(logfile, O_WRONLY | O_CREAT);
    
        /* Set in, out and err to file*/
        close(0);
        dup(fdin);
        close(fdin);
        close(1);
        dup(fdout);
        close(2);
        dup(fderr);
        close(fdout);
    }
 
    /* Set new file permissions */
    umask(umask_val);

}
