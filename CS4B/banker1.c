#include <stdio.h>

void input();

int alloc[10][13] ;
int max[15][13];
int avail[10],n,m;

int main()
{

	int i, j, k;
	
	 

	input();

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(f[i]==0)
	{
		flag=0;
		printf("\nSystem is NOT SAFE");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	}
	

	return (0);
}
void input()
{
int i,j;
printf("\nEnter the no of Processes : ");
scanf("%d",&n);
printf("\nEnter the no of resources instances : ");
scanf("%d",&m);
printf("\nEnter the MAX Matrix :\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&max[i][j]);
}}
printf("\nEnter the ALLOCATION Matrix :\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&alloc[i][j]);
}}
printf("\nEnter the Available Resources :\n");
for(j=0;j<m;j++)
{
scanf("%d",&avail[j]);
}}
