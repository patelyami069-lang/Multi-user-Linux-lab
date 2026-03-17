#include <stdio.h>
#include <string.h>
#include "../modules/deadlock.h"
#include "../modules/utils.h"

void deadlock_demo()
{
    int n;
    char hold[20][20];
    char req[20][20];
    char logmsg[300];

    printf("\n===== Deadlock Simulation =====\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        printf("\nProcess P%d\n", i+1);

        printf("Resource held: ");
        scanf("%s", hold[i]);

        printf("Resource requested: ");
        scanf("%s", req[i]);
    }

    printf("\n===== System State =====\n");
    printf("Process   Holds   Requests\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d        %s      %s\n", i+1, hold[i], req[i]);
    }

    int deadlock = 1;

    for(int i=0;i<n;i++)
    {
        int found = 0;

        for(int j=0;j<n;j++)
        {
            if(strcmp(req[i], hold[j]) == 0)
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            deadlock = 0;
            break;
        }
    }

    if(deadlock)
    {
        printf("\nDeadlock Detected!\n");
        sprintf(logmsg, "Deadlock simulation run: DEADLOCK DETECTED for %d processes", n);
        log_activity(logmsg);
    }
    else
    {
        printf("\nSystem Safe: No Deadlock\n");
        sprintf(logmsg, "Deadlock simulation run: SYSTEM SAFE for %d processes", n);
        log_activity(logmsg);
    }
}