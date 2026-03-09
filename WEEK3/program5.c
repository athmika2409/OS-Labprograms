#include<stdio.h>

int main(){
    int bt[10],at[10],pr[10],rt[10];
    int wt[10],tat[10],ct[10];
    int n,time=0,remain,highest,i;

    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        rt[i]=bt[i];
    }

    remain=n;

    while(remain!=0){
        highest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(highest==-1 || pr[i]<pr[highest])
                    highest=i;
            }
        }

        if(highest==-1){
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest]==0){
            remain--;
            ct[highest]=time;
            tat[highest]=ct[highest]-at[highest];
            wt[highest]=tat[highest]-bt[highest];
        }
    }

    printf("\nPID\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\n",i+1,wt[i],tat[i]);
        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage WT=%.2f",avgwt/n);
    printf("\nAverage TAT=%.2f",avgtat/n);
}
