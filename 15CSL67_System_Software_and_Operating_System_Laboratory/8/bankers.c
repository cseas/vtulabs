#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int alloc[10][10], max[10][10], need[10][10];
int avail[10], work[10], processes, resources, j, i, v=0;
bool finish[10];

bool check(int i) {
    for(j=0; j<resources; j++) {
        if(need[i][j] > work[j])
            return false;
    }
    return true;
}

int main() {
    int k;
    printf("Enter the number of processes and resources:\n");
    scanf("%d%d", &processes, &resources);

    int seq[processes];

    printf("\nEnter the allocated values:\n");
    for(i=0; i<processes; i++)
        for(j=0; j<resources; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter the max values:\n");
    for(i=0; i<processes; i++)
        for(j=0; j<resources; j++)
            scanf("%d", &max[i][j]);

    // need = max - allocation
    for(i=0; i<processes; i++)
        for(j=0; j<resources; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nEnter the available matrix:\n");
    for(i=0; i<resources; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    // Safety algorithm
    for(i=0; i<processes; i++)
        finish[i] = false;

    while(v < processes) {
        bool allocated = false;
        for(i=0; i<processes; i++) {
            if(!finish[i] && check(i)) {
                for(k=0; k<resources; k++)
                    work[k] = work[k] + alloc[i][k];

                allocated = finish[i] = true;
                seq[v] = i;
                v++;
            }
        }
        if(!allocated) break;
    }

    for(i=0; i<processes; i++) {
        if(finish[i] == false) {
            printf("\nAll processes can't be safely allocated!\n");
            exit(0);
        }
    }

    printf("Processes safely allocated with sequence:\n");
    for(i=0; i<v; i++)
        printf("%d\t", seq[i]);

    printf("\n");
    return 0;
}
