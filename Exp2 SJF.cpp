// Made by:- Nikhil Singh 
// Roll No:- 2K22/CO/309
#include<bits/stdc++.h>

class PCB{
public:
    int pid, wait, burst, turnaround;
};

void pline(int);

int main(){
    int i, n, j, wait = 0;
    float avg = 0.0, sum = 0.0, wait_average = 0.0;
    class PCB p[10], temp;
	printf("SJF Algorithm\n");
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    for( i = 0; i<n; i++){
        printf("Enter Arrival Time and Burst Time for process id %d :\n", i+1);
        scanf("%d", &p[i].burst);
        p[i].pid = i+1;
    }
    for( i = 0; i<n-1; i++){
        for( j = 0; j<n-i-1; j++){
            if(p[j].burst > p[j+1].burst){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    for( i = 0; i<n; i++){
		p[i].wait = sum;
        sum = sum + p[i].burst;
        p[i].turnaround = sum;
    }
    sum = 0;
    pline(44);
    printf("PID\tBurst\tWait\tTurnaround\n");
    pline(44);
    for( i = 0; i<n; i++){
        printf("%d\t%d\t%d\t%d\n",p[i].pid, p[i].burst, p[i].wait, p[i].turnaround);
        sum+=p[i].turnaround;
		wait += p[i].wait;
    }
    pline(44);
	wait_average = wait/(float)(n);
    avg = sum/(float)(n);
	printf("Total Waiting Time: %d\n", wait);
	printf("Average Waiting Time: %.3f\n", wait_average);
    printf("Total Turnaround Time: %f\n", sum);
    printf("Average Turnaround Time : %.3f\n", avg);
    return 0;
}

void pline(int n){
    for(int i = 0; i<=n; i++){
        printf("-");
    }
    printf("\n");
}