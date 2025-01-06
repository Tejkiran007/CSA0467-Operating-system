#include <stdio.h>

void priority_scheduling(int processes[], int burst_times[], int priorities[], int n) {
    int waiting_time[n], turnaround_time[n];
    
    waiting_time[0] = 0;
    turnaround_time[0] = burst_times[0];
    int i;
    
    // Calculate waiting time and turnaround time for each process
    for ( i = 1; i < n; i++) {
        waiting_time[i] = burst_times[i - 1] + waiting_time[i - 1];
        turnaround_time[i] = waiting_time[i] + burst_times[i];
    }
    
    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_times[i], priorities[i], waiting_time[i], turnaround_time[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int processes[] = {1, 2, 3,}; // Process IDs
    int burst_times[] = {30 ,5, 12}; // Burst times for each process
    int priorities[] = {2, 1, 3}; // Priorities for each process
    int n = sizeof(processes) / sizeof(processes[0]);
    
    priority_scheduling(processes, burst_times, priorities, n);
    
    return 0;
}
