#include <pfork.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

extern int silent;

int main(int argc, char *argv[]) {
    char *args[argc];
    
    // Copy command line arguments to args array
    for (int i = 1; i < argc; i++) {
        args[i - 1] = argv[i];
    }
    args[argc - 1] = NULL; // Null-terminate the array
    
    //Verbose output. Don't write file
    silent = 0;
    char *silent_env = getenv("SILENT");
    if (silent_env != NULL && strcmp(silent_env, "1") == 0) {
        silent = 1;
    }
    
    skeleton_daemon();
    
    // Create a child process
    pid_t pid = fork();
    if (pid == -1) {
        // Error occurred
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // This is the child process
        // Execute the command directly
        execvp(args[0], args);
        
        // execvp only returns if an error occurs
        perror("execvp");
        exit(1);
    } else {
        // This is the parent process
        // Wait for the child to finish
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            // Child exited normally
            int exit_status = WEXITSTATUS(status);
            return exit_status;
        } else {
            // Child exited abnormally
            return 1;
        }
    }
}

