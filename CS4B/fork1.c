#include<stdio.h>
#include<unistd.h>

void main(){
	int p,pid1,pid2;
	for(int i=0;i<2;i++){
	p = fork();
	if(p<0){
		printf("Error in process creation !!\n");
		return;
	}
	else if(p==0){
		pid1 = getpid();
		printf("Parent process %d pid = %d \n\n",i+1,pid1);
	}
	else if(p>0){
		pid2 = getpid();
		printf("Child process %d pid = %d \n\n",i+1,pid2);
	}
	}	
}
