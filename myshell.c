#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHELLSTR "\nmyshell$ "
#define MAXCMDLEN 16384


int readcmd() {
  
  int rc;
  char *command;
  
  fgets(command, MAXCMDLEN, stdin); 

  if (strncmp(command, "exit", strlen("exit")-1) == 0) {
    fprintf(stderr, "exiting myshell\n");  
    rc = 0; 
  }
  else {
    fprintf(stderr, "Unknown Command"); 
    rc = 1;
  }

  return rc; 
  
}

int main(int argc, char *argv[]) {

  int rc = 1;

  while (rc != 0) { // exit command to shell will result in zero 
    fprintf(stdout, "%s", SHELLSTR);
    rc = readcmd();
  }

  return 0;
}
