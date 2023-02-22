#include "unity.h"
#include "../models/tasks.h"

void setUp() {
}

void tearDown() {
}

void test_task_new() {
    // Quando se cria uma tarefa, esta não vai ser NULL.
    Task task = task_new("1", "description");
    TEST_ASSERT_NOT_NULL(task);
    task_destroy(task);
}

void test_task_get_id() {
    // Quando se cria uma tarefa, o seu ID deve ser o mesmo que foi passado.
    Task task = task_new("1", "description");
    TEST_ASSERT_EQUAL_STRING("1", task_get_id(task));
    task_destroy(task);
    task = task_new("TESTE", "description");
    TEST_ASSERT_EQUAL_STRING("TESTE", task_get_id(task));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_task_new);
    RUN_TEST(test_task_get_id);
    return UNITY_END();
}
