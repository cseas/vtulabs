#include<stdio.h>

typedef struct J {
	int arrival, finish, burst, tat, wt;
} Job;

void scheduler(Job job[], int n, int quantum, int c) {
	int bursts[100];
	
  for(int i=0;i<n;i++)
		bursts[i] = job[i].burst;
	
  int t = 0, done = 0, curr, diff;
	
	if (c == 0) // RR
		curr = -1;
	else // SJF
		curr = 0;
	
  while (done < n) {	
		if(c == 1) { // SJF
			for(int x=0; x<n; x++) {	
				if(job[curr].burst == 0) // if current job has finished
					curr = x;
				if(job[x].burst < job[curr].burst)		
					if(job[x].burst > 0 && job[x].arrival <= t)
						curr = x;
			}
			
			diff = 1;		// preemptive mode
			// diff = job[curr].burst;	// non preemptive mode
		} else { // RR
			while(1) {
				curr = (curr + 1) % n;
				if(job[curr].burst != 0)
					break;
			}
      
			diff = (quantum <= job[curr].burst) ? quantum : job[curr].burst;		
		}
		
    job[curr].burst -= diff;
		t += diff;
		
    //if curr job finished
    if(job[curr].burst == 0) {
			done++;		
			job[curr].finish = t;		
		}
	}	

	if(c == 1)	
		printf("\nThe SJF schedule details are:\n");
	else
		printf("\nThe Round Robin schedule details are:\n");	
	
  for (int i=0; i<n; i++) // restore burst values for displaying
		job[i].burst = bursts[i];
	
  printf("\nJob\tTaT\tWT\n");
	for(int i=0; i<n; i++) {
		job[i].tat = job[i].finish - job[i].arrival * c;
		job[i].wt = job[i].tat - job[i].burst;
		printf("%d\t%d\t%d\n", i, job[i].tat, job[i].wt);
	}
}

int main() {
	Job job[100];
	int n, quantum, choice;
	
  printf("Enter the number of jobs:\n");
	scanf("%d", &n);
	
  printf("\nEnter Arrival & Burst time:\n");
	for(int i=0;i<n;i++) {
		printf("Job%d: ", i);
		scanf("%d%d", &job[i].arrival, &job[i].burst);
	}

	printf("\n1:Round Robin\n2:Shortest Job First\n");
	scanf("%d", &choice);
	switch (choice) {
		case 1:	
			printf("Enter quantum size for Round Robin: ");
			scanf("%d",&quantum);
			scheduler(job, n, quantum, 0);	
			break;
		case 2:scheduler(job, n, quantum, 1);
	}
}
