#include <stdio.h>
#include <string.h>
#include "modules/login.h"
#include "modules/utils.h"
#include "modules/printer_queue.h"
#include "modules/shared_files.h"
#include "modules/deadlock.h"

void lab_menu(char user[])
{
    int ch;

    while(1)
    {
        clear_screen();
        printf("\n===== Linux Lab Management System =====\n");
        printf("1. Dashboard\n");
        printf("2. Printer Management\n");
        printf("3. Shared File Manager\n");
        printf("4. Deadlock Detection\n");
        printf("5. View Activity Log\n");
        printf("6. Logout\n");

        printf("Choice: ");
        scanf("%d",&ch);

        if(ch == 1)
        {
            show_dashboard(user);
            pause_screen();
        }
        else if(ch == 2)
        {
            printer_menu(user);
            clear_screen();
        }
        else if(ch == 3)
        {
            shared_files_menu(user);
            clear_screen();
        }
        else if(ch == 4)
        {
            deadlock_demo();
            pause_screen();
        }

        else if(ch == 5)
        {
            view_activity_log();
            pause_screen();
        }

        else if(ch == 6)
        {
            printf("Logging out...\n");
            clear_screen();
            break;
        }

        else
        {
            printf("Invalid choice\n");
            pause_screen();
        }
    }
}

int main() {
    int choice;
    char current_user[50];

    while(1)
    {
        printf("\n===== LAB SYSTEM =====\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            register_user();
        }

        else if(choice == 2)
        {
            if(login_user(current_user))
            {
                printf("Welcome %s\n",current_user);
                pause_screen();
                lab_menu(current_user);
            }
        }

        else if(choice == 3)
        {
            printf("Exiting...\n");
            return 0;
        }

        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}