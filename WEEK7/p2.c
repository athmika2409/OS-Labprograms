#include <stdio.h>

#define MAX 10

int n;
int hungry;
int pos[MAX];

int canEat(int p, int eating[]) {
    int left = (p + n - 1) % n;
    int right = (p + 1) % n;

    if (eating[left] == 0 && eating[right] == 0)
        return 1;
    return 0;
}

void oneAtATime() {
    int eating[MAX] = {0};

    printf("Allow one philosopher to eat at any time\n");

    for (int i = 0; i < hungry; i++) {
        int p = pos[i];

        for (int j = 0; j < hungry; j++) {
            printf("P %d is waiting\n", pos[j]);
        }

        if (canEat(p, eating)) {
            eating[p] = 1;
            printf("P %d is granted to eat\n", p);
            printf("P %d has finished eating\n", p);
            eating[p] = 0;
        }
    }
}
void twoAtATime() {
    int eating[MAX] = {0};

    printf("Allow two philosophers to eat at any time\n");

    for (int i = 0; i < hungry; i++) {
        int p = pos[i];

        if (canEat(p, eating)) {
            eating[p] = 1;
            printf("P %d is granted to eat\n", p);
        } else {
            printf("P %d is waiting\n", p);
        }
    }

    for (int i = 0; i < hungry; i++) {
        int p = pos[i];
        if (eating[p]) {
            printf("P %d has finished eating\n", p);
            eating[p] = 0;
        }
    }
}

int main() {
    int choice;

    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &hungry);

    for (int i = 0; i < hungry; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, n);
        scanf("%d", &pos[i]);
        pos[i]--;
    }

    while (1) {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                oneAtATime();
                break;
            case 2:
                twoAtATime();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
