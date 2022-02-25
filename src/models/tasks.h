#ifndef TASKS_H
#define TASKS_H

typedef struct Task_ *Task;

Task task_new(const char* id, const char* description);
void task_destroy(const Task task);
char* task_get_id(const Task task);
char* task_get_description(const Task task);
char* task_get_status(const Task task);
void task_set_completed(const Task task);

#endif
