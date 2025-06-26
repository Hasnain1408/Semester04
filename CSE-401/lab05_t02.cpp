#include<stdio.h>

void bubbleSort(int* array, int* process, int size) {

  
  for (int step = 0; step < size - 1; ++step) {
      
    for (int i = 0; i < size - step - 1; ++i) {
      
      if (array[i] > array[i + 1]) {

        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;

        int temp2 = process[i];
        process[i] = process[i + 1];
        process[i + 1] = temp2;
      }
    }
  }
}

void SJF(int burst_time[], int* process, int n) {
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
        printf("P%d\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    
    printf("Average Waiting Time: %.2f\n", avg_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time / n);

    
}

int main() {
    int burst_time[] = {2, 1, 8, 4, 5};
    int process[] = {1, 2, 3, 4, 5};
    int n = sizeof(burst_time) / sizeof(burst_time[0]);

    bubbleSort(burst_time, process, n);
    
    SJF(burst_time, process, n);
    return 0;
}






