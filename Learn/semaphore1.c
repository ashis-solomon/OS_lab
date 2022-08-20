#include<stdio.h>

int wait(int s);
int signal(int s);
void producer();
void consumer();

int mutex=1,empty=3,full=0,x=0;

int wait(int s){
	return (--s);
}

int signal(int s){
	return (++s);
}

void producer(){
	mutex = wait(mutex);
	full = signal(full);
	x++;
	printf("\nProducer produces item %d !!\n",x);
	empty = wait(empty);
	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
	empty = signal(empty);
	printf("\nConsumer consumes item %d !!\n",x);
	x--;
	full = wait(full);
	mutex = signal(mutex);
}

void main(){
	int choice=1;
	printf("**MENU**\n\n");
	printf("1.Producer\n2.Consumer\n3.Exit\n\n");
	while(choice!=3){
		printf("\nEnter the menu choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:	if((mutex==1) && (empty!=0)){
						producer();
					}
					else{
						printf("\nBUFFER IS FULL!!\n");
					}
					break;
			case 2:	if((mutex==1) && (full!=0)){
						consumer();
					}
					else{
						printf("\nBUFFER IS EMPTY!!\n");
					}
					break;
			case 3: 	return;
		}
	}
}