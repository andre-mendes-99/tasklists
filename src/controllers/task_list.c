#include "task_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_TASKS 10

struct TaskList_ {
    Task tasks[MAX_TASKS];
    int num_tasks;
};

TaskList task_list_new() {
    TaskList task_list = malloc(sizeof(struct TaskList_));
    task_list->num_tasks = 0;
    for(int i=0; i<MAX_TASKS; i++) {
        task_list->tasks[i] = NULL;
    }
    return task_list;
}

void task_list_destroy(const TaskList task_list) {
    int i;
    for (i = 0; i < task_list->num_tasks; i++) {
        task_destroy(task_list->tasks[i]);
    }
    free(task_list);
}

char* _generate_id(const TaskList task_list) {
    char* id = malloc(sizeof(char) * 10);
    sprintf(id, "%d", task_list->num_tasks);
    return id;
}

char* task_list_add_task(const TaskList task_list, const char* description) {
    char* id = _generate_id(task_list);
    Task task = task_new(id, description);
    task_list->tasks[task_list->num_tasks] = task;
    task_list->num_tasks++;
    return id;
}

void task_list_remove_task(const TaskList task_list, const char* id) {
    for (int i = 0; i < task_list->num_tasks; i++) {
        char* task_id = task_get_id(task_list->tasks[i]);
        if (strcmp(task_id, id) == 0) {
            task_destroy(task_list->tasks[i]);
            task_list->num_tasks--;
            break;
        }
    }
}

void task_list_complete_task(const TaskList task_list, const char* id) {
    for (int i = 0; i < task_list->num_tasks; i++) {
        char* task_id = task_get_id(task_list->tasks[i]);
        if (strcmp(task_id, id) == 0) {
            task_set_completed(task_list->tasks[i]);
            break;
        }
    }
}

int task_list_get_num_tasks(const TaskList task_list) {
    return task_list->num_tasks;
}

Task* task_list_get_tasks(const TaskList task_list) {
    return task_list->tasks;
}
