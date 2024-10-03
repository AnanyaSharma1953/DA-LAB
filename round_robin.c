#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process {
    int id;
    int burst_time;
    int remaining_time;
    struct Process* next;
} p;
void add_process(p** head, int id, int burst_time) 
{
    p* n= (p*)malloc(sizeof(p));
    n->id = id;
    n->burst_time = burst_time;
    n->remaining_time = burst_time;
    n->next = NULL;
    if (*head == NULL) {
        *head = n;
    } 
    else 
    {
        p* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void round_robin(p* head, int quantum) 
{
    p* current = head;
    int all_done;
    do {
        all_done = 1; 
        current = head;

        while (current != NULL) {
            if (current->remaining_time > 0) 
            {
                all_done = 0; 

                int time_to_run = (current->remaining_time < quantum) ? current->remaining_time : quantum;

                printf("Process %d is executing for %d units.\n", current->id, time_to_run);

                current->remaining_time -= time_to_run;
                if (current->remaining_time == 0) 
                {
                    printf("Process %d has completed.\n", current->id);
                }
            }
            current = current->next; 
        }
    } while (!all_done); 
}

int main() 
{
    p* process_list = NULL;
    int num_processes, i, burst_time, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    for (i = 1; i <= num_processes; i++) {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &burst_time);
        add_process(&process_list, i, burst_time);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    round_robin(process_list, quantum);
    return 0;
}
