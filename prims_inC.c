#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 9999999 

int minEdge(int key[],int included[],int V){
    int min=INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if(included[v]==0 && key[v]<min){
            min=key[v];
            min_index=v;
        }
    }
    return min_index;
}
void prims(int V,int graph[V][V]){

    //parent array to check whether cycle formation is taking place
    int parent[V];

    //key array to pick the min weighted edge
    int key[V];

    //To check whether all the vertices are included or not
    int included[V];

    for(int i=0;i<V;i++){
        //Setting the entire array with max value
        key[i]=INT_MAX; 

        //Marking all the vertices as unvisited
        included[i]=0;
    }

    key[0]=0; //selecting the 0 vertex as source vertex
    parent[0]=-1;  //Making the first node a the root of mst

    for(int i=0;i<V-1;i++){
        int u=minEdge(key,included,V);
        included[u]=1;

        for(int v=0;i<V;v++){
            if(graph[u][v]!=0 && included[v]==0 && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];

            }
        }
    }

    //printing the MST
    printf("The edges included in MST are \n");
    for(int i=1;i<V;i++){
        printf("%d -> %d weight: %d \n",parent[i],i,graph[i][parent[i]]);
    }

}
int main(){
    int V,E;
    printf("Enter the number of vertices:");
    scanf("%d",&V);
    int graph[V][V];

    //initailizing the adjacency matrix as all zeros
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            graph[i][j]=0;
        }
    }
    printf("Enter the number of edges ");
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        int s,d,w;
        printf("Enter the edge in the format 'source destionation weight' ");
        scanf("%d %d %d",&s,&d,&w);
        graph[s][d]=w;
        graph[d][s]=w;

    }
    printf("\nThe adjacency matrix is:\n ");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    prims(V,graph);

    return 0;
}