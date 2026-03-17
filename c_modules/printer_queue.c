#include <stdio.h>
#include <string.h>
#include "../modules/printer_queue.h"
#include "../modules/utils.h"

void add_print_job(const char user[])
{
    FILE *fp;
    char file[100], logmsg[200];

    printf("Enter file name to print: ");
    scanf("%s", file);

    fp = fopen("data/printer_queue.txt", "a");

    if(fp == NULL)
    {
        printf("Error opening queue file\n");
        return;
    }

    fprintf(fp,"%s %s\n", user, file);

    fclose(fp);

    printf("Job added to queue\n");

    sprintf(logmsg, "%s added print job: %s", user, file);
    log_activity(logmsg);
}

void process_print_job()
{
    FILE *fp;
    FILE *temp;

    char user[50], file[100], logmsg[200];
    int first = 1;

    fp = fopen("data/printer_queue.txt","r");

    if(fp == NULL)
    {
        printf("Queue empty\n");
        return;
    }

    temp = fopen("data/temp.txt","w");

    while(fscanf(fp,"%s %s", user, file) != EOF)
    {
        if(first)
        {
            printf("Printing: %s for %s\n", file, user);
            first = 0;
            sprintf(logmsg, "%s printed file: %s", user, file);
            log_activity(logmsg);
        }
        else
        {
            fprintf(temp,"%s %s\n", user, file);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("data/printer_queue.txt");
    rename("data/temp.txt","data/printer_queue.txt");
}

void view_queue()
{
    clear_screen();
    FILE *fp;

    char user[50], file[100];
    int pos = 1;

    fp = fopen("data/printer_queue.txt","r");

    if(fp == NULL)
    {
        printf("Queue empty\n");
        return;
    }

    printf("\n===== Printer Queue (FCFS) =====\n");
    printf("Position\tUser\tFile\n");
    printf("----------------------------------\n");

    while(fscanf(fp,"%s %s", user, file) != EOF)
    {
        printf("%d\t\t%s\t%s\n", pos++, user, file);
    }

    fclose(fp);
}

void printer_menu(const char user[])
{
    int choice;

    while(1)
    {
        clear_screen();
        printf("\n===== Printer Menu =====\n");
        printf("1. Add Print Job\n");
        printf("2. Process Next Job\n");
        printf("3. View Queue\n");
        printf("4. Back to Main Menu\n");

        printf("Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add_print_job(user);
                pause_screen();
                break;

            case 2:
                process_print_job();
                pause_screen();
                break;

            case 3:
                view_queue();
                pause_screen();
                break;

            case 4:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}