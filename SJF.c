#include <stdio.h>
 
int main() {
    int bt[20], at[20], p[20], wt[20], tat[20], i, j, n, total = 0, totalT = 0, pos, temp;
    float avg_wt, avg_tat;
 
    printf("Enter number of processes:");
    scanf("%d", &n);
 
    printf("\nEnter Burst Time and Arrival Time:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        p[i] = i + 1;
    }
 
  
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (at[j] < at[pos] || (at[j] == at[pos] && bt[j] < bt[pos])) {
                pos = j;
            }
        }
 
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
 
        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
 
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
 
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        total += wt[i];
    }
 
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        totalT += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], wt[i], tat[i]);
    }
 
    avg_wt = (float)total / n;
    avg_tat = (float)totalT / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
 
    return 0;
    }
