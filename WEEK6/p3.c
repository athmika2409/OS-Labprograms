#include <stdio.h>

struct Task {
    int id, execution, period;
    float share;
};

int main() {
    int n, i;
    struct Task t[10];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        t[i].id = i + 1;
        printf("Enter execution time and period for Task %d: ", i+1);
        scanf("%d %d", &t[i].execution, &t[i].period);

        t[i].share = (float)t[i].execution / t[i].period;
    }

    printf("\nProportional Scheduling:\n");
    for(i = 0; i < n; i++) {
        printf("Task %d gets %.2f CPU share\n", t[i].id, t[i].share);
    }

    return 0;
}
