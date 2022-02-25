#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cli.h"
#include "../controllers/task_list.h"
#include "../models/tasks.h"

void run_cli() {
    char line[120];
    char* command;
    char* id;
    char* description;
    TaskList task_list = task_list_new();
    while(1) {
        fgets(line, 120, stdin);

        command = strtok(line, " \n");

        if (strcmp(command, "Q") == 0) {
            task_list_destroy(task_list);
            break;
        }
        else if(strcmp(command, "RT") == 0) {
            description = strtok(NULL, "\n");
            id = task_list_add_task(task_list, description);
            printf("Tarefa criada com identificador %s.\n", id);
        }
        else if(strcmp(command, "LT") == 0) {
            Task* tasks = task_list_get_tasks(task_list);
            int num_tasks = task_list_get_num_tasks(task_list);
            for(int i=0; i<num_tasks; i++) {
                Task task = tasks[i];
                if(task != NULL) {
                    printf("%s %s %s\n", task_get_id(task), task_get_description(task), task_get_status(task));
                }
            }
        }
        else if(strcmp(command, "MT") == 0) {
            id = strtok(NULL, "\n");
            task_list_complete_task(task_list, id);
            printf("Tarefa %s marcada como completada.\n", id);
        }
    }
}
