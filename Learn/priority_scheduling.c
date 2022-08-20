#include<stdio.h>

int n,i,j;
int at[10]={0},bt[10]={0},prio[10]={0},ct[10]={0},wt[10]={0},tat[10]={0},proc[10]={0},order[10]={0},visited[10]={0};
int current_time=0,smallest,loop;
float total_tat=0,total_wt=0;

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
				swap(&prio[i],&prio[j]);
				swap(&proc[i],&proc[j]);
			}
		}
	}
}

int main(){
	printf("\n***PRIORITY SCHEDULING***\n\n");

	printf("\nEnter the number of processes : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		printf("\nEnter the arrival time of process %d : ",i);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time of process %d : ",i);
		scanf("%d",&bt[i]);
		printf("\nEnter the priority of process %d : ",i);
		scanf("%d",&prio[i]);
		proc[i] = i;
		visited[i] = 0;
	}

	smallest = at[1];
	j = 1;
	for(loop=1;loop<=n;loop++){
		if(smallest>at[i]){
			smallest = at[i];
			j = i;
		}
	}
	
	current_time = smallest;
	sort(prio,n);
	j=1;

	while(j<=n){
		int yes = 0;
			
		for(i=1;i<=n;i++){
			if(visited[i]==0 && current_time>=at[i]){
				yes = 1;
				visited[i] = 1;
				ct[i] = current_time + bt[i];
				wt[i] = current_time - at[i];
				tat[i] = wt[i] + bt[i];
				order[j] = proc[i];
				total_tat += tat[i];
				total_wt += wt[i];
				current_time = ct[i];
				++j;
				break;
			}
		}
		
		if(yes==0){
			++current_time;
		}
	}

	total_tat = total_tat/n;
	total_wt = total_wt/n;

	printf("\n");
	printf("P_ID\tAT\tPRIO\tBT\tCT\tTAT\tWT\t\n\n");

	for(i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",i,at[i],prio[i],bt[i],ct[i],tat[i],wt[i]);
	}

	printf("\nAvg TAT = %f",total_tat);
	printf("\nAvg WT = %f",total_wt);

}








