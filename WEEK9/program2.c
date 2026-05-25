#include <stdio.h>

int search(int key, int frame[], int f) {
    for (int i = 0; i < f; i++) {
        if (frame[i] == key)
            return 1;
    }
    return 0;
}

void fifo(int pages[], int n, int f) {
    int frame[f];
    int index = 0, faults = 0;

    for (int i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nFIFO Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {

        if (!search(pages[i], frame, f)) {

            frame[index] = pages[i];
            index = (index + 1) % f;
            faults++;

            printf("PF No. %d: ", faults);

            for (int j = 0; j < f; j++) {
                if (frame[j] != -1)
                    printf("%d ", frame[j]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    printf("FIFO Page Faults: %d\n", faults);
}

void lru(int pages[], int n, int f) {
    int frame[f], time[f];
    int faults = 0, count = 0;

    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {

        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if (!found) {

            int pos = 0;

            for (int j = 1; j < f; j++) {
                if (time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;

            printf("PF No. %d: ", faults);

            for (int j = 0; j < f; j++) {
                if (frame[j] != -1)
                    printf("%d ", frame[j]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    printf("LRU Page Faults: %d\n", faults);
}

void optimal(int pages[], int n, int f) {
    int frame[f];
    int faults = 0;

    for (int i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nOptimal Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {

        if (!search(pages[i], frame, f)) {

            int pos = -1, farthest = i + 1;

            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {

                int max = -1;

                for (int j = 0; j < f; j++) {

                    int k;

                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k])
                            break;
                    }

                    if (k > max) {
                        max = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
            faults++;

            printf("PF No. %d: ", faults);

            for (int j = 0; j < f; j++) {
                if (frame[j] != -1)
                    printf("%d ", frame[j]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    printf("Optimal Page Faults: %d\n", faults);
}

int main() {

    int f, n;

    printf("Enter the number of Frames: ");
    scanf("%d", &f);

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the reference string: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    fifo(pages, n, f);
    lru(pages, n, f);
    optimal(pages, n, f);

    return 0;
}
