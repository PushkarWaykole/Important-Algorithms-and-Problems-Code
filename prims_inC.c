#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 9999999 
#define V 5
// int minEdge(int key[],int included[],int V){
//     int min=INT_MAX,min_index;
//     for(int v=0;v<V;v++){
//         if(included[v]==0 && key[v]<min){
//             min=key[v];
//             min_index=v;
//         }
//     }
//     return min_index;
// }
int minimum_key(int k[], int mst[])    
{  
    int minimum  = INT_MAX, min,i;    
      
    /*iterate over all vertices to find the vertex with minimum key-value*/  
    for (i = 0; i < V; i++)  
        if (mst[i] == 0 && k[i] < minimum )   
            minimum = k[i], min = i;    
    return min;    
} 

void prims(int graph[V][V]){

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
        int edge=minimum_key(key,included);
        included[edge]=1;

        for(int v=0;i<V;v++){
            if(graph[edge][v]!=0 && included[v]==0 && graph[edge][v]<key[v]){
                parent[v]=edge;
                key[v]=graph[edge][v];

            }
        }
    }

    //printing the MST
    // printf("The edges included in MST are \n");
    // for(int i=1;i<V;i++){
    //     printf("%d -> %d weight: %d \n",parent[i],i,graph[i][parent[i]]);
    // }
    printf("\n Edge \t  Weight\n");  
     for (int i = 1; i < V; i++)    
     printf(" %d <-> %d    %d \n", parent[i], i, graph[i][parent[i]]);

}
int main(){
    // int V,E;
    // printf("Enter the number of vertices:");
    // scanf("%d",&V);
    // int graph[V][V];
    
    // //initailizing the adjacency matrix as all zeros
    // for(int i=0;i<V;i++){
    //     for(int j=0;j<V;j++){
    //         graph[i][j]=0;
    //     }
    // }
    // printf("Enter the number of edges ");
    // scanf("%d",&E);
    // for(int i=0;i<E;i++){
    //     int s,d,w;
    //     printf("Enter the edge in the format 'source destionation weight' ");
    //     scanf("%d %d %d",&s,&d,&w);
    //     graph[s][d]=w;
    //     graph[d][s]=w;

    // }
    // printf("\nThe adjacency matrix is:\n ");
    // for(int i=0;i<V;i++){
    //     for(int j=0;j<V;j++){
    //         printf("%d ",graph[i][j]);
    //     }
    //     printf("\n");
    // }
   
    int graph[V][V] = {{0, 0, 3, 0, 0},    
                                {0, 0, 10, 4, 0},    
                                {3, 10, 0, 2, 6},    
                                {0, 4, 2, 0, 1},    
                                {0, 0, 6, 1, 0},    
                                };  
    prims(graph);

    return 0;
}