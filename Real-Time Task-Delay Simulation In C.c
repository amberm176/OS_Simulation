#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "unistd.h"
typedef struct Queue{
    int tasks[6];
    int f;
    int b;
} Queue;
void createQueue(Queue* tasks)
{
    tasks->f = 1;
    tasks->b = 6;
}
int fault_injection(struct Queue *tasks)
{
    int task_duration = 10;
    int start_time_stamp = clock();
    int restriction = 5; 
    int delay = rand() % 7;  
    task_duration += delay;
    clock_t start, finish;
    start = clock();
    for (int i = start_time_stamp; i<task_duration;i++);
    { 

        sleep(task_duration);
        if (start_time_stamp-clock() == restriction && restriction <= task_duration)
        {
            printf("This task was unable to complete \n", tasks-> f);
            
                
        }
        
        else if(start_time_stamp== restriction && restriction >= task_duration)
        {
            printf(" Task: %d Completed \n", tasks-> f );  
        }
        finish = clock();
        int total_time = (finish - start) / CLOCKS_PER_SEC;
        printf("A delay occured, lasting for %d seconds. The total duration for task: %d was %d.\n", delay, tasks-> f,total_time);
        tasks->f++;
        tasks->b = tasks->f;
        tasks->b++; 
    }
}
int main ()
{
    struct Queue *tasks[6] = {1,2,3,4,5,6};
    createQueue(tasks);
    fault_injection(tasks);
}