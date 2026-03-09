#include<stdio.h>

struct process{
    int pid, bt, at, wt, tat, ct;
};

int main(){
    struct process p[10], temp;
    int n,i,j;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Process %d Arrival Time: ",i+1);
        scanf("%d",&p[i].at);
        printf("Process %d Burst Time: ",i+1);
        scanf("%d",&p[i].bt);
        p[i].pid=i+1;
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].bt > p[j].bt){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    int time=0;
    for(i=0;i<n;i++){
        time += p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }

    float avgwt=0,avgtat=0;

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tat);
        avgwt+=p[i].wt;
        avgtat+=p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
}
