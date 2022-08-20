#include<stdio.h>

int mutex=1,empty=3,full=0,x=0;

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}

void producer(){
	mutex = wait(mutex);
	full = signal(full);
	++x;
	printf("\nProducer produed item %d !!",x);
	empty = wait(empty);
	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
	empty = signal(empty);
	printf("\nConsumer consumed item %d !!",x);
	--x;
	full = wait(full);
	mutex = signal(mutex);
}

void main(){
	printf("**Menu**\n");
	printf("\n1.Producer\n2.Consumer\n3.Exit\n\n");
	int choice=1;
	while(choice!=3){
		printf("\nEnter the menu choice : ");
		scanf("%d",&choice);
		switch(choice){
			
			case 1 : if(full==3){printf("\nBuffer is Full!!!\n");}
					else if(mutex==1 && full!=3){producer();}
					break;
			case 2: if(empty==0){printf("\nBuffer is Empty!!!\n");}
					if(mutex==1 && empty!=0){consumer();}
					break;
			case 3: return;
					break;
					
		}
	}
}

