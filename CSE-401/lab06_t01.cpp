#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int priority;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;

    Process(int id, int burst, int priority, int arrival)
        : pid(id), burst_time(burst), remaining_time(burst), priority(priority),
          arrival_time(arrival), completion_time(0), turnaround_time(0), waiting_time(0) {}
};

bool compareArrival(const Process& a, const Process& b) {
    return a.arrival_time < b.arrival_time;
}

bool compareBurst(const Process& a, const Process& b) {
    return a.remaining_time < b.remaining_time;
}

void SJF_preemptive(vector<Process>& processes) {
    int current_time = 0;
    int total_processes = processes.size();
    int completed_processes = 0;
    vector<Process> ready_queue;
    vector<pair<int, int>> gantt_chart;
  
    while (completed_processes < total_processes) {
        for (auto& process : processes) {
            if (process.arrival_time == current_time) {
                ready_queue.push_back(process);
            }
        }
        
        if (!ready_queue.empty()) {
            sort(ready_queue.begin(), ready_queue.end(), compareBurst);
            Process running_process = ready_queue.front();
            ready_queue.erase(ready_queue.begin());
            gantt_chart.push_back(make_pair(running_process.pid, current_time));
            
            if (running_process.remaining_time == running_process.burst_time) {
                cout << "Time " << current_time << ": Process P" << running_process.pid << " starts execution." << endl;
            }
            
            running_process.remaining_time -= 1;
            
            if (running_process.remaining_time == 0) {
                completed_processes += 1;
                running_process.completion_time = current_time + 1;
                cout<<running_process.completion_time<<" ";
                cout << "Time " << current_time + 1 << ": Process P" << running_process.pid << " completes execution." << endl;
            } else {
                ready_queue.push_back(running_process);
            }
        }

        current_time += 1;
    }

   
}

int main() {
    vector<Process> processes = {
        {1, 20, 40, 0},
        {2, 25, 30, 25},
        {3, 25, 30, 30},
        {4, 15, 35, 60},
        {5, 10, 5, 100},
        {6, 10, 10, 105}
    };

    sort(processes.begin(), processes.end(), compareArrival);
    SJF_preemptive(processes);


    return 0;
}

 //  Print

    int total_processes = processes.size();
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // for (auto& process : processes) {
    //     process.turnaround_time = process.completion_time - process.arrival_time; 
    //     process.waiting_time = process.turnaround_time - process.burst_time;  
    // }
    printf("Process\tBurst Time\tRemaining Time\tCompletion Time\tArival time\n");
    for (auto& process : processes)  {
    //    cout << "P" << process.pid << ": " << process.completion_time << " ";
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", process.pid, process.burst_time, process.remaining_time, process.completion_time, process.arrival_time);
        // printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", process.pid, process.burst_time, process.waiting_time, process.turnaround_time, process.arrival_time);
        // avg_waiting_time += process.waiting_time;
        // avg_turnaround_time += process.turnaround_time;
    }
    
    printf("Average Waiting Time: %.2f\n", avg_waiting_time / total_processes);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time / total_processes);