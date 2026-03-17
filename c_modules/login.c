#include <stdio.h>
#include <string.h>
#include "../modules/login.h"

int register_user() {
    char username[50], password[50];
    char file_user[50], file_pass[50];

    FILE *fp = fopen("data/users.txt", "a+");
    if (fp == NULL) {
        printf("Error opening users file.\n");
        return 0;
    }

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    rewind(fp);

    while (fscanf(fp, "%49[^,],%49s\n", file_user, file_pass) == 2) {
        if (strcmp(username, file_user) == 0) {
            printf("Username already exists!\n");
            fclose(fp);
            return 0;
        }
    }

    fprintf(fp, "%s,%s\n", username, password);
    fclose(fp);

    printf("Registration successful.\n");
    return 1;
}

int login_user(char logged_in_user[]) {
    char username[50], password[50];
    char file_user[50], file_pass[50];

    FILE *fp = fopen("data/users.txt", "r");
    if (fp == NULL) {
        printf("Error opening users file.\n");
        return 0;
    }

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    while (fscanf(fp, "%49[^,],%49s\n", file_user, file_pass) == 2) {
        if (strcmp(username, file_user) == 0 && strcmp(password, file_pass) == 0) {
            strcpy(logged_in_user, username);
            fclose(fp);
            printf("Login successful.\n");
            return 1;
        }
    }

    fclose(fp);
    printf("Invalid credentials.\n");
    return 0;
}