#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter number of processes -- ");
    scanf("%d", &n);

    printf("Enter number of resources -- ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m];
    int finish[n], safe[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for P%d\n", i);

        printf("Enter allocation -- ");
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }

        printf("Enter Max -- ");
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter Available Resources -- ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int pid;
    int request[m];

    printf("\nEnter New Request Details --\n");

    printf("Enter pid -- ");
    scanf("%d", &pid);

    printf("Enter Request for Resources -- ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &request[i]);
    }

    int possible = 1;

    for (int i = 0; i < m; i++)
    {
        if (request[i] > need[pid][i] || request[i] > avail[i])
        {
            possible = 0;
            break;
        }
    }

    if (!possible)
    {
        printf("\nRequest cannot be granted.\n");
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        avail[i] -= request[i];
        alloc[pid][i] += request[i];
        need[pid][i] -= request[i];
    }

    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    while (count < n)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 1;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if (flag)
                {
                    for (int j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    printf("\nP%d is visited(", i);

                    for (int j = 0; j < m; j++)
                    {
                        printf("%d", avail[j]);

                        if (j != m - 1)
                            printf(" ");
                    }

                    printf(")");

                    safe[count] = i;
                    count++;

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            printf("\nSYSTEM IS NOT SAFE STATE\n");
            return 0;
        }
    }

    printf("\n\nSYSTEM IS IN SAFE STATE\n");

    printf("The Safe Sequence is -- (");

    for (int i = 0; i < n; i++)
    {
        printf("P%d", safe[i]);

        if (i != n - 1)
            printf(" ");
    }

    printf(")\n");

    return 0;
}
