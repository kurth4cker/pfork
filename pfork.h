#pragma once

/*
 * PFork : simple daemonizer library
 * skeleton_daemon(); function set process to background and close current process.
 * current pid value changed
*/

#include <stdbool.h>
#include <sys/types.h>
//main daemonizer function
void skeleton_daemon();

//change umask value for daemon (default 022)
void set_umask(mode_t umask_value);
//stderr and stdout file (if silent equal 0)
extern const char *logfile;
//stdin file (if silent equal 0)
extern const char *infile;
//if silent is 1, stdout and stdin will write to file and stdin read from file.
extern bool silent;
