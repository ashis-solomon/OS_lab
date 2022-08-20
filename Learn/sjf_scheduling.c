#include<stdio.h>

int n,i,j;
int at[10],bt[10],ct[10],tat[10],wt[10],proc[10],order[10],visited[10];
int current_time=0,smallest;
float total_tat=0,total_wt=0;

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(arr[i]>arr[j]){
				swap(&at[i],&at[j]);
				swap(&bt[i],&bt[j]);
				swap(&proc[i],&proc[j]);
			}
		}
	}
}

int main(){
	
	printf("\n***SHORTEST JOB FIRST SCHEDULING***\n\n");

	printf("\nEnter the number of processes : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		printf("\nEnter the arrival time of process %d : ",i);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time of process %d : ",i);
		scanf("%d",&bt[i]);
		proc[i] = i;
		visited[i] = 0;
	}

	smallest = at[1];
	j = 1;
	for(int loop=1;loop<=n;loop++){
		if(smallest>at[loop]){
			smallest = at[loop];
			j = loop;
		}
	}

	current_time = smallest;
	j=1;
	sort(bt,n);

	while(j<=n){
		int yes = 0;

		for(i=1;i<=n;i++){
			if(visited[i]==0 && current_time>=at[i]){
				yes = 1;
				visited[i]=1;
				order[j] = proc[i];
				wt[i] = current_time - at[i];
				tat[i] = wt[i] + bt[i];
				ct[i] = current_time + bt[i];
				total_tat += tat[i];
				total_wt += wt[i];
				current_time = ct[i];
				++j;
				break;
	
			}
		}
		
		if(yes == 0){
			++current_time;
		}
	}
	total_tat = total_tat/n;
	total_wt = total_wt/n;
	
	printf("\n");
	printf("P_ID\tAT\tBT\tCT\tTAT\tWT\t\n\n");
	
	for(i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("\nOrder of Execution : \n");
	for(i=1;i<=n;i++){printf("%d->",order[i]);}
	printf("\n\n\nAvg WT = %f",total_wt);
	printf("\nAvg TAT = %f",total_tat);
}



