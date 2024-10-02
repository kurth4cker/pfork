#include <pfork.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    char *args[argc];
    
    // Copy command line arguments to args array
    for (int i = 1; i < argc; i++) {
        args[i - 1] = argv[i];
    }
    args[argc - 1] = NULL; // Null-terminate the array
    
    skeleton_daemon();
    
    // Create a child process
    pid_t pid = fork();
    switch (pid) {
    case -1:
        // Error occurred
        perror("fork");
        return 1;
    case 0:
        // This is the child process
        // Execute the command directly
        execvp(args[0], args);
        
        // execvp only returns if an error occurs
        perror("execvp");
        exit(1);
    }
}
