#include<stdio.h>

int alloc[10][10];
int max[10][10];
int available[10];
int need[10][10];

int n,r;

void input();
void show();
void cal();

void input(){
	int i,j;
	printf("\nEnter the number of processes : ");
	scanf("%d",&n);
	printf("\nEnter the number of resources : ");
	scanf("%d",&r);
	
	printf("\nEnter the ALLOCATION matrix : \n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\n\nEnter the MAX matrix : \n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("\n\nEnter the AVAILABLE RESOURCES matrix : \n");
	for(i=0;i<r;i++){
		scanf("%d",&available[i]);
	}
}

void show(){
	int i,j;
	printf("\nPROCESS\t\tALLOCATION\t\tMAX\t\tAVAILABLE\n");

	for(i=0;i<n;i++){
		printf("\nP%d\t\t",i);
		for(j=0;j<r;j++){
			printf("%d  ",alloc[i][j]);
		}
		printf("\t\t");
		for(j=0;j<r;j++){
			printf("%d  ",max[i][j]);
		}
		printf("\t");
		if(i==0){
			for(j=0;j<r;j++){
				printf("%d  ",available[j]);
			}
		}
	}
}

void cal(){
	int i,j,flag=1,c1=0;
	int finish[10] = {0};
	int need[10][10];
	int safe[10];

	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}

	while(flag){
		flag=0;
		for(i=0;i<n;i++){
			int c=0;
			for(j=0;j<r;j++){
				if((finish[i]==0) && (need[i][j]<=available[j])){
					c++;
					if(c==r){
						for(int k=0;k<r;k++){
							available[k] += alloc[i][j];
							finish[i] = 1;
							flag = 1;
						}
						printf("P%d->",i);
						if(finish[i]==1){
							i=n;
						}
					}
					
				}
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(finish[i]==1){c1++;}
	}
	if(c1==n){
		printf("\nTHE SYSTEM IS IN SAFE STATE !!");
	}
	else{
		printf("\nPROCESSES ARE IN DEADLOCK");
		printf("\nTHE SYSTEM IS IN UNSAFE STATE !!");
	}
}

void main(){
	printf("\n***BANKER'S ALGORITHM***\n\n");
	input();
	show();
	cal();
}







