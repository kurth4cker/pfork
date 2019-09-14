#include "daemon.c"
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
  char args[1024]="";
  for(int i=1;i<argc;i++){
    strcat(args,argv[i]);
    strcat(args," ");
  }
  skeleton_daemon();
  return system(args);
}
