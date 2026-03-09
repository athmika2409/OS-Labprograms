#include<stdio.h>

struct process{
    int pid,bt,at,pr,wt,tat,ct;
};

int main(){
    struct process p[10],temp;
    int n,i,j;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Priority: ");
        scanf("%d",&p[i].pr);

        p[i].pid=i+1;
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].pr > p[j].pr){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    int time=0;
    float avgwt=0,avgtat=0;

    for(i=0;i<n;i++){
        time+=p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }

    printf("\nPID\tPR\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].pr,p[i].wt,p[i].tat);
        avgwt+=p[i].wt;
        avgtat+=p[i].tat;
    }

    printf("\nAverage WT=%.2f",avgwt/n);
    printf("\nAverage TAT=%.2f",avgtat/n);
}
