#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int fault_injection(task)
{
    int task_duration = rand() % 10;
    int restriction = 5; 
    int delay = rand() % 10;  
    task_duration += delay;
    clock_t start, finish;
    start = clock();
    for( int j = 0 ;j <6;j++);
    {
        sleep(task_duration);
        finish = clock();
        int total_time = (finish - start) / CLOCKS_PER_SEC;
        if (restriction <= total_time)
        {
            printf("This task was unable to complete \n");  
            printf("A delay occured, lasting for %d seconds. The total duration was %d.\n", delay, total_time);
            
        }
        else if(restriction >= total_time)
        {   
            printf("This task was able to complete \n");  
            printf("A delay occured, lasting for %d seconds. The total duration was %d.\n", delay, total_time);
        }
    }
}
int main()
{
    int task1;
    int task2;
    int task3;
    int task4;
    int task5;
    int task6;
    fault_injection(task1);
    fault_injection(task2);
    fault_injection(task3);
    fault_injection(task4);
    fault_injection(task5);
    fault_injection(task6);
}