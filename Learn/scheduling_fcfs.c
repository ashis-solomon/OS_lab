#include<stdio.h>
#include<stdlib.h>

int at[10]={0},bt[10]={0},order[10]={0};
int ct[10],tat[10],wt[10];

int n,i,j,temp;
float total_tat,total_wt;

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int arr[],int n){
	for(i=0;i<n;i++){
		for(j=i+1;j<=n;j++){
			if(arr[i]>arr[j]){
				swap(&at[i],&at[j]);
				swap(&bt[i],&bt[j]);
				swap(&order[i],&order[j]);
			}
		}
	}
}

void input(){
	printf("\n***FCFS SCHEDULING***\n\n");

	printf("Enter the number of processes : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		printf("Enter the arrival time of process %d : ",i);
		scanf("%d",&at[i]);
		printf("Enter the burst time of process %d : ",i);
		scanf("%d",&bt[i]);
		order[i] = i;
	}
	sort(at,n);
}

void cal(){
	for(i=1;i<=n;i++){
		if(i==1){
			temp = at[i] + bt[i];
			ct[i] = temp;
			tat[i] = ct[i] - at[i];
			wt[i] = tat[i] - bt[i];
			total_tat += tat[i];
		}
		else{
			temp = temp + bt[i];
			ct[i] = temp;
			tat[i] = ct[i] - at[i];
			wt[i] = tat[i] - bt[i];
			if(wt[i]<0){
				ct[i] += abs(wt[i]);
				temp = ct[i];
				tat[i] += abs(wt[i]);
				wt[i] = 0;
			}
			total_tat += tat[i];
			total_wt += wt[i];
		}
	}
	total_tat = total_tat/n;
	total_wt = total_wt/n;
}

void show(){
	printf("\nThe order of execution : \n");
	for(i=1;i<=n;i++){
		printf("P%d->",order[i]);
	}
	printf("\n");

	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\n\n");
	printf("total_tat = %.2f",total_tat);
	printf("total_wt = %.2f",total_wt);
}

void main(){
	input();
	cal();
	show();
}