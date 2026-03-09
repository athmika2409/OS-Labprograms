#include<stdio.h>

int main(){
    int bt[10],at[10],rt[10],ct[10],tat[10],wt[10];
    int n,i,time=0,remain,smallest;
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        rt[i]=bt[i];

    remain=n;

    }
    while(remain!=0){
        smallest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1){
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0){
            remain--;
            ct[smallest]=time;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage WT=%.2f",avgwt/n);
    printf("\nAverage TAT=%.2f",avgtat/n);
}
