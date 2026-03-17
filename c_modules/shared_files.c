#include <stdio.h>
#include <string.h>
#include "../modules/shared_files.h"
#include "../modules/utils.h"

void view_files()
{
    FILE *fp;
    char file[100];
    int i = 1;

    fp = fopen("data/shared_files.txt", "r");

    if(fp == NULL)
    {
        printf("No shared files.\n");
        return;
    }

    printf("\n===== Shared Files =====\n\n");

    while(fscanf(fp, "%s", file) != EOF)
    {
        printf("%d. %s\n", i, file);
        i++;
    }

    fclose(fp);
}

void read_file(const char current_user[])
{
    FILE *fp;
    char filename[100], logmsg[200];
    char ch;

    printf("Enter file name to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    printf("\n===== File Content =====\n\n");

    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    printf("\n");

    sprintf(logmsg, "%s accessed file: %s", current_user, filename);
    log_activity(logmsg);

    fclose(fp);
}

void remove_file(const char current_user[])
{
    FILE *fp, *temp;
    char filename[100];
    char file[100];
    int found = 0;
    char logmsg[200];

    printf("Enter file name to remove: ");
    scanf("%s", filename);

    /* delete actual file */
    remove(filename);

    fp = fopen("data/shared_files.txt", "r");
    temp = fopen("data/temp.txt", "w");

    if(fp == NULL || temp == NULL)
    {
        printf("Error opening file list.\n");
        return;
    }

    while(fscanf(fp, "%s", file) != EOF)
    {
        if(strcmp(file, filename) != 0)
        {
            fprintf(temp, "%s\n", file);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("data/shared_files.txt");
    rename("data/temp.txt", "data/shared_files.txt");

    if(found)
        printf("File removed successfully!\n");
    else
        printf("File not found in shared list.\n");

    sprintf(logmsg, "%s removed file: %s", current_user, filename);
    log_activity(logmsg);
}

void shared_files_menu(const char current_user[])
{
    int choice;

    while(1)
    {
        clear_screen();
        printf("\n===== Shared Files =====\n");
        printf("1. View Files\n");
        printf("2. Read File Content\n");
        printf("3. Share New File\n");
        printf("4. Add Content to File\n");
        printf("5. Remove File\n");
        printf("6. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            view_files();
            pause_screen();
        }
        else if(choice == 2)
        {
            read_file(current_user);
            pause_screen();
        }
        else if(choice == 3)
        {
            FILE *fp;
            char new_file[100];
            char logmsg[200];

            printf("Enter file name to share: ");
            scanf("%s", new_file);

            fp = fopen("data/shared_files.txt", "a");

            if(fp == NULL)
            {
                printf("Error opening file.\n");
                return;
            }

            fprintf(fp, "%s\n", new_file);

            fclose(fp);

            printf("File shared successfully!\n");
            sprintf(logmsg, "%s shared file: %s", current_user, new_file);
            log_activity(logmsg);
            pause_screen();
        }
        else if(choice == 4)
        {
            FILE *fp;
            char filename[100];
            char content[200];
            char logmsg[200];

            printf("Enter file name: ");
            scanf("%s", filename);

            fp = fopen(filename, "a");

            if(fp == NULL)
            {
                printf("File not found.\n");
                return;
            }

            printf("Enter content: ");
            scanf(" %[^\n]", content);

            fprintf(fp,"%s\n", content);

            fclose(fp);

            printf("Content added successfully!\n");
            sprintf(logmsg, "%s added content to file: %s", current_user, filename);
            log_activity(logmsg);
            pause_screen();
        }
        else if(choice == 5)
        {
            remove_file(current_user);
            pause_screen();
        }
        else if(choice == 6)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
}