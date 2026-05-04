#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int Ci;
    int Ti;
    int Di;
    int remaining;
    int next_release;
} Task;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    Task t[MAX];
    int hyperperiod = 1;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nTask %d\n", i + 1);
        t[i].id = i + 1;

        printf("Execution Time (Ci): ");
        scanf("%d", &t[i].Ci);

        printf("Period (Ti): ");
        scanf("%d", &t[i].Ti);

        printf("Deadline (Di): ");
        scanf("%d", &t[i].Di);

        t[i].remaining = 0;
        t[i].next_release = 0;

        hyperperiod = lcm(hyperperiod, t[i].Ti);
    }

    printf("\nHyperperiod (LCM) = %d\n\n", hyperperiod);

    for (int time = 0; time < hyperperiod; time++) {

        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                t[i].remaining += t[i].Ci;
                t[i].next_release += t[i].Ti;
            }
        }

        int selected = -1;
        int min_deadline = 1e9;

        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                if (t[i].Di < min_deadline) {
                    min_deadline = t[i].Di;
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            printf("Time %d: Idle\n", time);
        } else {
            printf("Time %d: Task %d running (Deadline=%d)\n",
                   time, t[selected].id, t[selected].Di);

            t[selected].remaining--;
        }
    }

    return 0;
}

