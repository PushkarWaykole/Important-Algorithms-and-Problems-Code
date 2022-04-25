#include<stdio.h>

typedef struct Job{
    int id;
    int deadline;
    int profit;

}Job;

void sortByProfit(struct Job jobs[],int n){
    int i,j;
    Job temp;

    for(i=0;i<n;i++){
        for(j=0;j<(n-i-1);j++){
            if(jobs[j].profit<jobs[j+1].profit){
                temp=jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
            }

        }
    }
}

int maxDeadline(struct Job jobs[],int n){
    int max=jobs[0].deadline;
    for(int i=1;i<n;i++){
        if(max<jobs[i].deadline){
            max=jobs[i].deadline;
        }
    }
    return max;
}

void schedualJobs(struct Job jobs[],int n,int deadline){
    int ganttChart[deadline];
    for(int i=0;i<deadline;i++){
        ganttChart[i]=0;
    }
    Job currentJob;
    for(int i=0;i<deadline;i++){
        currentJob=jobs[i];
        int currentDeadline=jobs[i].deadline-1;
        int temp=currentDeadline;
        while(ganttChart[temp]!=0){
            temp--;
        }
        ganttChart[temp]=jobs[i].id;
    }
    printf("The gantt chart is : ");
    for(int i=0;i<deadline;i++){
        if(i==0){
            printf("| %d ",ganttChart[i]);
        }
        else if(i==deadline-1){
            printf("| %d |",ganttChart[i]);
        }
        else{

        printf("| %d ",ganttChart[i]);
        }
    }
}

int main(){
    int n;
    printf("Enter the number of jobs:");
    scanf("%d",&n);
    Job jobs[n];
    for(int i=0;i<n;i++){
        int d,p;
        printf("Enter the deadline of Job %d:",i+1);
        scanf("%d",&d);
        printf("Enter the profit of the Job %d:",i+1);
        scanf("%d",&p);

        jobs[i].deadline=d;
        jobs[i].profit=p;
        jobs[i].id=i+1;

    }

    sortByProfit(jobs,n);
    printf("The jobs after been sorted in decreasing order of their profit are:\n");
    for(int i=0;i<n;i++){
        printf("Job %d Deadline %d Profit %d\n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
    }
    int maxdeadline=maxDeadline(jobs,n);
    printf("The maximum deadline among the jobs is: %d ",maxdeadline);

    schedualJobs(jobs,n,maxdeadline);
    return 0;
}