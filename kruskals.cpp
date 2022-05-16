#include<bits/stdc++.h>
using namespace std;

//Structure for the edge 
struct Edge
{
    char vertex1;
    char vertex2;
    int weight;
    Edge(char v1,char v2,int w):vertex1(v1),vertex2(v2),weight(w) {}
};

//Graph structure
struct Graph{
    vector<char> vertices;
    vector<Edge> edges;
};

//Unordered map for parent and rank
unordered_map<char,char> Parent;
unordered_map<char,int> Rank; //To store the depth of the tree

//Find function
char Find(char vertex){
    if(Parent[vertex]==vertex){
        return Parent[vertex];
    }
    else{
        return Find(Parent[vertex]);
    }
}

//Union function

void Union(char root1,char root2){
    if(Rank[root1]>Rank[root2]){
        Parent[root2]=root1;
    }
    else if(Rank[root2]>Rank[root1]){
        Parent[root1]=root2;
    }
    else{
        Parent[root1]=root2;
        Rank[root2]++;
    }
}



//Make set function

void MakeSet(char vertex){
    Parent[vertex]=vertex;
    Rank[vertex]=0;
}

//Kruskal function
void Kruskal(Graph& g){
    vector<Edge> A; //To store edges included in the min spanning tree

    for(auto c:g.vertices){
        MakeSet(c);
    }

    //sorting the edges in ascending order
    sort(g.edges.begin(),g.edges.end(),[](Edge x,Edge y) {return x.weight < y.weight;});

    //Adding edges one by one to MST
    for(Edge e:g.edges){
        char root1=Find(e.vertex1);
        char root2=Find(e.vertex2);
        if(root1!=root2){
            A.push_back(e);
            Union(root1,root2);
        }
    }

    for(Edge e:A){
        cout<<e.vertex1<<"--"<<e.vertex2<<" "<<e.weight<<endl;
    }

}
int main(){
    char t[]={'a','b','c','d','e','f'};

    Graph g;
    g.vertices=vector<char>(t,t+sizeof(t)/sizeof(t[0]));

    g.edges.push_back(Edge('a','b',4));
    g.edges.push_back(Edge('a','f',2));
    g.edges.push_back(Edge('f','b',5));
    g.edges.push_back(Edge('c','b',6));
    g.edges.push_back(Edge('c','f',1));
    g.edges.push_back(Edge('f','e',4));
    g.edges.push_back(Edge('d','e',2));
    g.edges.push_back(Edge('d','c',3));

    Kruskal(g);
    return 0;
}
