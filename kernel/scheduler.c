#include <stdint.h>

#define MAX_TASKS 3
typedef void (*TaskFunction)(void);

TaskFunction tasks[MAX_TASKS];
uint8_t taskCount = 0;

void addTask(TaskFunction task) {
    if (taskCount < MAX_TASKS) {
        tasks[taskCount++] = task;
    }
}

void scheduleTasks() {
    while (1) {
        for (uint8_t i = 0; i < taskCount; i++) {
            tasks[i]();
        }
    }
}