#include <stdio.h>
#include <math.h>

#define MAX 10

struct Task {
    int id;
    int Ci;
    int Ti;
    int remaining;
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void sortTasks(struct Task tasks[], int n) {
    struct Task temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].Ti > tasks[j].Ti) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    int n, time;
    int hyperperiod = 1;
    float U = 0.0, bound;

    struct Task tasks[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Maximum %d tasks allowed.\n", MAX);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;

        printf("\nTask %d\n", i + 1);

        printf("Enter Execution Time (Ci): ");
        scanf("%d", &tasks[i].Ci);

        printf("Enter Period (Ti): ");
        scanf("%d", &tasks[i].Ti);

        tasks[i].remaining = 0;

        U += (float)tasks[i].Ci / tasks[i].Ti;
    }

    printf("\nCPU Utilization = %.4f\n", U);

    bound = n * (pow(2.0, 1.0 / n) - 1);
    printf("RMS Utilization Bound = %.4f\n", bound);

    if (U <= bound)
        printf("System is Schedulable using RMS\n");
    else
        printf("System is NOT Guaranteed Schedulable using RMS\n");

    sortTasks(tasks, n);

    printf("\nPriority Order:\n");
    for (int i = 0; i < n; i++) {
        printf("Priority %d -> Task %d (Period = %d)\n",
               i + 1, tasks[i].id, tasks[i].Ti);
    }

    hyperperiod = tasks[0].Ti;
    for (int i = 1; i < n; i++) {
        hyperperiod = lcm(hyperperiod, tasks[i].Ti);
    }

    printf("\nHyperperiod = %d\n", hyperperiod);

    printf("\nScheduling Timeline:\n");

    for (time = 0; time < hyperperiod; time++) {

        for (int i = 0; i < n; i++) {
            if (time % tasks[i].Ti == 0) {
                tasks[i].remaining = tasks[i].Ci;
            }
        }

        int selected = -1;

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                selected = i;
                break;
            }
        }

        if (selected != -1) {
            printf("Time %2d -> Task %d\n", time, tasks[selected].id);
            tasks[selected].remaining--;
        } else {
            printf("Time %2d -> Idle\n", time);
        }
    }

    return 0;
}
