#include<stdio.h>

typedef struct activity{
    int id;
    int start;
    int finish;
}activity;


void selectActivities(struct activity activities[],int n){
    activity selected[n];
    selected[0]=activities[0];
    int count=1;
    activity curr;
    for(int i=1;i<n;i++){
        curr=activities[i];
        printf("Current selected activity %d\n",i);
        if(curr.start >= selected[count-1].finish){
            selected[count]=curr;
            printf("Activity %d selected now count is: %d\n",curr.id,count);
            count++;
        }
        else{
            printf("Activity %d is not selected now count is: %d\n",i,count);
        }
    }
    printf("The selected activities are:\t");
    for(int i=0;i<count;i++){
        printf("%d ",selected[i].id);
    }
}
void sortByFinish(struct activity activities[],int n){
    int i,j;
    activity temp;

    for(i=0;i<n;i++){
        for(j=0;j<(n-i-1);j++){
            if(activities[j].finish>activities[j+1].finish){
                temp=activities[j];
                activities[j]=activities[j+1];
                activities[j+1]=temp;
            }

        }
    }

}
int main(){


    

    int n_activities;
    printf("Enter the number of activities:");
    scanf("%d",&n_activities);

    activity activities[n_activities];

    for(int i=0;i<n_activities;i++){
        int s,f;
        printf("Enter the start and finish time for activity %d :",i+1);
        scanf("%d %d",&s,&f);
        activities[i].start = s;
        activities[i].finish = f;
        activities[i].id=i+1;
    }

    for(int i=0;i<n_activities;i++){
        printf("Activity %d start %d finish %d",activities[i].id,activities[i].start,activities[i].finish);
    }

    sortByFinish(activities,n_activities);
    printf("After sorting activities according to the finish time:\n");
    for(int i=0;i<n_activities;i++){
        printf("Activity %d start   %d finish %d\n",activities[i].id,activities[i].start,activities[i].finish);
    }

    selectActivities(activities,n_activities);
    return 0;
}