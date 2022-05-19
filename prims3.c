#include <stdio.h>    
#include <limits.h>    
// #define V 5  /*Define the number of V in the g*/  
int V;
/* create minimum_key() method for finding the vertex that has minimum key-value and that is not added in MST yet */   
int minimum_key(int k[], int mst[],int V)    
{  
    int minimum  = INT_MAX, min,i;    
      
    /*iterate over all V to find the vertex with minimum key-value*/  
    for (i = 0; i < V; i++)  
        if (mst[i] == 0 && k[i] < minimum )   
            minimum = k[i], min = i;    
    return min;    
}    
/* create prim() method for constructing and printing the MST.  
The g[V][V] is an adjacency matrix that defines the g for MST.*/  
void prim(int g[][V],int V)    
{    
    /* create array of size equal to total number of V for storing the MST*/  
    int parent[V];    
    /* create k[V] array for selecting an edge having minimum weight*/  
    int k[V];       
    int mst[V];      
    int i, count,edge,v; /*Here 'v' is the vertex*/  
    for (i = 0; i < V; i++)  
    {  
        k[i] = INT_MAX;  
        mst[i] = 0;    
    }  
    k[0] = 0; /*It select as first vertex*/  
    parent[0] = -1;   /* set first value of parent[] array to -1 to make it root of MST*/  
    for (count = 0; count < V-1; count++)    
    {    
        /*select the vertex having minimum key and that is not added in the MST yet from the set of V*/  
        edge = minimum_key(k, mst,V);    
        mst[edge] = 1;    
        for (v = 0; v < V; v++)    
        {  
            if (g[edge][v] && mst[v] == 0 && g[edge][v] <  k[v])    
            {  
                parent[v]  = edge, k[v] = g[edge][v];    
            }  
        }  
     }    
     /*Print the constructed Minimum spanning tree*/  
     printf("\n Edge \t  Weight\n");  
     for (i = 1; i < V; i++)    
     printf(" %d <-> %d    %d \n", parent[i], i, g[i][parent[i]]);    
      
}    
int main()    
{    
    int E;
    printf("Enter the number of V:");
    scanf("%d",&V);

    int g[V][V];
    
    //initailizing the adjacency matrix as all zeros
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            g[i][j]=0;
        }
    }
    printf("Enter the number of edges ");
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        int s,d,w;
        printf("Enter the edge in the format 'source destionation weight' ");
        scanf("%d %d %d",&s,&d,&w);
        g[s][d]=w;
        g[d][s]=w;

    }
    printf("\nThe adjacency matrix is:\n ");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }

    // int g[V][V] = {{0, 0, 3, 0, 0},    
    //                             {0, 0, 10, 4, 0},    
    //                             {3, 10, 0, 2, 6},    
    //                             {0, 4, 2, 0, 1},    
    //                             {0, 0, 6, 1, 0},    
    //                             };   
    prim(g,V);    
    return 0;  
}  