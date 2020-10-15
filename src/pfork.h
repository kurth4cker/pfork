/*
 * PFork : simple daemonizer library
 * skeleton_daemon(); function set process to background and close current process.
 * current pid value changed
*/

//main daemonizer function
extern void skeleton_daemon();

//change umask value for daemon (default 022)
extern void set_umask(int umask_value);
//stderr and stdout file (if silent equal 0)
extern char* logfile;
//stdin file (if silent equal 0)
extern char* infile;
//if silent is 1, stdout and stdin will write to file and stdin read from file.
extern int silent;
