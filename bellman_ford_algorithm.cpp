#include<bits/stdc++.h>
using namespace std;

int main(){
    int N = 6;
    // Graph 
    // {u-->v , wt}   
    vector<vector<int>> graph = {{0,1,5}, {1,5,-3}, {1,2,-2}, {5,3,1}, {3,2,6}, {2,4,3}, {3,4,-2}};
    vector<int> dist(N, 1e8);
    dist[0] = 0;
    bool ans = true;
    // Do N-1 iteration of relaxation of graph for each node
    for(int i = 0; i < N-1; i++){
        for(auto it: graph){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    
    // Check for negative cycle
    for(auto it: graph){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v])
            ans = false;
    }
    if(ans){
        for(int it: dist)
            cout<<it<<" ";
    }
    else 
        cout<<"Negative Cycle Detected!";
    return 0;
}