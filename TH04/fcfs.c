#include <stdio.h>

void main()
{
    // process id
    int pn[10];
    // arrival, bursting, start ,finish, turnaround, waiting, 
    int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], i, n;
    // total waiting time, total turnaround time
    int totwt = 0, tottat = 0;
    float ave_waiting_time,ave_turnaround_time;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Process Name, Arrival Time & Burst Time:");
        scanf("%d%d%d", &pn[i], &arr[i], &bur[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            star[i] = arr[i];
            wt[i] = star[i] - arr[i];
            finish[i] = star[i] + bur[i];
            tat[i] = finish[i] - arr[i];
        }
        else
        {
            star[i] = finish[i - 1];
            wt[i] = star[i] - arr[i];
            finish[i] = star[i] + bur[i];
            tat[i] = finish[i] - arr[i];
        }
    }
    printf("\nPName \tArrtime \tBurtime \tStart \tTAT \tFinish");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%6d\t\t%6d\t%6d\t%6d\t%6d", pn[i], arr[i], bur[i], star[i], tat[i], finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("\n");
    ave_waiting_time = totwt*1.0/n;
    ave_turnaround_time = tottat*1.0/n;

    printf("Average wating time: %f\n",ave_waiting_time);
    printf("Average turnaround time: %f\n",ave_turnaround_time);
}
