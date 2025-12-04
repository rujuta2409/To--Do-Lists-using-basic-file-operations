#include <stdio.h>

void addTask() {
    FILE *fp = fopen("todo.txt", "a+");  
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char task[256];

    printf("Enter your task: ");
    scanf(" %255[^\n]", task);  

    fprintf(fp, "%s\n", task);
    fclose(fp);

    printf("Task added successfully.\n");
}

void viewTasks() {
    FILE *fp = fopen("todo.txt", "r");  
    if (fp == NULL) {
        printf("No tasks found. File does not exist yet.\n");
        return;
    }

    char task[256];

    printf("\n--- Your To-Do List ---\n");


    while (fscanf(fp, " %255[^\n]", task) == 1) {
        printf("- %s\n", task);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SIMPLE TO-DO LIST =====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
