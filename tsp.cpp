#include <bits/stdc++.h>
using namespace std;
 
int TSP(vector<vector<int>> &graph, int s)
{
    vector<int> vertex;
    for (int i = 0; i < graph.size(); i++){
        if (i != s){
            vertex.push_back(i);
        }
    }
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}

void addEdge(vector<vector<int>>& adjMatrix, int u, int v,int w) {
adjMatrix[u][v] = w;
adjMatrix[v][u] =w ; 
}

int main(){
int numver;
cout<<"Enter the number of vertices:- ";
cin>>numver;
vector<vector<int>>adjMatrix(numver,vector<int>(numver,0));
int numedge;
cout<<"Enter the number of edge:- ";
cin>>numedge;
for(int i=0;i<numedge;i++){
    int u,v,w;
    cout<<"Enter edge and weight"<<i+1<<"(u,v,w):- ";
    cin>>u>>v>>w;
    addEdge(adjMatrix,u,v,w);
}
cout<<"Graph is :- "<<endl;
for(int i=0;i<numver;i++){
    for(int j=0;j<numver;j++){
        cout<<adjMatrix[i][j]<<" ";
    }
    cout<<"\n";
}
cout<<"Shortest Path is :- "<<TSP(adjMatrix,0)<<endl;
    return 0;
}