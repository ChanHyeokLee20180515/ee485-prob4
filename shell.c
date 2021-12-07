#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

int main() {
  int i = 0, pid, count = 0;
  char *token, command[2000];
  fgets(command, sizeof(command), stdin);
  command[strlen(command)-1] = 0;
  while(command[i] != '\0'){
      if(isspace(command[i])){
          count++;
      }
      i++;
  }
  count++;
  char *arguments[count];
  printf("%d\n",count);


  token = strtok(command, " ");
  if (token == NULL) {exit(-1);}
  arguments[0] = token;
  for (i = 1; i<count; i++) {
    token = strtok(NULL, " ");
    if (token == NULL)
      break;
    arguments[i] = token;
  }
  arguments[i] = NULL;

  pid = fork();
  if (pid != 0){
    wait(NULL);
  } else {
    execvp(arguments[0], arguments);
  }
}
