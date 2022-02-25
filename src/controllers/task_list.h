#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "../models/tasks.h"

typedef struct TaskList_ *TaskList;

TaskList task_list_new();
void task_list_destroy(TaskList task_list);
char* task_list_add_task(const TaskList task_list, const char* description);
void task_list_complete_task(const TaskList task_list, const char* id);
int task_list_get_num_tasks(const TaskList task_list);
Task* task_list_get_tasks(const TaskList task_list);

#endif
