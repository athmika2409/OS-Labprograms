#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Enter no of resources: ");
    scanf("%d", &m);

    int alloc[n][m], req[n][m], avail[m], work[m];
    int finish[n], seq[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nP%d Allocation: ", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

        printf("P%d Request: ", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &req[i][j]);
    }

    printf("\nAvailable Resources: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        finish[i] = 0;

        for (int j = 0; j < m; j++)
            sum += alloc[i][j];

        if (sum == 0)
            finish[i] = 1;
    }

    int k = 0, found;

    do
    {
        found = 0;

        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                int flag = 1;

                for (int j = 0; j < m; j++)
                {
                    if (req[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if (flag)
                {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    finish[i] = 1;
                    seq[k++] = i;
                    found = 1;

                    printf("P%d visited\n", i);
                }
            }
        }

    } while (found);

    int deadlock = 0;

    for (int i = 0; i < n; i++)
    {
        if (!finish[i])
        {
            deadlock = 1;
            break;
        }
    }

    if (deadlock)
    {
        printf("\nSystem is in Deadlock\n");

        printf("Deadlocked Processes: ");
        for (int i = 0; i < n; i++)
            if (!finish[i])
                printf("P%d ", i);
    }
    else
    {
        printf("\nSystem is not in Deadlock\n");

        printf("Sequence: ");
        for (int i = 0; i < k; i++)
            printf("P%d ", seq[i]);
    }

    return 0;
}
