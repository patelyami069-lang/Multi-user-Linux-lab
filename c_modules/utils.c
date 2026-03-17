#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "../modules/utils.h"

void clear_screen()
{
    system("cls");
}

void pause_screen()
{
    printf("Press Enter to continue...");
    getchar();
    getchar();
}

void log_activity(const char *text)
{
    FILE *fp = fopen("data/activity_log.txt","a");

    if(fp == NULL){
        printf("Error opening activity log file.\n");
        return;
    }

    fprintf(fp,"%s\n", text);

    fclose(fp);
}

void view_activity_log() {
    FILE *fp;
    char ch;

    fp = fopen("data/activity_log.txt", "r");

    if(fp == NULL)
    {
        printf("No activity log found.\n");
        return;
    }

    printf("\n===== Activity Log =====\n\n");

    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    printf("\n");
    fclose(fp);
}

void show_dashboard(const char user[])
{
    clear_screen();
    FILE *fp;
    int queue_len = 0, shared_files = 0;
    char line[200];

    fp = fopen("data/printer_queue.txt", "r");
    if(fp != NULL)
    {
        while(fgets(line, sizeof(line), fp) != NULL)
            queue_len++;
        fclose(fp);
    }

    fp = fopen("data/shared_files.txt", "r");
    if(fp != NULL)
    {
        while(fgets(line, sizeof(line), fp) != NULL)
            shared_files++;
        fclose(fp);
    }

    printf("\n========= LAB STATUS =========\n\n");
    printf("User           : %s\n", user);
    printf("Printer Status : %s\n", queue_len > 0 ? "Busy" : "Ready");
    printf("Queue Length   : %d\n", queue_len);
    printf("Shared Files   : %d\n", shared_files);
    printf("\n==============================\n");
}