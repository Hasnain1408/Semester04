#include<stdio.h>


void Round_Robin(int burst_time[], int n) {
    int waiting_time[n], turnaround_time[n],completion_time[n];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    int remaining_time[n];
    for (int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];

    int count = n;
    int quantum;
    printf("Enter quantum time -> ");
    scanf("%d",&quantum);

    int round_time=0;

    while(count)
    { 
        for (int i = 0; i < n; i++)
        {
            if(quantum < remaining_time[i])
            {
                completion_time[i] = round_time + quantum;
                round_time += quantum;
                remaining_time[i] -= quantum;
                // completion_time[i] += quantum; 
            }else if(remaining_time[i] != 0 || remaining_time[i] == quantum )
            {
                completion_time[i] = round_time + remaining_time[i];
                round_time += remaining_time[i];
                remaining_time[i] -= remaining_time[i]; 
                //completion_time[i] += remaining_time[i];   
                count--;
            }
        }       
    }
    
    for (int i = 0; i < n; i++)
        turnaround_time[i] = completion_time[i]-0;

    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
        waiting_time[i] = turnaround_time[i]- burst_time[i];
    
    
    
    printf("Process\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d \t\t%d\n", i+1, burst_time[i], turnaround_time[i], waiting_time[i]);
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    
    printf("Average Waiting Time: %.2f\n", avg_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time / n);

    
}

int main() {
    int burst_time[] = {2, 1, 8, 4, 5};
    int n = sizeof(burst_time) / sizeof(burst_time[0]);
    
    Round_Robin(burst_time, n);
    return 0;
}


