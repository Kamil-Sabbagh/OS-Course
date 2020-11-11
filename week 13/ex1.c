#include <stdio.h>
#include <stdbool.h>
int procs;
int num_res;

void read_from_file(FILE *fp,int procs, int num_res,int E[] ,int A[],int C[][num_res],int R[][num_res]){
	

	for(int i = 0; i < num_res; i++) fscanf(fp,"%d",&E[i]) ; 

	for(int i = 0; i < num_res; i++) fscanf(fp,"%d",&A[i]) ;


	for (int i = 0; i < procs ; ++i)
	{
		for(int k = 0; k < num_res; k++) fscanf(fp,"%d",&C[i][k]);
	}

	for (int i = 0; i < procs ; ++i)
	{
		for(int k = 0; k < num_res; k++) fscanf(fp,"%d",&R[i][k]);
		
	}
}

void isSafe(FILE *out,int processes[], int available[], int allocation[][num_res], int request[procs][num_res]){

	bool finish[procs];

	for (int i = 0; i < procs ; ++i) finish[i] = 0;
	
	int safeOrder[procs];

	int work[num_res];
	for(int i = 0; i < num_res; i++)  work[i] = available[i];
	
	int count = 0;
	while(count < procs ){
		bool found = false;
		for (int i = 0; i < procs ; ++i)
		{
			if(finish[i] == 0){
				int j;
				for (j = 0; j < num_res; ++j)
					if(request[i][j] > work[j])
						break;
				if(j == num_res){
					for(int k = 0; k < num_res;k++)
						work[k] += allocation[i][k];
					safeOrder[count++] = i;

					finish[i] = 1;

					found = true;
				}	
			}		
		}

		if ( !found ){
			fprintf(out,"The system in not in a safe stat to run\n");
			return;
		}

	}
		fprintf(out,"A safe system sequence of order: \n");
		for (int i = 0; i < procs ; ++i)
		{
			fprintf(out,"%d ",safeOrder[i]);
		}
		fprintf(out,"\n");

}	


int main()
{

	FILE  *fp_w = fopen("input_dl","r"); 
	FILE *fp_wo = fopen("input_ok","r");
	FILE *out_ok = fopen("output_ok","w");
	FILE *out_dl = fopen("output_dl","w");
	
	printf("Enter number of processes:\n");
	scanf("%d", &procs);

	printf("Enter number of resources\n");
	scanf("%d", &num_res);


	int E[num_res];
	int A[num_res];
	int C[procs][num_res];
	int R[procs][num_res];

	int processes[procs];
	for (int i = 0; i < procs ; ++i)
	{
		processes[i] = i;
	}
	read_from_file(fp_wo,procs , num_res,E,A,C,R);
	isSafe(out_ok,processes,A,C,R);

	read_from_file(fp_w, procs, num_res,E,A,C,R);
	isSafe(out_dl,processes,A,C,R);
	return 0;
}
