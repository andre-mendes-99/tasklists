#include "tasks.h"
#include <stdlib.h>
#include <string.h>

struct Task_ {
    char* id;
    char* description;
    char* status;
};

Task task_new(const char* id, const char* description) {
    Task task = malloc(sizeof(struct Task_));
    task->id = strdup(id);
    task->description = strdup(description);
    task->status = strdup("Por completar");
    return task;
}

void task_destroy(const Task task) {
    free(task->id);
    free(task->description);
    free(task->status);
    free(task);
}

char* task_get_id(const Task task) {
    return task->id;
}

char* task_get_description(const Task task) {
    return task->description;
}

char* task_get_status(const Task task){
    return task->status;
}

void task_set_completed(const Task task) {
    free(task->status);
    task->status = strdup("Completada");
}
