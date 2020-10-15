#include <pfork.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
  char args[1024]="";
  for(int i=1;i<argc;i++){
    strcat(args,argv[i]);
    strcat(args," ");
  }
  //Versobe output. dont write file
  silent = 0;
  char *silent_env = getenv("SILENT");
  if(silent_env != NULL){
      if(strcmp(silent_env,"1")==0){
          silent=1;
      }
  }
  skeleton_daemon();
  //We dont use execpv. We need to run as child process...
  return system(args);
}
