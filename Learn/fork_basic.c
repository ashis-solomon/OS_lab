#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
  int p = fork();
  if(p==0){
    printf("\nIN CHILD PROCESS\n");
    printf("\nParent Process id : %d \n",getppid());
    printf("\nProcess id : %d \n",getpid());
    printf("\nEXIT CHILD\n");
    exit(EXIT_SUCCESS);
  }
  else{
    printf("\nIN PARENT PROCESS\n");
    printf("\nProcess id : %d \n",getpid());
    wait(NULL);
    printf("\nEXIT PARENT\n");
  }
  return 0;
}