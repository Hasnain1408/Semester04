#include<stdio.h>

void fcfs(int burst_time[], int n) {
    int waiting_time[n], turnaround_time[n],completion_time[n];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    completion_time[0]=burst_time[0];
    for (int i = 1; i < n; i++)
        completion_time[i]=completion_time[i-1]+burst_time[i];
    
    for (int i = 0; i < n; i++)
        turnaround_time[i] = completion_time[i]-0;

    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
        waiting_time[i] = turnaround_time[i]- burst_time[i];
    
    
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    
    printf("Average Waiting Time: %.2f\n", avg_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time / n);

    
}

int main() {
    int burst_time[] = {2, 1, 8, 4, 5};
    int n = sizeof(burst_time) / sizeof(burst_time[0]);
    
    fcfs(burst_time, n);
    return 0;
}

// print_process()
// {
//     for(int i=0; i<n; ++i)
//     {
//         printf("|---P%d---",i+1);
//     }
//     printf("|");

//     printf("0");
//     for(int i=0; i<n; ++i)
//     {
//         printf("          ",turnaround_time[i]);
//     }
   
// }
