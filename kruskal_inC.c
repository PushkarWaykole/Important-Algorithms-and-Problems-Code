#include<stdio.h>


typedef struct edge{
    int source;
    int destination;
    int weight;
}edge;

void sortByWeight(struct edge input[],int E){
    int i,j;
    edge temp;
    for(i=0;i<E-1;i++){
        for(j=0;j<(E-i-1);j++){
            if(input[j].weight > input[j+1].weight){
                temp=input[j];
                input[j]=input[j+1];
                input[j+1]=temp;
            }
        }
    }
}


int findParent(int v,int parent[]){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v],parent);
}

void kruskals(struct edge input[],int n,int E){

    //Sort the input array in ascending order based on weights 
    sortByWeight(input,E);

    //Creating an output array of size E-1
    edge output[n-1];
    
    //parent array to check for loop in mst after adding the edge
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int count=0; //To store the count of edges added in mst
    int i=0; //To check the current edge

    //check till the count is not n-1
    //that is till n=all the vertices are not included
    while(count!=n-1){
        edge currentEdge=input[i];

        //check if we can add the current edge in mst or not
        int sourceParent=findParent(currentEdge.source,parent);
        int destinationParent=findParent(currentEdge.destination,parent);

        //if the parent of source and dest are diff then we can add the edge otherwise not

        if(sourceParent!=destinationParent){
            output[count]=currentEdge;
            count++;
            //changing the parent of source vertex to destination 
            parent[sourceParent]=destinationParent;
        }
        i++;

    }

    //printing the mst
    printf("The edges included in the MST are \n");
    for(int i=0;i<n-1;i++){

        
        printf("%d  -> %d -> %d\n",output[i].source,output[i].destination,output[i].weight);
    }
    int sum=0;
    for (int i = 0; i < n-1; i++)
    {
        
        sum+=output[i].weight;
    }
    
    printf("The cost of the MST is %d \n",sum);
}
int main(){
    int n,E;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the number of Edges:");
    scanf("%d",&E);
    edge input[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        printf("Enter edge in format source destination weight ");
        scanf("%d %d %d",&s,&d,&w);
        input[i].source=s;
        input[i].destination=d;
        input[i].weight=w;
    }
    
    kruskals(input,n,E);
    
    return 0;
}