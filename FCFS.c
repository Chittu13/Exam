#include<stdio.h>
struct PRCS {
    int id;
    int arrivalTime;
    int burstTime;
};
void FCFS(struct PRCS processes[], int n) {
    int waitTime = 0;
    int totalWaitTime = 0;
    int totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        waitTime = waitTime + processes[i].burstTime - processes[i].arrivalTime;
        totalWaitTime += waitTime;
        totalTurnaroundTime += (waitTime + processes[i].burstTime);
        waitTime += processes[i].burstTime;
    }
    double avgWaitTime = (double)totalWaitTime / n;
    double avgTurnaroundTime = (double)totalTurnaroundTime / n;
    printf("Total Wait Time: %d\n", totalWaitTime);
    printf("Average Waiting Time: %lf\n", avgWaitTime);
    printf("Total Turnaround Time: %d\n", totalTurnaroundTime);
    printf("Average Turnaround Time: %lf\n", avgTurnaroundTime);
}
int main() 
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct PRCS processes[n];
    for (int i = 0; i < n; i++) 
    {
        printf("Enter details for process %d\n", i + 1);
        processes[i].id = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
    }
    FCFS(processes, n);
    return 0;
}
